#pragma once
#include "Bullets.h"

class MachineGun:public Bullets
{
public:
    MachineGun(LTexture*, Point&, Point&);
    MachineGun();
    ~MachineGun();
    void Render(long int&, SDL_Renderer*);
    void Move();
    bool GetAlive();
};
