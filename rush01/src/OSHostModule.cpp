#include <iostream>
#include <sys/utsname.h>
#include "OSHostModule.hpp"

OSHostModule::OSHostModule() : SDLDisplay(true), _present("Host name") { refreshInfo(); }
OSHostModule::~OSHostModule() {}

void OSHostModule::refreshInfo() {
	struct utsname name;

	uname(&name);

	_sysname = name.sysname;
	_release = name.release;
	_version = name.version;
	_version.erase(_version.begin() + 28, _version.end());
	_machine = name.machine;
}

const std::string &OSHostModule::getPresent() const { return _present; }
const std::string &OSHostModule::getSysname() const { return _sysname; }
const std::string &OSHostModule::getRelease() const { return _release; }
const std::string &OSHostModule::getVersion() const { return _version; }
const std::string &OSHostModule::getMachine() const { return _machine; }

std::ostream &operator<<(std::ostream &os, OSHostModule const &ref) {
	os	<< " _present - " << ref.getPresent() << std::endl
		<< " _sysname - " << ref.getSysname() << std::endl
		<< " _release - " << ref.getRelease() << std::endl
		<< " _version - " << ref.getVersion() << std::endl
		<< " _machine - " << ref.getMachine();
	return os;
}

void OSHostModule::drawTerminal()
{
    refreshInfo();
    attron(COLOR_PAIR(1));
    printw("\n\nHost name\n\n");
    attron(COLOR_PAIR(2));
    printw("Sysname %s\n", _sysname.c_str());
    printw("Release %s\n", _release.c_str());
    printw("Version %s\n", _version.c_str());
    printw("Machine %s", _machine.c_str());
}
void OSHostModule::drawSDL() {
//	refreshInfo();
	int x = 30;
	int y = 350;
	SDL_Rect pos = { .x = x, .y = y, .h = 0, .w = 0 };
	drawString(_present.c_str(), _white, pos, true);
	setPos(pos, x, (y += _fontSizeSmall + 7));
	drawString(("SYSNAME:    " + _sysname).c_str(), _white, pos, false);
	setPos(pos, x, (y += _fontSizeSmall));
	drawString(("RELEASE: " + _release).c_str(), _white, pos, false);
	setPos(pos, x, (y += _fontSizeSmall));
	drawString(("VERSION: " + _version).c_str(), _white, pos, false);
	setPos(pos, x, (y += _fontSizeSmall));
	drawString(("MACHINE: " + _machine).c_str(), _white, pos, false);
}
