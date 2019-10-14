#include "NcursesDisplay.hpp"

NcursesDisplay::NcursesDisplay() { init(); }
NcursesDisplay::~NcursesDisplay() {}


namespace
{
    void resizeHandl(int) {
        endwin();
        std::cerr << "Window size cannot be resized" << std::endl;
        exit(1);
    }

    void checkSize() {
        int terminal_h, terminal_w;
        getmaxyx(stdscr, terminal_h, terminal_w);
        if (terminal_w < PLAY_WINDOW_W || terminal_h < PLAY_WINDOW_H) {
            endwin();
            std::cerr << "Window so small" << std::endl;
            exit(1);
        }
    }
}

void NcursesDisplay::init()
{
    setlocale(LC_ALL, "");
    initscr();
    checkSize();
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_RED);
    init_pair(2, COLOR_BLACK, COLOR_WHITE);
    signal(SIGWINCH, resizeHandl);
    noecho();
}

void NcursesDisplay::end() {}

void NcursesDisplay::loop(const std::vector<IMonitorModule *> &modules)
{
    unsigned int i;

    while (true)
    {
        i = 0;
        clear();
        while (i < modules.size())
        {
            modules[i]->drawTerminal();
            i++;
        }
        refresh();
        nodelay(stdscr, 1);
        if (wgetch(stdscr) == 27)
        {
            clear();
            refresh();
            exit(0);
        }
        usleep(100000);
    }
}
