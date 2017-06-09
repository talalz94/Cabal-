#pragma once
#include "Barriers.h"
#include <iostream>

class UnBreakable:public Barriers
{
public:
    UnBreakable(LTexture*, float, float);
    ~UnBreakable();
    void Render(long int&, SDL_Renderer*);
    int GetType();
    void SetAlive(bool);
    bool GetAlive();
    void SetPosition(const Point&);
    const Point GetPosition();
};
