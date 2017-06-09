#include "Foots.h"

Foots::Foots()
{

}

Foots::Foots(LTexture* image, Point& position, int animation):Enemy(image, position, animation)
{
    delay = 0;
}

Foots::~Foots()
{

}

void Foots::Render(long int& frame, SDL_Renderer* gRenderer)
{

}

void Foots::Move()
{

}

bool Foots::GetAlive()
{
    return alive;
}
