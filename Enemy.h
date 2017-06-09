#pragma once
#include "Unit.h"
#include "Bullets.h"
#include <iostream>

class Enemy:public Unit
{
public:
    Enemy(LTexture*, Point&, int);
    Enemy();
    ~Enemy();
    void Render(long int&, SDL_Renderer*);
    void Move();
    bool GetAlive();
};

