#pragma once
#include "Unit.h"

class Bullets:public Unit
{
protected:
    int ratioo;
    Unit* target;
    Point initial;
    Point destination;
    float angle;
public:
    Bullets(LTexture*, Point&, Unit*);
    Bullets();
    ~Bullets();
    void Render(long int&, SDL_Renderer*);
    void Move();
    bool GetAlive();
};
