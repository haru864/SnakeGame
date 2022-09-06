#ifndef _FEED_H_
#define _FEED_H_

typedef struct coordinate
{
    int x;
    int y;
} coordinate;

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