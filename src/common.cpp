#include <iostream>
#include "common.h"

extern time_t START_TIME, END_TIME;

void showSurvivalTime()
{
    time_t sec = END_TIME - START_TIME;
    std::string h, m, s;

    h = std::to_string(sec / 3600);
    sec %= 3600;
    m = std::to_string(sec / 60);
    sec %= 60;
    s = std::to_string(sec);

    if (h.length() < 2)
    {
        h = '0' + h;
    }
    if (m.length() < 2)
    {
        m = '0' + m;
    }
    if (s.length() < 2)
    {
        s = '0' + s;
    }

    fprintf(stdout, "survival time: %s:%s:%s(hh:mm:ss)\n", h.c_str(), m.c_str(), s.c_str());
}
