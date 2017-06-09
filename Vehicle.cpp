#include "Vehicle.h"

Vehicle::Vehicle()
{

}

Vehicle::Vehicle(LTexture* image, Point& position, int animation):Enemy(image, position, animation)
{

}

Vehicle::~Vehicle()
{

}

void Vehicle::Render(long int& frame, SDL_Renderer* gRenderer)
{

}

void Vehicle::Move()
{

}

bool Vehicle::GetAlive()
{
    return alive;
}
