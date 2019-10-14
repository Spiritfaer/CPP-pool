#include <stdexcept>
#include <vector>
#include <new>
#include "SDLDisplay.hpp"
#include "ZazModule.hpp"

SDLDisplay::SDLDisplay() { init(); _cat = false; }
SDLDisplay::SDLDisplay(bool children) { static_cast<void>(children); }
SDLDisplay::~SDLDisplay() {}

SDL_Window		*SDLDisplay::_window = NULL;
SDL_Renderer	*SDLDisplay::_render = NULL;
SDL_Texture		*SDLDisplay::_texture = NULL;
SDL_Surface		*SDLDisplay::_surface = NULL;
TTF_Font		*SDLDisplay::_fontBig = NULL;
unsigned int	SDLDisplay::_fontSizeBig = 25;
TTF_Font		*SDLDisplay::_fontSmall = NULL;
unsigned int	SDLDisplay::_fontSizeSmall = 20;
SDL_Color		SDLDisplay::_white = { .r = 250, .g = 255, .b = 255, .a = 0 };

SDL_Window		*SDLDisplay::getWindow() const { return _window; }
SDL_Renderer	*SDLDisplay::getRender() const { return _render; }
SDL_Texture		*SDLDisplay::getTexture() const { return _texture; }
SDL_Surface		*SDLDisplay::getSurface() const { return _surface; }
TTF_Font		*SDLDisplay::getFont() const { return _fontBig; }
unsigned int	SDLDisplay::getFontSize() const { return _fontSizeBig; }

void SDLDisplay::init() {
	if ((SDL_Init(SDL_INIT_EVERYTHING) < 0))
		throw std::logic_error("SDL_Init");
	if (TTF_Init() == -1)
		throw std::logic_error("TTF_Init");
	_window = SDL_CreateWindow("FT GKRELLM",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			WINDOW_W, WINDOW_H, SDL_WINDOW_SHOWN);
	if (!_window)
		throw std::bad_alloc();
	_render = SDL_CreateRenderer(_window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!_render)
		throw std::bad_alloc();
	_texture = SDL_CreateTexture(_render, SDL_PIXELFORMAT_ABGR8888,
			SDL_TEXTUREACCESS_TARGET, WINDOW_W, WINDOW_H);
	if (!_texture)
		throw std::bad_alloc();
	SDL_SetTextureBlendMode(_texture, SDL_BLENDMODE_BLEND);
	_surface = SDL_CreateRGBSurface(0, WINDOW_W, WINDOW_H, 32, 0, 0, 0, 0);
	if (!_surface)
		throw std::bad_alloc();
	_fontBig = TTF_OpenFont(FONT_BOLD, SDLDisplay::_fontSizeBig);
	_fontSmall = TTF_OpenFont(FONT_REGULAR, SDLDisplay::_fontSizeSmall);
	if (!_fontBig || !_fontSmall)
		throw std::bad_alloc();
	SDL_SetWindowOpacity(_window, 0.80);
	int32_t img_flags = IMG_INIT_PNG | IMG_INIT_JPG;
	int32_t img_getFlags = IMG_Init(img_flags);
	if (img_flags != img_getFlags)
		throw std::bad_alloc();
}

void SDLDisplay::loop(const std::vector<IMonitorModule *> &modules) {
	SDL_Event event;
	bool loop = true;
	unsigned int lastTime = 0, currentTime;
	ZazModule	cat;
	windowsClear();
	windowsPresent();

	bool test = true;
	while (loop) {
		loop = eventGuard(event);
		currentTime = SDL_GetTicks();
		if (test) {
			windowsClear();
			for (unsigned int i = 0; i < modules.size(); ++i) {
				modules[i]->drawSDL();
				if (_cat)
					cat.drawSDL();
			}
			windowsPresent();
			test = false;
		}


		if (currentTime > lastTime + 1000) {
			for (unsigned int i = 0; i < modules.size() && loop; ++i) {
				loop = eventGuard(event);
				modules[i]->refreshInfo();
			}
			lastTime = currentTime;
			test = true;
		}
	}
}

bool SDLDisplay::eventGuard(SDL_Event &ev) {
	SDL_PollEvent(&ev);
	if (ev.type == SDL_QUIT)
		return false;
	if (ev.key.type == SDL_KEYDOWN
		&& ev.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		return false;
	if (ev.key.type == SDL_KEYDOWN
		&& ev.key.keysym.scancode == SDL_SCANCODE_SPACE)
		_cat = !_cat;
	return true;
}

void SDLDisplay::end() {
	if (_fontBig)
		TTF_CloseFont(_fontBig);
	if (_fontSmall)
		TTF_CloseFont(_fontSmall);
	if (_surface)
		SDL_FreeSurface(_surface);
	if (_texture)
		SDL_DestroyTexture(_texture);
	if (_render)
		SDL_DestroyRenderer(_render);
	if (_window)
		SDL_DestroyWindow(_window);
	TTF_Quit();
	SDL_Quit();
}

void SDLDisplay::windowsPresent() {
	SDL_UpdateTexture(_texture, NULL, _surface->pixels, (uint32_t)WINDOW_W << 2u);
	SDL_RenderCopy(_render, _texture, NULL, NULL);
	SDL_RenderPresent(_render);
}

void SDLDisplay::windowsClear() {
	SDL_SetRenderDrawColor(_render, 45, 47, 50, 0);
	SDL_RenderClear(_render);
	SDL_FillRect(_surface, NULL, 0x000000);

}

void SDLDisplay::drawString(const char *str, SDL_Color const &color, SDL_Rect &pos, bool big) {
	static SDL_Surface *text_surf;
	if (big)
		text_surf = TTF_RenderText_Blended(_fontBig, str, color);
	else
		text_surf = TTF_RenderText_Blended(_fontSmall, str, color);
	SDL_BlitSurface(text_surf, NULL, _surface, &pos);

	SDL_FreeSurface(text_surf);
	text_surf = NULL;
}

void SDLDisplay::setPos(SDL_Rect &rect, int x, int y) {
	rect.x = x;
	rect.y = y;
}
