#include <sstream>
#include <vector>
#include "VirtualMemModule.hpp"

VirtualMemModule::VirtualMemModule() : SDLDisplay(true), _present("Virtual Memory") { refreshInfo(); }
VirtualMemModule::~VirtualMemModule() {}

const std::string &VirtualMemModule::getPresent() const { return _present;}
const std::string &VirtualMemModule::getVsize() const { return _vsize;}
const std::string &VirtualMemModule::getFrameworkVsize() const { return _frameworkVsize;}
const std::string &VirtualMemModule::getSwapins() const { return _swapins;}
const std::string &VirtualMemModule::getSwapouts() const { return _swapouts;}

std::ostream &operator<<(std::ostream &os, VirtualMemModule const &ref) {
	os	<< "_present " << ref.getPresent() << std::endl
		<< "_vsize " << ref.getVsize() << std::endl
		<< "_frameworkVsize " << ref.getFrameworkVsize() << std::endl
		<< "_swapins " << ref.getSwapins() << std::endl
		<< "_swapouts " << ref.getSwapouts();
	return os;
}

void VirtualMemModule::refreshInfo(void) {
	char		psBuffer[128];
	FILE		*pPipe;
	std::string	buff;

	if( (pPipe = popen( "/usr/bin/top -l 1 -n 0 | awk '/VM/'", "r" )) == NULL )
		throw std::logic_error("PhysMemModule can't read");
	std::fgets(psBuffer, 128, pPipe);
	buff = psBuffer;
	pclose(pPipe);

	std::istringstream iss(buff);
	std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
									 std::istream_iterator<std::string>());
	_vsize = results[1];
	_frameworkVsize = results[3];
	_swapins = results[6];
	_swapouts = results[8];
}

void VirtualMemModule::drawTerminal(void)
{
    refreshInfo();
    attron(COLOR_PAIR(1));
    printw("\n\nVirtual Memory\n\n");
    attron(COLOR_PAIR(2));
    printw("Vsize %s\n", _vsize.c_str());
    printw("FrameWork Size %s\n", _frameworkVsize.c_str());
    printw("SwapIns %s\n", _swapins.c_str());
    printw("SwapOut %s", _swapouts.c_str());
}
void VirtualMemModule::drawSDL(void) {
//	refreshInfo();
	int x = 600;
	int y = 350;
	SDL_Rect pos = { .x = x, .y = y, .h = 0, .w = 0 };
	drawString(_present.c_str(), _white, pos, true);
	setPos(pos, x, (y += _fontSizeSmall + 7));
	drawString(("VSIZE:     " + _vsize).c_str(), _white, pos, false);
	setPos(pos, x, (y += _fontSizeSmall));
	drawString(("FRAMEWORK: " + _frameworkVsize).c_str(), _white, pos, false);
	setPos(pos, x, (y += _fontSizeSmall));
	drawString(("SWAPINS :  " + _swapins).c_str(), _white, pos, false);
	setPos(pos, x, (y += _fontSizeSmall));
	drawString(("SWAPOUTS:  " + _swapouts).c_str(), _white, pos, false);
}
