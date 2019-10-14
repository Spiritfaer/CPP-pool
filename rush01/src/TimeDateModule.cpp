#include <iostream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include "TimeDateModule.hpp"

TimeDateModule::TimeDateModule() : SDLDisplay(true), _present("Data/Time") { refreshInfo(); }
TimeDateModule::~TimeDateModule() {}

const std::string &TimeDateModule::getTime() const { return _time; }

std::ostream &operator<<(std::ostream &os, TimeDateModule const &ref) {
	os << ref.getTime();
	return os;
}

void TimeDateModule::refreshInfo() {
	std::time_t t = std::time(nullptr);
	std::stringstream buff;

	if (t % 2)
		buff << "local:     " << std::put_time(std::localtime(&t), "%H:%M:%S %A %d %B %Y %Z");
	else
		buff << "local:     " << std::put_time(std::localtime(&t), "%H %M %S %A %d %B %Y %Z");
	_time = buff.str();
}

void TimeDateModule::drawTerminal()
{
    refreshInfo();
    attron(COLOR_PAIR(1));
    printw("\n\nTIME/DATE\n\n");
    attron(COLOR_PAIR(2));
    printw("Time %s", _time.c_str());
}
void TimeDateModule::drawSDL() {
//	refreshInfo();
	SDL_Rect pos = { .x = 200, .y = 0, .h = 0, .w = 0 };
	drawString(_time.c_str(), _white, pos, true);
}
