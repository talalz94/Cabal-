#pragma once
#include "Enemy.h"
#include <iostream>

class Vehicle:public Enemy
{
public:
    Vehicle(LTexture*, Point&, int);
    Vehicle();
    ~Vehicle();
    void Render(long int&, SDL_Renderer*);
    void Move();
    bool GetAlive();
};
