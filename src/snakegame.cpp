#include <iostream>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include <thread>
#include "feed.h"
#include "snake.h"

int SCREEN_HEIGHT, SCREEN_WIDTH;
int EATEN_FEED;
time_t START_TIME, END_TIME;

void waitInput(Snake *);
void checkKeyInput(Snake *);

int main(int argc, char *argv[])
{
    initscr();
    noecho();
    refresh();

    EATEN_FEED = 0;
    getmaxyx(stdscr, SCREEN_HEIGHT, SCREEN_WIDTH);
    SCREEN_HEIGHT = 20;
    SCREEN_WIDTH = 20;

    Snake snake;
    Feed feed;

    std::thread waitInputWorker(waitInput, &snake);

    while (true)
    {
        werase(stdscr);
        for (int y = 0; y < SCREEN_HEIGHT; y++)
        {
            for (int x = 0; x < SCREEN_WIDTH; x++)
            {
                for (int i = 0; i < snake.body.size(); i++)
                {
                    if ((y == snake.body.at(i).y) && (x == snake.body.at(i).x))
                    {
                        char icon = snake.icon[snake.body.at(i).dir];
                        mvprintw(y, x, &icon);
                    }
                }
                if ((y == feed.getCoordinate().y) && (x == feed.getCoordinate().x))
                {
                    char feedIcon = feed.getIcon();
                    mvprintw(y, x, &feedIcon);
                }
            }
        }
        refresh();
        if ((snake.body.front().y == feed.getCoordinate().y) && (snake.body.front().x == feed.getCoordinate().x))
        {
            snake.eat(feed);
        }
        snake.move();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    waitInputWorker.join();

    endwin();

    return 0;
}

void waitInput(Snake *snake)
{
    while (true)
    {
        checkKeyInput(snake);
    }
}

void checkKeyInput(Snake *snake)
{
    int keyInput = getch();
    snake->move((char)keyInput);
}
