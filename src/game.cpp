/**
 * \file game.cpp
 * \brief Dedicated functions of the game container.
 * \author Cedric B.
 * \version 0.1
 * \date 2020-10-19
 *
 * This file contains all functions needed to compute game parameters
 * and display the graphical output
 *
 */


#include <ncurses.h>
#include "ncurses_addons.h"
#include "game.h"
#include "constants.h"
#include "brickshapes.h"
#include "levels.h"


void displayBall(int yPos, int xPos)
{
    move(yPos, xPos);
    attron(COLOR_PAIR(WHITE_ON_BLACK));
    printw("@");
    attroff(COLOR_PAIR(WHITE_ON_BLACK));
}

void moveBallVertically(int &yPos, int yDir)
{
    if (yDir == UP)
    {
        yPos = yPos - 1;
    }
    else
    {
        yPos = yPos + 1;
    }
}

bool isCollidingEdges(int pos, int posMin, int posMax)
{
    if ( (pos < posMin) || (pos >= posMax) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

void convertCoordinatesToIndexes(int yPos, int xPos, unsigned int &index1, unsigned int &index2)
{
    index1 = yPos/10;
    index2 = xPos/8;
}

bool isCollidingBrick(int yPos, int xPos, unsigned short tabLvl[TAB_LVL_HEIGHT][TAB_LVL_WIDTH])
{
    bool isColliding = false;

    unsigned int index1;
    unsigned int index2;
    // get index in tab from position in window
    convertCoordinatesToIndexes(yPos, xPos, index1, index2);
    if (tabLvl[index1][index2] != 4) // birck not empty
        isColliding = true;
    return isColliding;
}

int invertDirection(int currentDir)
{
    int newDir;

    switch(currentDir)
    {
    case LEFT:
        newDir = RIGHT;
        break;
    case RIGHT:
        newDir = LEFT;
        break;
    case DOWN:
        newDir = UP;
        break;
    case UP:
        newDir = DOWN;
        break;
    default :
        newDir = currentDir;
        break;
    }
    return newDir;
}

void displayBrick(int yPos, int xPos, int brickType)
{
    unsigned int i;
    for(i=0; i<BRICK_PATTERN_SIZE_Y; i=i+1)
    {
        mvprintw(yPos+i, xPos, "%s", TAB_BRICK_PATTERNS[brickType][i]);
    }

}

void loadTabLevel(unsigned short tabLvl[TAB_LVL_HEIGHT][TAB_LVL_WIDTH], unsigned int lvlNumber)
{
    if (lvlNumber == 1)
        for (int row = 0; row < TAB_LVL_HEIGHT; row++ )
        {
            for (int col = 0; col < TAB_LVL_WIDTH; col++ )
                tabLvl[row][col] = LEVEL_1[row][col];
        }

}

void displayLevel(unsigned short tabLvl[TAB_LVL_HEIGHT][TAB_LVL_WIDTH])
{
    for (int col = 0; col < TAB_LVL_WIDTH; col++ )
    {
        for (int ligne = 0; ligne < TAB_LVL_HEIGHT; ligne++)
        {
            displayBrick(ligne*3, col*8, tabLvl[ligne][col]);
        }
    }
}

void updateLevelFromCollision(int yPos, int xPos, unsigned short tabLvl[TAB_LVL_HEIGHT][TAB_LVL_WIDTH])
{
    if (isCollidingBrick(yPos, xPos, tabLvl))
    {
        unsigned int index1;
        unsigned int index2;
        convertCoordinatesToIndexes(yPos, xPos, index1, index2);
        int brickType = tabLvl[index1][index2];
        switch (brickType)
        {
        case 0:
            //le joueur perd une vie
            break;
        case 1:
            break;
        case 2:
            tabLvl[index1][index2] = 3;
            break;
        case 3:
            tabLvl[index1][index2] = 4;
            break;
        default:
            break;
        }
    }
        
}
