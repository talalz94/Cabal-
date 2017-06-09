#pragma once
#include "Bullets.h"

class Default:public Bullets                   //Inherits from the Bullets class.
{
public:
    Default(LTexture*, Point&, Point&);
    Default();
    ~Default();
    void Render(long int&, SDL_Renderer*);
    void Move();
    bool GetAlive();
};
