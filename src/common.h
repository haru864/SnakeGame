#ifndef _COMMON_H_
#define _COMMON_H_

typedef struct direction
{
    int x;
    int y;
} direction;

typedef struct coordinate
{
    int x;
    int y;
    direction dir;
} coordinate;

void showSurvivalTime();

#endif