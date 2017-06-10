#include "Powerups.h"

Powerups::Powerups()
{

}

Powerups::Powerups(LTexture* image, Point& position, int power):Unit(image, position)
{
    this->animation = power;
    //HEALTH                //these are the sprites of health and score.
    clips[0].x = 33;
    clips[0].y = 7;
    clips[0].w = 42;
    clips[0].h = 42;

    //SCORE
    clips[1].x = 188;
    clips[1].y = 7;
    clips[1].w = 41;
    clips[1].h = 42;

    this->position = position;          //positions in coordinates

    this->width = clips[0].w;
    this->height = clips[0].h;

    speedx = 0;
    speedy = 0;
    alive  = true;
    moves=power;
    type=power+50;
    std::cout<<power<<"\n";
}

Powerups::~Powerups()           //deconstructor
{
    spriteSheetTexture = NULL;
    std::cout<<"Powerups deallocated\n";
}

void Powerups::Render(long int& frame, SDL_Renderer* gRenderer)         //Render function for power ups
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[moves], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

void Powerups::Move()       //move function for power ups.
{
    if (position.y>=595)     // here I am giving location for power ups.
    {
        speedy=0;
    }
    else
    {
        speedy=3;
    }
    position.y+=speedy;
}

bool Powerups::GetAlive()    //Here It is seeing a delay that if power ups are not taken then it will end.
{
    delay++;
    if (delay==400)
    {
        alive=false;
    }
    return alive;
}
