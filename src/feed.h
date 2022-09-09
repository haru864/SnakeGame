#ifndef _FEED_H_
#define _FEED_H_

#define FEED_ICON '#'

#include "common.h"

class Feed
{
private:
    coordinate coord;
    char icon;

public:
    Feed();
    ~Feed();
    void birth();
    coordinate getCoordinate();
    void setCoordinate(int x, int y);
    char getIcon();
    void setIcon(char ch);
    bool isAvailableCoord(int x, int y);
};

#endif