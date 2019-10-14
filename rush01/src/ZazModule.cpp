#include "ZazModule.hpp"

ZazModule::ZazModule() : SDLDisplay(true), _present("Zaz's cat") { refreshInfo(); }
ZazModule::~ZazModule() {}

void ZazModule::refreshInfo(void) {
	SDL_Surface *tmp;

	tmp = IMG_Load("cat/tenor-3-1dragged.png");
	_catSDL[0] = SDL_CreateTextureFromSurface(_render, tmp);
	SDL_FreeSurface(tmp);

	tmp = IMG_Load("cat/tenor-3-2dragged.png");
	_catSDL[1] =  SDL_CreateTextureFromSurface(_render, tmp);
	SDL_FreeSurface(tmp);

	tmp = IMG_Load("cat/tenor-3-3dragged.png");
	_catSDL[2] =  SDL_CreateTextureFromSurface(_render, tmp);
	SDL_FreeSurface(tmp);

	tmp = IMG_Load("cat/tenor-3-4dragged.png");
	_catSDL[3] =  SDL_CreateTextureFromSurface(_render, tmp);
	SDL_FreeSurface(tmp);

	tmp = IMG_Load("cat/tenor-3-5dragged.png");
	_catSDL[4] =  SDL_CreateTextureFromSurface(_render, tmp);
	SDL_FreeSurface(tmp);
}

void ZazModule::drawTerminal() {}

void ZazModule::drawSDL() {
	static int index = 0;
	int x = 1920 / 4 - 220 / 2;
	int y = 1080 / 4 - 206 / 2;
	SDL_Rect pos = { .x = x, .y = y, .h = 206, .w = 220 };
	SDL_RenderCopy(_render, _catSDL[index++], NULL, &pos);
	index = (index > 4) ? 0 : index;
}
