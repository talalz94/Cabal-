#include "Default.h"
#include <math.h>


Default::Default()
{

}

Default::Default(LTexture* image, Point& departure, Point& destination)
{
    spriteSheetTexture = image;
    //Frame 0
    clips[0].x = 3;
    clips[0].y = 3;
    clips[0].w = 5;
    clips[0].h = 6;

    this->position = departure;
    this->destination = destination;
    this->initial=departure;

    this->width = clips[0].w;
    this->height = clips[0].h;

    type=11;
    speedx = 10;
    speedy = 10;
    alive  = true;
    moves=0;
}


Default::~Default()
{
    std::cout<<"Default deallocated\n";
}

void Default::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[0], 0.0, NULL, SDL_FLIP_VERTICAL, gRenderer );
}

void Default::Move()
{
    position.x += speedx*cos(angle);
    position.y += speedx*sin(angle);

}

bool Default::GetAlive()
{
    if (position.y<200)
    {
        alive=false;
    }
    return alive;
}
