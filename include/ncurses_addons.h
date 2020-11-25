/**
 * \file ncurses_addons.h
 * \brief Headers of extended functions for ncurses library container.
 * \author Cedric B.
 * \version 0.1
 * \date 2020-10-19
 *
 * This file consists in an extension of the ncurses base functionalities declaration
 *
 */

#ifndef NCURSES_ADDONS_H_INCLUDED
#define NCURSES_ADDONS_H_INCLUDED

#include <ncurses.h>


/**
 * \brief Color pairs constants.
 *
 * Color pairs constant to use within COLOR_PAIR macro
 * in order to select the foreground and background colors.
 */
enum FG_BG_COLOR_PAIRS {BLACK_ON_BLACK = 1, RED_ON_BLACK, GREEN_ON_BLACK, YELLOW_ON_BLACK, BLUE_ON_BLACK, MAGENTA_ON_BLACK, CYAN_ON_BLACK, WHITE_ON_BLACK}; // Number 0 is RESERVED by the terminal


/**
 * \brief ncurses library initialization and window creation.
 *
 * \return A pointer to the created window.
 *
 * This function verifies if the system can launch ncurses
 * and if terminals support colors. If not, the program
 * execution is aborted.
 */
WINDOW* init_ncurses();


/**
 * \brief Map all colors (foreground) with a black background for COLOR_PAIR needs.
 *
 */
void mapColors();


/**
 * \brief Check if a key has been pressed since the last call of the function.
 *
 * \return 1 if a key was pressed, 0 otherwise.
 *
 */
int kbhit();

#endif // NCURSES_ADDONS_H_INCLUDED
