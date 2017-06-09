#pragma once
#include "Enemy.h"

class Barriers:public Enemy
{
public:
    Barriers(LTexture*, Point&, int);
    Barriers();
    ~Barriers();
    void Render(long int&, SDL_Renderer*);
    bool GetAlive();
};
