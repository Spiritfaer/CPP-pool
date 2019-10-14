#ifndef LOGGER_HPP
#define LOGGER_HPP


#include <string>

class Logger {

public:
	Logger(std::string const &refer = "test.log");
	void log(std::string const &dest, std::string const & message);

private:
	std::string	logginType_;

	void logToConsole(std::string const &refer);
	void logToFile(std::string const &refer);
	std::string makeLogEntry(std::string const &refer);
};


#endif
