#pragma once
#include "Enemy.h"
#include"Boss.h"
#include <iostream>

class Turrets:public Enemy
{
protected:
    int counter;
    Unit* target=NULL;
public:
    Turrets(LTexture*,Point&, Unit*);
    ~Turrets();
    void Render(long int&, SDL_Renderer*);
    void Move(int, int);
    bool GetAlive();
};
