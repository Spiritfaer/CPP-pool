#include <iostream>
#include <sstream>
#include <vector>
#include "NetworksModule.hpp"

NetworksModule::NetworksModule() : SDLDisplay(true), _present("Network") { refreshInfo(); }
NetworksModule::~NetworksModule() {}

const std::string &NetworksModule::getIn() const { return _in; }
const std::string &NetworksModule::getOut() const { return _out; }

std::ostream &operator<<(std::ostream &os, NetworksModule const &ref) {
	os	<< "in - " << ref.getIn() << std::endl
		<< "out - " << ref.getOut();
	return os;
}

void NetworksModule::refreshInfo(void) {
	char		psBuffer[128];
	FILE		*pPipe;
	std::string	buff;

	if( (pPipe = popen( "/usr/bin/top -l 1 -n 0 | awk '/Networks/'", "r" )) == NULL )
		throw std::logic_error("NetworksModule can't read");
	std::fgets(psBuffer, 128, pPipe);
	buff = psBuffer;
	pclose(pPipe);

	std::istringstream iss(buff);
	std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
									 std::istream_iterator<std::string>());
	_in = results[2];
	_out = results[4];
}

void NetworksModule::drawTerminal(void)
{
    refreshInfo();
    attron(COLOR_PAIR(1));
    printw("\n\nNetwork\n\n");
    attron(COLOR_PAIR(2));
    printw("IN %s\n", _in.c_str());
    printw("OUT %s", _out.c_str());
}
void NetworksModule::drawSDL(void) {
//	refreshInfo();
	int x = 30;
	int y = 200;
	SDL_Rect pos = { .x = x, .y = y, .h = 0, .w = 0 };
	drawString(_present.c_str(), _white, pos, true);
	setPos(pos, x, (y += _fontSizeSmall + 7));
	drawString(("IN:     " + _in).c_str(), _white, pos, false);
	setPos(pos, x, (y += _fontSizeSmall));
	drawString(("OUT: " + _out).c_str(), _white, pos, false);
}
