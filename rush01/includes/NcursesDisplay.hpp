#ifndef NCURSES_DISPLAY_HPP
#define NCURSES_DISPLAY_HPP

#include "ncurses.h"
#include "Cor.hpp"
#include "IMonitorDisplay.hpp"
#include <clocale>
#include <zconf.h>

#define  PLAY_WINDOW_W 50
#define  PLAY_WINDOW_H 50

class NcursesDisplay : IMonitorDisplay {
public:
    NcursesDisplay();
    ~NcursesDisplay();

    void loop(const std::vector<IMonitorModule *> &modules);

    void    init();
    void    end();

private:
	NcursesDisplay(NcursesDisplay const &);
	NcursesDisplay &operator=(NcursesDisplay const &);
};


#endif
