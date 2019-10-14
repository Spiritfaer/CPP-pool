#include <iostream>
#include <fstream>
#include "Logger.hpp"

Logger::Logger(std::string const &refer) : logginType_(refer) {}

void
Logger::logToConsole(std::string const &refer) {
	std::cout << makeLogEntry(refer) << std::endl;
}

void
Logger::logToFile(std::string const &refer) {
	std::ofstream write;
	write.open(logginType_, std::ios_base::app);
	if (!write.is_open())
		write.open(logginType_, std::ios_base::app | std::ios_base::trunc);
	if (!write.is_open()) {
		std::cout << "ERROR LOGGING TO FILE WITH OPEN FILE!" << std::endl;
	}
	write << makeLogEntry(refer) << std::endl;
	write.close();
}

std::string
Logger::makeLogEntry(std::string const &refer) {
	char buff[20];
	static size_t count = 0;
	std::chrono::time_point<std::chrono::system_clock> now;
	now = std::chrono::system_clock::now();
	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
	std::strftime(buff, sizeof(buff), "[%Y%m%d_%H%M%S]", std::localtime(&now_c));
	std::string rtrn(buff);
	rtrn += " Message:" + refer + ";" + " calling:" + std::to_string(count++) + ";";
	return rtrn;
}

void
Logger::log(std::string const &dest, std::string const &message) {
	void (Logger::*logger[])(std::string const &refer) = {
		&Logger::logToFile, &Logger::logToConsole
	};
	std::string const type[] = { "logToFile", "logToConsole"	};
	for (size_t i = 0; i < 2; ++i) {
		if (dest == type[i])
			(this->*logger[i])(message);
	}
}
