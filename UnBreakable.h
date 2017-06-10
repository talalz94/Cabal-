#pragma once
#include "Barriers.h"
#include <iostream>

class UnBreakable:public Barriers
{
public:
    UnBreakable();
    UnBreakable(LTexture*, Point&, int);
    ~UnBreakable();
    void Render(long int&, SDL_Renderer*);
    bool GetAlive();
};
