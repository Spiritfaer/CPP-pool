#ifndef ZAZMODULE_HPP
#define ZAZMODULE_HPP

#include <iostream>
#include "IMonitorModule.hpp"
#include "SDLDisplay.hpp"

class ZazModule : public IMonitorModule, public SDLDisplay {
public:
	ZazModule();
	~ZazModule();

	void drawTerminal(void);
	void drawSDL(void);
	void refreshInfo(void);

private:
	std::string const	_present;
	SDL_Texture			*_catSDL[5];

	ZazModule(ZazModule const &);
	ZazModule &operator=(ZazModule const &);
};

std::ostream &operator<<(std::ostream &os, ZazModule const &);

#endif
