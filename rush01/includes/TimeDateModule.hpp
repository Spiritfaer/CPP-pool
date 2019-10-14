#ifndef TIME_DATE_MODULE_HPP
#define TIME_DATE_MODULE_HPP

#include "IMonitorModule.hpp"
#include "SDLDisplay.hpp"

class TimeDateModule : public IMonitorModule, public SDLDisplay {
public:
	TimeDateModule();
	~TimeDateModule();

	void drawTerminal(void);
	void drawSDL(void);
	void refreshInfo(void);

	const std::string &getTime() const;

private:
	std::string _present;
	std::string _time;

	TimeDateModule(TimeDateModule const &);
	TimeDateModule &operator=(TimeDateModule const &);
};

std::ostream &operator<<(std::ostream &os, TimeDateModule const &);

#endif
