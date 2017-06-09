#pragma once
#include "Unit.h"
#include <iostream>

class Powerups:public Unit
{
public:
    Powerups(LTexture*, Point&, int);
    Powerups();
    ~Powerups();
    void Render(long int&, SDL_Renderer*);
    void Move();
    bool GetAlive();
};
