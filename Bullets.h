#pragma once
#include "Unit.h"

class Bullets:public Unit      //inherits from Unit class. Itself is a base class.
{
protected:
    int ratioo;               //used to calculate rotation of missiles
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
