#include "Logger.hpp"

int		main(void)
{
	Logger toConsole;
	for (size_t i = 0; i < 5; ++i) {
		toConsole.log("logToConsole", "Testing console message");
	}

	Logger toFile;
	for (size_t i = 0; i < 5; ++i) {
		toConsole.log("logToFile", "Testing file message");
	}

	return 0;
}
