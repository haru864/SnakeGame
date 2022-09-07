#ifndef _FEED_H_
#define _FEED_H_

#include "common.h"
#include "snake.h"

class Feed
{
private:
    coordinate coord;

public:
    Feed();
    ~Feed();
    void birth();
};

#endif