#include <iostream>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include <thread>
#include "snake.h"

int SCREEN_HEIGHT, SCREEN_WIDTH;
int EATEN_FEED;
time_t START_TIME, END_TIME;
Snake snake;

void waitInput();
void checkKeyInput();

int main(int argc, char *argv[])
{
    initscr();
    noecho();

    EATEN_FEED = 0;
    getmaxyx(stdscr, SCREEN_HEIGHT, SCREEN_WIDTH);
    SCREEN_HEIGHT = 10;
    SCREEN_WIDTH = 10;

    std::thread waitInputWorker(waitInput);

    while (true)
    {
        for (int y = 0; y < SCREEN_HEIGHT; y++)
        {
            for (int x = 0; x < SCREEN_WIDTH; x++)
            {
                if ((y == snake.body.front().y) && (x == snake.body.front().x))
                {
                    mvprintw(y, x, &snake.icon["right"]);
                }
                else
                {
                    mvprintw(y, x, ".");
                }
            }
        }
        refresh();
        snake.move();
        sleep(1);
    }

    waitInputWorker.join();

    endwin();

    return 0;
}

void waitInput()
{
    while (true)
    {
        checkKeyInput();
    }
}

void checkKeyInput()
{
    int keyInput = getch();
    snake.move((char)keyInput);
}
