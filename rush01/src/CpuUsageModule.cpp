#include <iostream>
#include <sstream>
#include <vector>
#include "CpuUsageModule.hpp"

CpuUsageModule::CpuUsageModule() : SDLDisplay(true), _present("CPU Usage") { refreshInfo(); }
CpuUsageModule::~CpuUsageModule() {}

const std::string &CpuUsageModule::getUser() const { return _user; }
const std::string &CpuUsageModule::getSys() const { return _sys; }
const std::string &CpuUsageModule::getIdle() const { return _idle; }

std::ostream &operator<<(std::ostream &os, CpuUsageModule const &ref) {
	os	<< "user - " << ref.getUser() << std::endl
		<< "sys - " << ref.getSys() << std::endl
		<< "idle - " << ref.getIdle();
	return os;
}

void CpuUsageModule::refreshInfo() {
	char		psBuffer[128];
	FILE		*pPipe;
	std::string	buff;

	if( (pPipe = popen( "/usr/bin/top -l 1 -n 0 | awk '/CPU usage/'", "r" )) == NULL )
		throw std::logic_error("CpuUsageModule can't read");
	std::fgets(psBuffer, 128, pPipe);
	buff = psBuffer;
	pclose(pPipe);

	std::istringstream iss(buff);
	std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
									 std::istream_iterator<std::string>());
	_user = results[2];
	_sys = results[4];
	_idle = results[6];
}

void CpuUsageModule::drawTerminal()
{
    refreshInfo();
    attron(COLOR_PAIR(1));
    printw("\n\nCPU Usage\n\n");
    attron(COLOR_PAIR(2));
    printw("User: %s\n", _user.c_str());
    printw("Sys: %s\n", _sys.c_str());
    printw("IDLE %s", _idle.c_str());
}
void CpuUsageModule::drawSDL()
{
//	refreshInfo();
	int x = 30;
	int y = 40;
	SDL_Rect pos = { .x = x, .y = y, .h = 0, .w = 0 };
	drawString(_present.c_str(), _white, pos, true);
	setPos(pos, x, (y += _fontSizeSmall + 7));
	drawString(("USER:  " + _user).c_str(), _white, pos, false);
	setPos(pos, x, (y += _fontSizeSmall));
	drawString(("SYS:    " + _sys).c_str(), _white, pos, false);
	setPos(pos, x, (y += _fontSizeSmall));
	drawString(("IDLE:   " + _idle).c_str(), _white, pos, false);
}
