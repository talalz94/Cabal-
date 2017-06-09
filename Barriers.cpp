#include "Barriers.h"

Barriers::Barriers()
{

}

Barriers::Barriers(LTexture* image, Point& position, int state):Enemy(image, position, state)
{

}


Barriers::~Barriers()
{

}

void Barriers::Render(long int& frame, SDL_Renderer* gRenderer)
{

}

bool Barriers::GetAlive()
{
    return alive;
}
