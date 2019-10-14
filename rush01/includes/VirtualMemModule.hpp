#ifndef VIRTUAL_MEM_MODULE_HPP
#define VIRTUAL_MEM_MODULE_HPP

#include <iostream>
#include "IMonitorModule.hpp"
#include "SDLDisplay.hpp"

class VirtualMemModule : public IMonitorModule, public SDLDisplay {
public:
	VirtualMemModule();
	~VirtualMemModule();

	const std::string &getPresent() const;
	const std::string &getVsize() const;
	const std::string &getFrameworkVsize() const;
	const std::string &getSwapins() const;
	const std::string &getSwapouts() const;

	void drawTerminal(void);
	void drawSDL(void);
	void refreshInfo(void);

private:
	std::string const	_present;
	std::string			_vsize;
	std::string			_frameworkVsize;
	std::string			_swapins;
	std::string			_swapouts;

	VirtualMemModule(VirtualMemModule const &);
	VirtualMemModule &operator=(VirtualMemModule const &);
};

std::ostream &operator<<(std::ostream &os, VirtualMemModule const &);

#endif
