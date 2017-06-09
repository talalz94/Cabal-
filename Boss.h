#pragma once
#include "Enemy.h"
#include"Turrets.h"
#include"Unit.h"
#include "HealthBar.h"
#include <iostream>

class Boss:public Enemy
{
protected:
    Unit* t1;
    int c;
    Unit* healthbar=NULL;
public:
    Boss(LTexture*, LTexture*, Point&, Unit* target);
    Boss();
    ~Boss();
    void Render(long int&, SDL_Renderer*);
    bool GetAlive();
    void Move(long int&);
};
