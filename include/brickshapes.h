/**
 * \file brickshapes.h
 * \brief Headers file with string table containing the bricks patterns.
 * \author Cedric B.
 * \version 0.1
 * \date 2020-10-19
 *
 * This file contains the bricks patterns to be displayed on the game screen.
 *
 */

#ifndef BRICKSHAPES_H_INCLUDED
#define BRICKSHAPES_H_INCLUDED

#include "constants.h"

const char TAB_BRICK_PATTERNS[4][BRICK_PATTERN_SIZE_Y][BRICK_PATTERN_SIZE_X+1] =
{
    {
        "--------",
        "88888888",
        "--------",
    },
    {
        "********",
        "* *  * *",
        "********",
    },
    {
        "--------",
        "|      |",
        "--------",
    },
    {
        "MMMMMMMM",
        "I  XX  I",
        "WWWWWWWW",
    }
};

#endif // BRICKSHAPES_H_INCLUDED
