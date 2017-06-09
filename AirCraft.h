#pragma once
#include "Vehicle.h"
#include <iostream>

class AirCraft:public Vehicle
{
public:
    AirCraft(LTexture*, Point&, int);
    AirCraft();
    ~AirCraft();
    void Render(long int&, SDL_Renderer*);
    void Move();
    bool GetAlive();
};
