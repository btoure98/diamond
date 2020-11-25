/**
 * \file main.cpp
 * \brief Main function container
 * \author Cedric B.
 * \version 0.1
 * \date 2020-10-19
 *
 * Program launcher with game architecture skeleton
 *
 */

#include <cstdlib>
#include <ctime>
#include <ncurses.h>
#include <iostream>
#include "ncurses_addons.h"
#include "constants.h"
#include "game.h"


/**
 * \brief Main function: entry point of the program
 *
 * \return EXIT_SUCCESS if all went good, EXIT_FAILURE otherwise.
 */
int main(void)
{
    /************************************************/
    /*          Variables declarations              */
    /************************************************/
    bool cont;
    int key;
    // For game timing
    clock_t currentTime, previousTime;
    double deltaT;
    // Ball movements
    int xBall, yBall, yDirBall;
    int xBallTemp, yBallTemp;
    // Level container
    unsigned short tabLevel[TAB_LVL_HEIGHT][TAB_LVL_WIDTH];
    // Window parameters
    int windowHeight, windowWidth, gameZoneHeight, gameZoneWidth;
    WINDOW* pMainWindow;


    /************************************************/
    /*          ncurses initialization              */
    /************************************************/
    pMainWindow = init_ncurses();
    curs_set(0); // Set cursor invisible
    keypad(pMainWindow, true); // Enable arrows and special keys on keyboard


    /************************************************/
    /*          Beginning of the program            */
    /************************************************/
    /* Window and game zone characteristics */
    getmaxyx(pMainWindow, windowHeight, windowWidth);
    gameZoneHeight = TAB_LVL_HEIGHT * BRICK_PATTERN_SIZE_Y;
    gameZoneWidth = TAB_LVL_WIDTH * (BRICK_PATTERN_SIZE_X + 1);
    /* Ball initial positioning */
    xBall = 1;
    yBall = 1;
    yDirBall = DOWN;

    /* Level initializing */
    loadTabLevel(tabLevel, 1);

    /* Game main loop */
    // First initialization before looping
    previousTime = clock();
    cont = true;
    while(cont)
    {
        /* Keyboard handling */
        if(kbhit())
        {
            key = getch();
            switch(key)
            {
            case 27: // Escape key code
                cont = false;
                break;
            case KEY_LEFT:
                xBall = xBall - 1;
                break;
            case KEY_RIGHT:
                xBall = xBall + 1;
                break;
            default:
                break;
            }
        }

        /* Game parameters periodic actualization */
        currentTime = clock();
        // Elapsed time from previous actualization, in milliseconds
        deltaT = (currentTime - previousTime) * 1000 / CLOCKS_PER_SEC;
        if (deltaT > UPDATE_DELAY_MS)
        {
            previousTime = currentTime;

            // Simulate the next move
            yBallTemp = yBall;
            moveBallVertically(yBallTemp, yDirBall);
            // Is next move valid ?
            if (!isCollidingEdges(yBallTemp, 0, gameZoneHeight))
            {
                yBall = yBallTemp;
            }
            else
            {
                yDirBall = invertDirection(yDirBall);
            }
        }

        /* Graphical update */
        // Clear window
        werase(pMainWindow);
        // Display game elements
        displayLevel(tabLevel);
        displayBall(yBall, xBall);
        // refresh window needed to display all the text
        refresh();
    }


    /************************************************/
    /*          End of the program                  */
    /************************************************/
    // Close properly ncurses
    endwin();

    return EXIT_SUCCESS;
}
