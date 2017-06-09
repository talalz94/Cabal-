#include "Powerups.h"

Powerups::Powerups()
{

}

Powerups::Powerups(LTexture* image, Point& position, int power):Unit(image, position)
{
    this->animation = animation;
    //HEALTH
    clips[0].x = 33;
    clips[0].y = 7;
    clips[0].w = 42;
    clips[0].h = 42;

    //SCORE
    clips[1].x = 188;
    clips[1].y = 7;
    clips[1].w = 41;
    clips[1].h = 42;

    this->position = position;

    this->width = clips[0].w;
    this->height = clips[0].h;

    speedx = 0;
    speedy = 0;
    alive  = true;
    moves=power;
    type=power+50;
    std::cout<<power<<"\n";
}

Powerups::~Powerups()
{
    spriteSheetTexture = NULL;
    std::cout<<"Powerups deallocated\n";
}

void Powerups::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[moves], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void Powerups::Move()
{
    if (position.y>=595)
    {
        speedy=0;
    }
    else
    {
        speedy=3;
    }
    position.y+=speedy;
}

bool Powerups::GetAlive()
{
    delay++;
    if (delay==400)
    {
        alive=false;
    }
    return alive;
}
