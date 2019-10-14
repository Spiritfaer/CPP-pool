#ifndef NETWORKS_MODULE_HPP
#define NETWORKS_MODULE_HPP

#include <string>
#include "IMonitorModule.hpp"
#include "SDLDisplay.hpp"

class NetworksModule : public IMonitorModule, public SDLDisplay {
public:
	NetworksModule();
	~NetworksModule();

	const std::string &getIn() const;
	const std::string &getOut() const;

	void drawTerminal(void);
	void drawSDL(void);
	void refreshInfo(void);

private:
	std::string		_present;
	std::string		_in;
	std::string		_out;

	NetworksModule(NetworksModule const &);
	NetworksModule &operator=(NetworksModule const &);
};

std::ostream &operator<<(std::ostream &os, NetworksModule const &ref);

#endif
