#ifndef CPU_USAGE_MODULE_HPP
#define CPU_USAGE_MODULE_HPP

#include <string>
#include "IMonitorModule.hpp"
#include "SDLDisplay.hpp"

class CpuUsageModule : public IMonitorModule, public SDLDisplay {
public:
	CpuUsageModule();
	~CpuUsageModule();

	void drawTerminal(void);
	void drawSDL(void);
	void refreshInfo(void);

	const std::string &getUser() const;
	const std::string &getSys() const;
	const std::string &getIdle() const;

private:
	std::string		_present;
	std::string		_user;
	std::string		_sys;
	std::string		_idle;

	CpuUsageModule(CpuUsageModule const &);
	CpuUsageModule &operator=(CpuUsageModule const &);
};

std::ostream &operator<<(std::ostream &os, CpuUsageModule const &ref);

#endif
