#pragma once
#include "Foots.h"
#include <iostream>

class Soldier:public Foots
{
public:
    Soldier(LTexture*, Point&, int);
    Soldier();
    ~Soldier();
    void Render(long int&, SDL_Renderer*);
    void Move();
    bool GetAlive();
};
