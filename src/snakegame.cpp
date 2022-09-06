#include <iostream>
#include <ncurses.h>
#include <time.h>
#include "snake.h"

int SCREEN_HEIGHT, SCREEN_WIDTH;
int EATEN_FEED;
time_t START_TIME, END_TIME;

int main(int argc, char *argv[])
{
    initscr();
    EATEN_FEED = 0;
    getmaxyx(stdscr, SCREEN_HEIGHT, SCREEN_WIDTH);

    Snake snake;
    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            mvprintw(x, y, snake.icon[snake.body.front().dir].c_str());
        }
    }

    refresh();

    endwin();

    return 0;
}
