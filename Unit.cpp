#include "Unit.h"

Unit::Unit()
{

}

Unit::Unit(LTexture* image, const Point& position)
{
    spriteSheetTexture = image;
    this->position = position;
}

Unit::~Unit()
{

}

void Unit::Render(long int& frame, SDL_Renderer* gRenderer)
{

}

void Unit::Move()
{

}

void Unit::Move(int direction)
{

}

void Unit::Move(int x, int y)
{

}

void Unit::Move(long int& frame)
{

}

int Unit::GetType()
{
    return type;
}

void Unit::SetAlive(bool alive)
{
    this->alive=alive;
}

bool Unit::GetAlive()
{
    return alive;
}

void Unit::SetPosition(Point& position)
{
    this->position.x=position.x;
    this->position.y=position.y;
}

Point Unit::GetPosition()
{
    return position;
}

void Unit:: SetState(int animation)
{
    moves=0;
    this->animation=animation;
}

int Unit::GetState()
{
    return animation;
}

int Unit::Getx()
{
    return position.x;
}

int Unit::Gety()
{
    return position.y;
}

void Unit::SetHealth(int health)
{
    this->health+=health;
}

int Unit::GetHealth()
{
    return health;
}

int Unit::top()
{
    return position.y-height/2;
}
int Unit::bottom()
{
    return position.y+height/2;
}
int Unit::left()
{
    return position.x-width/2;
}

int Unit::right()
{
    return position.x+width/2;
}

int Unit::Attack()
{
    return fire;
}

void Unit::Setfire(int fire)
{
    this->fire=fire;
}
