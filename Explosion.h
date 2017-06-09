#pragma once
#include "Unit.h"
#include <iostream>

class Explosion:public Unit
{
public:
    Explosion(LTexture*, Point&, int);
    Explosion();
    ~Explosion();
    void Render(long int&, SDL_Renderer*);
    bool GetAlive();
};

