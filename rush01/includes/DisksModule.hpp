#ifndef DISKS_MODULE_HPP
#define DISKS_MODULE_HPP

#include <string>
#include "IMonitorModule.hpp"
#include "SDLDisplay.hpp"

class DisksModule : public IMonitorModule, public SDLDisplay {
public:
	DisksModule();
	~DisksModule();

	void drawTerminal(void);
	void drawSDL(void);
	void refreshInfo(void);

	const std::string &getRead() const;
	const std::string &getWritten() const;

private:
	std::string		_present;
	std::string		_read;
	std::string		_written;

	DisksModule(DisksModule const &);
	DisksModule &operator=(DisksModule const &);
};

std::ostream &operator<<(std::ostream &os, DisksModule const &ref);

#endif
