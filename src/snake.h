#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <vector>
#include <map>
#include "feed.h"

int SCREEN_HEIGHT, SCREEN_WIDTH;

// expression {x,y}
#define DIR_LEFT \
    {            \
        -1, 0    \
    }
#define DIR_RIGHT \
    {             \
        1, 0      \
    }
#define DIR_UP \
    {          \
        0, -1  \
    }
#define DIR_DOWN \
    {            \
        0, 1     \
    }

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

class Snake
{
public:
    std::vector<coordinate> body;
    std::map<direction, std::string> icon;

public:
    Snake();
    ~Snake();
    void eat(Feed feed);
    void move();
    void move(char ch);
    void die();
};

namespace snake
{
    bool isBorder(int x, int y)
    {
        if (x < 0 || x > SCREEN_WIDTH)
            return true;
        if (y < 0 || y > SCREEN_HEIGHT)
            return true;
        return false;
    }

    void showTime(time_t sec)
    {
        std::string h, m, s;
        h = std::to_string(sec / 3600);
        sec %= 3600;
        m = std::to_string(sec / 60);
        sec %= 60;
        s = std::to_string(sec / 3600);
        fprintf(stdout, "survival time: %s:%s:%s(hh:mm:ss)\n", h, m, s);
    }
}

#endif