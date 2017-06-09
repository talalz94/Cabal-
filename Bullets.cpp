#include "Bullets.h"

Bullets::Bullets()
{

}

Bullets::Bullets(LTexture* image, Point& departure, Unit* target):Unit(image, departure)
{

}


Bullets::~Bullets()
{

}

void Bullets::Render(long int& frame, SDL_Renderer* gRenderer)
{

}

void Bullets::Move()
{

}

bool Bullets::GetAlive()
{
    return alive;
}
