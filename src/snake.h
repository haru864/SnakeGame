#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <vector>
#include <map>
#include "common.h"
#include "feed.h"

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

class Snake
{
public:
    std::vector<coordinate> body;
    std::map<direction, char> icon;

public:
    Snake();
    ~Snake();
    void eat(Feed &);
    void grow();
    void move();
    void move(char);
    void die();
    bool isBorder();
    bool isOverlap();
};

#endif