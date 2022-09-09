#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>

typedef struct direction
{
    int x;
    int y;
    bool operator<(const direction &dir) const
    {
        if (x != dir.x)
        {
            return x < dir.x;
        }
        else
        {
            return y < dir.y;
        }
        return true;
    }
} direction;

typedef struct coordinate
{
    int x;
    int y;
    direction dir;
} coordinate;

void showSurvivalTime();

#endif