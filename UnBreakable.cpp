#include "UnBreakable.h"

UnBreakable::UnBreakable(LTexture* image, float x, float y)
{
    std::cout<<"Unbreakable barrier  created\n";
}

UnBreakable::~UnBreakable()
{
    std::cout<<"Unbreakable barrier destroyed\n";
}

void UnBreakable::Render(long int& frame, SDL_Rendere* gRenderer)
{

}

void UnBreakable::Move()
{

}
void UnBreakable::Move(int direction)
{
    //if (direction==left) blah blah
}

int UnBreakable::GetType()
{
    return type;
}

void UnBreakable::SetAlive(bool alive)
{
    this->alive = alive;
}

bool UnBreakable::GetAlive()
{
    return alive;
}

void UnBreakable::SetPosition(const Point&)
{

}

const Point UnBreakable::GetPosition()
{
    return position;
}
