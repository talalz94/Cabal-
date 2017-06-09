#pragma once
#include "Barriers.h"
#include <iostream>

class Breakable:public Barriers
{
public:
    Breakable(LTexture*, Point&, int);
    ~Breakable();
    void Render(long int&, SDL_Renderer*);
    bool GetAlive();
};
