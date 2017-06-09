#pragma once
#include "Foots.h"
#include <iostream>

class Commando:public Foots
{
public:
    Commando(LTexture*, Point&, int);
    Commando();
    ~Commando();
    void Render(long int&, SDL_Renderer*);
    void Move();
    bool GetAlive();
};
