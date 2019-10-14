#include <sstream>
#include <vector>
#include "PhysMemModule.hpp"

PhysMemModule::PhysMemModule() : SDLDisplay(true), _present("PhysMem") { refreshInfo(); }
PhysMemModule::~PhysMemModule() {}

const std::string &PhysMemModule::getPresent() const { return _present; }
const std::string &PhysMemModule::getUsed() const { return _used; }
const std::string &PhysMemModule::getWired() const { return _wired; }
const std::string &PhysMemModule::getUnused() const { return _unused; }

std::ostream &operator<<(std::ostream &os, PhysMemModule const &ref) {
	os	<< "_present " << ref.getPresent() << std::endl
		<< "_used " << ref.getUsed() << std::endl
		<< "_wired " << ref.getWired() << std::endl
		<< "_unused " << ref.getUnused();
	return os;
}

void PhysMemModule::refreshInfo(void) {
	char		psBuffer[128];
	FILE		*pPipe;
	std::string	buff;

	if( (pPipe = popen( "/usr/bin/top -l 1 -n 0 | awk '/PhysMem/'", "r" )) == NULL )
		throw std::logic_error("PhysMemModule can't read");
	std::fgets(psBuffer, 128, pPipe);
	buff = psBuffer;
	pclose(pPipe);

	std::istringstream iss(buff);
	std::vector<std::string> results((std::istream_iterator<std::string>(iss)),
									 std::istream_iterator<std::string>());
	_used = results[1];
	_wired = results[3];
	_wired.erase(_wired.begin());
	_unused = results[5];
}

void PhysMemModule::drawTerminal(void)
{
    refreshInfo();
    attron(COLOR_PAIR(1));
    printw("\n\nPHYSICAL MEMORY\n\n");
    attron(COLOR_PAIR(2));
    printw("Used %s\n", _used.c_str());
    printw("Wired %s\n", _wired.c_str());
    printw("Unused %s", _unused.c_str());
}
void PhysMemModule::drawSDL(void) {
//	refreshInfo();
	int x = 600;
	int y = 40;
	SDL_Rect pos = { .x = x, .y = y, .h = 0, .w = 0 };
	drawString(_present.c_str(), _white, pos, true);
	setPos(pos, x, (y += _fontSizeSmall + 7));
	drawString(("USED:   " + _used).c_str(), _white, pos, false);
	setPos(pos, x, (y += _fontSizeSmall));
	drawString(("WIRED:  " + _wired).c_str(), _white, pos, false);
	setPos(pos, x, (y += _fontSizeSmall));
	drawString(("UNUSED: " + _unused).c_str(), _white, pos, false);
}


