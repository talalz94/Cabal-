#pragma once
#include "Unit.h"
#include <iostream>

class HealthBar:public Unit
{
public:
    HealthBar(LTexture*, int, int);
    HealthBar();
    ~HealthBar();
    void Render(long int&, SDL_Renderer*);
    void Move(int);
    bool GetAlive();
};


