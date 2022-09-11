#include <random>
#include "feed.h"
#include "snake.h"

extern int SCREEN_HEIGHT, SCREEN_WIDTH;
extern Snake *snakeAddr;

Feed::Feed()
{
    birth();
    setIcon(FEED_ICON);
}

Feed::~Feed()
{
}

void Feed::birth()
{
    std::random_device rnd;
    unsigned long new_x;
    unsigned long new_y;

    do
    {
        new_x = rnd() % (SCREEN_WIDTH);
        new_y = rnd() % (SCREEN_HEIGHT);
    } while (!isAvailableCoord(new_x, new_y));

    setCoordinate(new_x, new_y);
}

coordinate Feed::getCoordinate()
{
    return coord;
}

void Feed::setCoordinate(int x, int y)
{
    coord.x = x;
    coord.y = y;
    coord.dir = {0, 0};
}

char Feed::getIcon()
{
    return icon;
}

void Feed::setIcon(char ch)
{
    icon = ch;
}

bool Feed::isAvailableCoord(int x, int y)
{
    if ((x == getCoordinate().x) && (y == getCoordinate().y))
    {
        return false;
    }
    if ((x >= SCREEN_WIDTH) || (x < 0) || (y >= SCREEN_HEIGHT) || (y < 0))
    {
        return false;
    }
    for (int i = 0; i < snakeAddr->body.size(); i++)
    {
        if (x == snakeAddr->body.at(i).x && y == snakeAddr->body.at(i).y)
        {
            return false;
        }
    }
    return true;
}
