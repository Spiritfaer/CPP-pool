#ifndef SDL_DISPLAY_HPP
#define SDL_DISPLAY_HPP

#include "IMonitorDisplay.hpp"
#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

#define WINDOW_W 1920 / 2
#define WINDOW_H 1080 / 2
#define FONT_REGULAR "fonts/Regular.ttf"
#define FONT_BOLD "fonts/Bold.ttf"

class SDLDisplay : public IMonitorDisplay {
public:
	SDLDisplay();
	SDLDisplay(bool);
	virtual ~SDLDisplay();

	SDL_Window *getWindow() const;
	SDL_Renderer *getRender() const;
	SDL_Texture *getTexture() const;
	SDL_Surface *getSurface() const;
	TTF_Font *getFont() const;
	unsigned int getFontSize() const;

	void loop(const std::vector<IMonitorModule *> &modules);
	void drawString(const char *str, SDL_Color const &color, SDL_Rect &pos, bool big);
	void setPos(SDL_Rect &rect, int x, int y);

	void init(void);
	void end(void);

protected:
	static SDL_Window		*_window;
	static SDL_Renderer		*_render;
	static SDL_Texture		*_texture;
	static SDL_Surface		*_surface;
	static TTF_Font			*_fontBig;
	static unsigned int		_fontSizeBig;
	static TTF_Font			*_fontSmall;
	static unsigned int		_fontSizeSmall;

	static SDL_Color		_white;
	bool					_cat;
private:
	SDLDisplay(SDLDisplay const &);
	SDLDisplay &operator=(SDLDisplay const &);

	bool eventGuard(SDL_Event &);
	void windowsPresent(void);
	void windowsClear(void);
};

#endif
