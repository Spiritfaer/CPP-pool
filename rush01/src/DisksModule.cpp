#include <iostream>
#include <sstream>
#include <vector>
#include "DisksModule.hpp"

DisksModule::DisksModule() : SDLDisplay(true), _present("Disk") { refreshInfo(); }
DisksModule::~DisksModule() {}

const std::string &DisksModule::getRead() const { return _read; }
const std::string &DisksModule::getWritten() const { return _written; }

std::ostream &operator<<(std::ostream &os, DisksModule const &ref) {
	os	<< "read - " << ref.getRead() << std::endl
		<< "written - " << ref.getWritten();
	return os;
}

void DisksModule::refreshInfo() {
	char		psBuffer[128];
	FILE		*pPipe;
	std::string	buff;

	if( (pPipe = popen( "/usr/bin/top -l 1 -n 0 | awk '/Disks/'", "r" )) == NULL )
		throw std::logic_error("NetworksModule can't read");
	std::fgets(psBuffer, 128, pPipe);
	buff = psBuffer;
	pclose(pPipe);

	std::istringstream iss(buff);
	std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
									 std::istream_iterator<std::string>());
	_read = results[1];
	_written = results[3];
}

void DisksModule::drawTerminal()
{
    refreshInfo();
    attron(COLOR_PAIR(1));
    printw("\n\nDISK\n\n");
    attron(COLOR_PAIR(2));
    printw("Read %s\n", _read.c_str());
    printw("Written %s", _written.c_str());
}
void DisksModule::drawSDL() {
//	refreshInfo();
	int x = 600;
	int y = 200;
	SDL_Rect pos = { .x = x, .y = y, .h = 0, .w = 0 };
	drawString(_present.c_str(), _white, pos, true);
	setPos(pos, x, (y += _fontSizeSmall + 7));
	drawString(("READ:    " + _read).c_str(), _white, pos, false);
	setPos(pos, x, (y += _fontSizeSmall));
	drawString(("WRITTEN: " + _written).c_str(), _white, pos, false);
}
