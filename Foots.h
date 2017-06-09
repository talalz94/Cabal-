#pragma once
#include "Enemy.h"
#include <iostream>

class Foots:public Enemy
{
public:
    Foots(LTexture*, Point&, int);
    Foots();
    ~Foots();
    void Render(long int&, SDL_Renderer*);
    void Move();
    bool GetAlive();
};
