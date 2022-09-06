#include <iostream>
#include <ncurses.h>
#include "snake.h"

extern int EATEN_FEED;
extern time_t START_TIME, END_TIME;

Snake::Snake()
{
    // go to right at first
    direction dir = DIR_RIGHT;
    coordinate coord = {0, 0, dir};
    body.push_back(coord);

    // set head, body icon
    icon[DIR_LEFT] = "<";
    icon[DIR_RIGHT] = ">";
    icon[DIR_UP] = "^";
    icon[DIR_DOWN] = "v";
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
    // head movement
    body.at(0).x += body.at(0).dir.x;
    body.at(0).y += body.at(0).dir.y;
    if (snake::isBorder(body.at(0).x, body.at(0).y))
    {
        die();
    }

    // body movement
}

void Snake::move(char ch)
{
    direction prevDir;
    prevDir.x = body.at(0).x;
    prevDir.y = body.at(0).y;

    switch (ch)
    {
    case 'w':
        body.at(0).dir = DIR_UP;
        break;
    case 'a':
        body.at(0).dir = DIR_LEFT;
        break;
    case 's':
        body.at(0).dir = DIR_RIGHT;
        break;
    case 'd':
        body.at(0).dir = DIR_DOWN;
        break;
    default:
        break;
    }

    if ((prevDir.x == body.at(0).x) && ((prevDir.y == body.at(0).y)))
    {
        die();
    }
}

void die()
{
    endwin();
    fprintf(stdout, "feeds: %d\n", EATEN_FEED);
    snake::showTime(END_TIME - START_TIME);
    fflush(stdout);
    exit(0);
}
