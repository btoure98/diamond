/**
 * \file game.h
 * \brief Headers of dedicated functions of the game.
 * \author Cedric B.
 * \version 0.1
 * \date 2020-10-19
 *
 * This file contains all functions declarations
 * needed to compute game parameters
 * and display the graphical output
 *
 */

#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "constants.h"
#include <iostream>

/**
 * \brief Prints the ball at his position within the windows.
 *
 * \param yPos Horizontal position of the cursor for the printed character.
 * \param xPos Vertical position of the cursor for the printed character.
 *
 * This function displays the ball character at the desired position
 * and with a specific color on the ncurses window.
 *
 */
void displayBall(int yPos, int xPos);

/**
 * \brief Modifies the vertical position of the ball according to its current direction of movement.
 *
 * \param yPos the position to be modified.
 * \param yDir the current direction of the ball (its speed somehow).
 *
 */
void moveBallVertically(int &yPos, int yDir);

/**
 * \brief Checks if a value is within an interval.
 *
 * \param pos the value to be tested.
 * \param posMin the minimum value of the interval.
 * \param posMax the maximum value of the interval.
 *
 * This function can be used in particular to verify if the ball stays inside of the bounded level.
 */
bool isCollidingEdges(int pos, int posMin, int posMax);

/**
 * \brief Converts a screen position to an index couple that can be used in the array representing the level.
 *
 * \param yPos vertical position of the character in the window.
 * \param xPos horizontal position of the character in the window.
 * \param index1 the first computed index (according to Y axis) "returned" value.
 * \param index2 the second computed index (according to X axis) "returned" value.
 *
 */
void convertCoordinatesToIndexes(int yPos, int xPos, unsigned int &index1, unsigned int &index2);

/**
 * \brief Checks if a ball (preferably temporary) is within a brick of the level.
 *
 * \param yPos vertical position of the ball in the window.
 * \param xPos horizontal position of the ball in the window.
 * \param tabLvl the current table containing the level.
 *
 */
bool isCollidingBrick(int yPos, int xPos, unsigned short tabLvl[TAB_LVL_HEIGHT][TAB_LVL_WIDTH]);

/**
 * \brief Returns the opposite direction of a given direction.
 *
 * \param currentDir the current direction to invert.
 * \return the inverted direction
 *
 */
int invertDirection(int currentDir);

/**
 * \brief Displays a brick (according to its corresponding pattern) on the window screen.
 *
 * \param yPos vertical position of the brick in the window.
 * \param xPos horizontal position of the brick in the window.
 * \param brickType a constant corresponding to the type of the brick
 *
 */
void displayBrick(int yPos, int xPos, int brickType);

/**
 * \brief Initializes the current level table (in memory) according to the given level number (see levels.h).
 *
 * \param tabLvl the current table containing the level.
 * \param lvlNumber the level to be loaded in the table.
 *
 */
void loadTabLevel(unsigned short tabLvl[TAB_LVL_HEIGHT][TAB_LVL_WIDTH], unsigned int lvlNumber);

/**
 * \brief Displays all the bricks from the current level on window screen .
 *
 * \param tabLvl the current table containing the level.
 *
 */
void displayLevel(unsigned short tabLvl[TAB_LVL_HEIGHT][TAB_LVL_WIDTH]);

/**
 * \brief Modifies the level contents (table) according to the given coordinates of the ball. A modification is only possible if the brick is breakable.
 *
 * \param yPos vertical position of the ball in the window.
 * \param xPos horizontal position of the ball in the window.
 * \param tabLvl the current table containing the level.
 *
 */
void updateLevelFromCollision(int yPos, int xPos, unsigned short tabLvl[TAB_LVL_HEIGHT][TAB_LVL_WIDTH]);
#endif // GAME_H_INCLUDED
