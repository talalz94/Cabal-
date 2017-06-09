#pragma once
#include "Vehicle.h"
#include <iostream>

class Tank:public Vehicle
{
public:
    Tank(LTexture*, Point&, int);
    Tank();
    ~Tank();
    void Render(long int&, SDL_Renderer*);
    void Move();
    bool GetAlive();
};
