#include "Breakable.h"

Breakable::Breakable(LTexture* image, Point& position, int state)
{

}

Breakable::~Breakable()
{
    std::cout<<"Breakable deallocated\n";
}

void Breakable::Render(long int& frame, SDL_Renderer* gRenderer)
{

}

bool Breakable::GetAlive()
{
    return alive;
}
