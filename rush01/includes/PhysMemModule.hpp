#ifndef PHYS_MEM_MODULE_HPP
#define PHYS_MEM_MODULE_HPP

#include <iostream>
#include "IMonitorModule.hpp"
#include "SDLDisplay.hpp"

class PhysMemModule : public IMonitorModule, public SDLDisplay {
public:
	PhysMemModule();
	~PhysMemModule();

	const std::string &getPresent() const;
	const std::string &getUsed() const;
	const std::string &getWired() const;
	const std::string &getUnused() const;

	void drawTerminal(void);
	void drawSDL(void);
	void refreshInfo(void);

private:
	std::string const	_present;
	std::string			_used;
	std::string			_wired;
	std::string			_unused;

	PhysMemModule(PhysMemModule const &);
	PhysMemModule &operator=(PhysMemModule const &);
};

std::ostream &operator<<(std::ostream &os, PhysMemModule const &);

#endif
