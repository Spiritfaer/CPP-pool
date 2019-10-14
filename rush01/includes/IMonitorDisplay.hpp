#ifndef IMONITOR_DISPLAY_HPP
#define IMONITOR_DISPLAY_HPP

#include "IMonitorModule.hpp"

class IMonitorDisplay
{
public:
	virtual void init() = 0;
	virtual void end() = 0;
	virtual void loop(const std::vector<IMonitorModule *> &) = 0;
	virtual ~IMonitorDisplay() {}
};

#endif
