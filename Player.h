#pragma once
#include "Unit.h"
#include "HealthBar.h"
#include <iostream>

class Player:public Unit
{
 private:
     Unit* healthbar=NULL;
public:
    Player(LTexture*, LTexture*, int, Point&);
    Player();
    ~Player();
    void Render(long int&, SDL_Renderer*);
    void Move(int);
    bool GetAlive();
};
