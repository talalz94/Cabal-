#include "MachineGun.h"
#include <math.h>


MachineGun::MachineGun()
{

}

MachineGun::MachineGun(LTexture* image, Point& departure, Point& destination)
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

    type=12;
    speedx = 15;
    speedy = 15;
    alive  = true;
    moves=0;

    angle = (atan2(destination.x - position.x, position.y - destination.y  ) ) - (3.14/2) ;
}


MachineGun::~MachineGun()
{
    std::cout<<"MachineGun deallocated\n";
}

void MachineGun::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[0], 0.0, NULL, SDL_FLIP_VERTICAL, gRenderer );
}

void MachineGun::Move()
{
    position.x += speedx*cos(angle);
    position.y += speedx*sin(angle);

}

bool MachineGun::GetAlive()
{
    if (position.y<200)
    {
        alive=false;
    }
    return alive;
}
