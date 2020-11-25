/**
 * \file ncurses_addons.cpp
 * \brief Extended functions for ncurses library container.
 * \author Cedric B.
 * \version 0.1
 * \date 2020-10-19
 *
 * This file consists in an extension of the ncurses base functionalities
 *
 */

#include <cstdlib>
#include "ncurses_addons.h"


WINDOW* init_ncurses()
{
    WINDOW* pWindow;
    // Creating the window terminal
    pWindow = initscr();
    if(pWindow == NULL)
    {
        printf("Failed to create a ncurses window terminal\n");
        exit(EXIT_FAILURE);
    }
    // Verifying terminal color support
    if (has_colors() == FALSE)
    {
        endwin();
        printf("Your terminal does not support color\n");
        exit(EXIT_FAILURE);
    }
    // Start ncurses color system
    start_color();
    // Create foreground/background color pairs
    mapColors();

    // Disable key press display on screen
    noecho();

    // getch becomes non blocking (use kbhit...)
    nodelay(stdscr, TRUE);

    return pWindow;
}


void mapColors()
{
    unsigned short i;

    // Number 0 for init_pair and COLOR_PAIR is RESERVED by the terminal
    // so BLACK_ON_BLACK begins the enum at 1
    // but ncurses COLORS constants start from 0 (see ncurses.h)
    for(i=BLACK_ON_BLACK; i<WHITE_ON_BLACK; i++)
    {
        init_pair(i, i-1, COLOR_BLACK);
    }
}


int kbhit()
{
    int ch = getch();

    if (ch != ERR)
    {
        ungetch(ch);
        return 1;
    }
    else
    {
        return 0;
    }
}
