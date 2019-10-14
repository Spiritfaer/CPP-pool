
#include "main.hpp"

void    printUsage()
{
    std::cout << "./ft_gkrellm [-os -dt -cpu -ram -net -vm -hd]" << std::endl;
    std::cout << "-os : shows info about host name and Machine" << std::endl;
    std::cout << "-dt : shows current date and time" << std::endl;
    std::cout << "-cpu : shows info about cpu" << std::endl;
    std::cout << "-ram : shows info about ram" << std::endl;
    std::cout << "-net : shows info about network" << std::endl;
    std::cout << "-vm : shows info about virtual memory" << std::endl;
    std::cout << "-hd : shows info about disk" << std::endl;
}

int main(int argc, char *argv[]) {
	ZazModule test;

	try {
		Cor cor(argc, argv);
		if (argc == 1) {
			SDLDisplay sdl;
			sdl.loop(cor.getModules());
			sdl.end();
		} else {
			NcursesDisplay ncurses;
			ncurses.loop(cor.getModules());
		}
	} catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
        printUsage();
    }

	return 0;
}
