#include <iostream>
#include <ncurses.h>
#include "snake.h"

extern int SCREEN_HEIGHT, SCREEN_WIDTH;
extern int EATEN_FEED;
extern time_t START_TIME, END_TIME;

Snake::Snake()
{
    // go to right at first
    direction dir = DIR_RIGHT;
    coordinate coord = {0, 0, dir};
    body.push_back(coord);

    // set icon
    icon[DIR_LEFT] = '<';
    icon[DIR_RIGHT] = '>';
    icon[DIR_UP] = '^';
    icon[DIR_DOWN] = 'v';
    currentHead = icon[DIR_RIGHT];

    // set birth time
    START_TIME = time(NULL);
}

Snake::~Snake() {}

void Snake::eat(Feed feed)
{
    // direction dir = body.back().dir;

    // coordinate coord = {0, 0, dir};

    // body.push_back(coord);
}

void Snake::move()
{
    for (size_t i = 0; i < body.size(); i++)
    {
        body.at(i).x += body.at(i).dir.x;
        body.at(i).y += body.at(i).dir.y;
    }

    if (isBorder())
    {
        die();
    }
}

void Snake::move(char ch)
{
    switch (ch)
    {
    case 'w':
        body.at(0).dir = DIR_UP;
        currentHead = icon[DIR_UP];
        break;
    case 'a':
        body.at(0).dir = DIR_LEFT;
        currentHead = icon[DIR_LEFT];
        break;
    case 's':
        body.at(0).dir = DIR_DOWN;
        currentHead = icon[DIR_DOWN];
        break;
    case 'd':
        body.at(0).dir = DIR_RIGHT;
        currentHead = icon[DIR_RIGHT];
        break;
    case '\n':
        die();
        break;
    default:
        break;
    }
}

void Snake::die()
{
    // set dead time
    END_TIME = time(NULL);

    endwin();
    fprintf(stdout, "feeds: %d\n", EATEN_FEED);
    showSurvivalTime();
    fflush(stdout);
    exit(0);
}

bool Snake::isBorder()
{
    if (body.front().x < 0 || body.front().x > SCREEN_WIDTH)
        return true;
    if (body.front().y < 0 || body.front().y > SCREEN_HEIGHT)
        return true;
    return false;
}
