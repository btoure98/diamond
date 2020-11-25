/**
 * \file constants.h
 * \brief Headers file with all constants used in the game.
 * \author Cedric B.
 * \version 0.1
 * \date 2020-10-19
 *
 * This file contains all the constants required by the game elements.
 *
 */

#ifndef CONSTANTS_H_INCLUDED
#define CONSTANTS_H_INCLUDED
/**
* Update delay between two sprite movements.
*/
const double UPDATE_DELAY_MS = 80;

enum DIRECTIONS {LEFT, RIGHT, DOWN, UP};
const unsigned int BRICK_PATTERN_SIZE_X = 8;
const unsigned int BRICK_PATTERN_SIZE_Y = 3;

/**
 * \brief All different brick types constants.
 *
 * BRICKTYPES enumerates all the kinds of bricks.
 */
enum BRICKTYPES {NORMAL_BRICK, DOUBLEHIT_BRICK, UNBREAKABLE_BRICK, RAZOR_BRICK, NO_BRICK};

/**
* Vertical dimension of levels (in number of bricks).
*/
const unsigned int TAB_LVL_HEIGHT = 10;

/**
* Horizontal dimension of levels (in number of bricks).
*/
const unsigned int TAB_LVL_WIDTH = 8;

#endif // CONSTANTS_H_INCLUDED

