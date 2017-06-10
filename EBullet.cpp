
#include "EBullet.h"
#include <math.h>


EBullet::EBullet()
{

}

EBullet::EBullet(LTexture* image, Point& departure, Point& destination)
{
    spriteSheetTexture = image;         //sprite sheet is loaded for bullets
    //Frame 0                           //image is clipped according to certain dimensions
    clips[0].x = 11;
    clips[0].y = 3;
    clips[0].w = 6;
    clips[0].h = 6;

    this->position = departure;             //position is given from where the bullet originates
    this->destination = destination;        //position where the bullet ends up
    this->initial=departure;

    this->width = clips[0].w;               //width of a bullet
    this->height = clips[0].h;              //height of a bullet

    type=14;
    speedx = 3;                               //speed in x-axis
    speedy = 3;                               //speed in y-axis
    alive  = true;
    moves=0;
    health=1;

    angle = (atan2(destination.x - position.x, position.y - destination.y  ) ) - (3.14/2) ;
}


EBullet::~EBullet()
{
    std::cout<<"EBullet destroyed\n";
}

void EBullet::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[0], 0.0, NULL, SDL_FLIP_VERTICAL, gRenderer );
}

void EBullet::Move()
{
    position.x += speedx*cos(angle);
    position.y += speedx*sin(angle);
}

bool EBullet::GetAlive()
{
    if (position.y>640 || health==0)
    {
        alive=false;
    }
    return alive;
}
