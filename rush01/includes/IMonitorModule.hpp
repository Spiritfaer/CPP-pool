#ifndef IMONITOR_MODULE_HPP
#define IMONITOR_MODULE_HPP

#include <ncurses.h>

class IMonitorModule
{
public:
	virtual void drawTerminal(void) = 0;
	virtual void drawSDL() = 0;
	virtual void refreshInfo(void) = 0;
	virtual ~IMonitorModule() {}
};

#endif
