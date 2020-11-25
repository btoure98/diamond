/**
 * \file levels.h
 * \brief Headers file with tables containing each game level definition.
 * \author Cedric B.
 * \version 0.1
 * \date 2020-10-19
 *
 * This file contains all the game levels definition (one table per level).
 *
 */

#ifndef LEVELS_H_INCLUDED
#define LEVELS_H_INCLUDED

#include "constants.h"


const unsigned short LEVEL_1[TAB_LVL_HEIGHT][TAB_LVL_WIDTH] =
{
    {4,4,3,0,0,3,4,4},
    {4,4,3,1,1,3,4,4},
    {4,0,0,0,0,0,0,4},
    {4,2,4,4,4,4,2,4},
    {4,4,4,4,4,4,4,4},
    {4,4,4,4,4,4,4,4},
    {4,2,4,4,4,4,2,4},
    {4,0,0,0,0,0,0,4},
    {4,4,3,1,1,3,4,4},
    {4,4,3,0,0,3,4,4}
};

#endif // LEVELS_H_INCLUDED
