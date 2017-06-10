#pragma once
#include "Bullets.h"

class Default:public Bullets
{
public:
    Default(LTexture*, Point&, Point&);
    Default();
    ~Default();
    void Render(long int&, SDL_Renderer*);
    void Move();
    bool GetAlive();
};
