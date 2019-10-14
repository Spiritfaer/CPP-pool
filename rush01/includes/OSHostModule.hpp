#ifndef OS_HOST_MODULE_HPP
#define OS_HOST_MODULE_HPP

#include <string>
#include "IMonitorModule.hpp"
#include "SDLDisplay.hpp"

class OSHostModule : public IMonitorModule, public SDLDisplay {

public:
	OSHostModule();
	~OSHostModule();

	void drawTerminal(void);
	void drawSDL();

	void refreshInfo(void);

	const std::string &getPresent() const;
	const std::string &getSysname() const;
	const std::string &getRelease() const;
	const std::string &getVersion() const;
	const std::string &getMachine() const;
private:
	std::string	_present;
	std::string	_sysname;
	std::string	_release;
	std::string	_version;
	std::string	_machine;

	OSHostModule(OSHostModule const &);
	OSHostModule &operator=(OSHostModule const &);
};

std::ostream &operator<<(std::ostream &os, OSHostModule const &ref);

#endif
