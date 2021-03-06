#pragma once
#include "Bullets.h"
#include <math.h>
#include <cmath>


class Missiles:public Bullets
{
public:
    Missiles(LTexture*, Point&, Unit*);
    Missiles();
    ~Missiles();
    void Render(long int&, SDL_Renderer*);
    void Move();
    bool GetAlive();
};
