#pragma once

struct Point
{
    int x;
    int y;

    Point()
    {
        x=y=0;
    }

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    bool operator==(const Point& p1)
    {
        bool result = false;

        if(x == p1.x && y == p1.y)
        {
            result = true;
        }

        return result;
    }
};
