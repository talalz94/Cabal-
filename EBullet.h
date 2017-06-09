#pragma once
#include "Bullets.h"

class EBullet:public Bullets
{
public:
    EBullet(LTexture*, Point&, Point&);
    EBullet();
    ~EBullet();
    void Render(long int&, SDL_Renderer*);
    void Move();
    bool GetAlive();
};
