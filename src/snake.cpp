#include <iostream>
#include <ncurses.h>
#include <vector>
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

    // set birth time
    START_TIME = time(NULL);
}

Snake::~Snake()
{
}

void Snake::eat(Feed feed)
{
    feed.birth();
    grow();
    EATEN_FEED++;
}

void Snake::grow()
{
    coordinate tailEnd;
    tailEnd.dir = body.back().dir;
    tailEnd.x = body.back().x + body.back().dir.x * (-1);
    tailEnd.y = body.back().y + body.back().dir.y * (-1);
    body.push_back(tailEnd);
}

void Snake::move()
{
    for (int i = 0; i < body.size(); i++)
    {
        int idx = (body.size() - 1) - i;
        if (idx == 0)
        {
            body.at(idx).x += body.at(idx).dir.x;
            body.at(idx).y += body.at(idx).dir.y;
        }
        else
        {
            body.at(idx).x = body.at(idx - 1).x;
            body.at(idx).y = body.at(idx - 1).y;
            body.at(idx).dir = body.at(idx - 1).dir;
        }
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
        body.front().dir = DIR_UP;
        break;
    case 'a':
        body.front().dir = DIR_LEFT;
        break;
    case 's':
        body.front().dir = DIR_DOWN;
        break;
    case 'd':
        body.front().dir = DIR_RIGHT;
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
