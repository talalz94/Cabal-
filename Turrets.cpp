#include "Turrets.h"

Turrets::Turrets(LTexture* image ,Point& position, Unit* target)
{
    spriteSheetTexture = image;

    //Frame 0
    clips[0].x =   415;
    clips[0].y =   93;
    clips[0].w = 45;
    clips[0].h = 45;

    //Frame 1
    clips[1].x =   464;
    clips[1].y =   93;
    clips[1].w = 31;
    clips[1].h = 45;

    //Frame 2
    clips[2].x =   502;
    clips[2].y =   93;
    clips[2].w = 26;
    clips[2].h = 45;

    //Frame 3
    clips[3].x =   535;
    clips[3].y =   93;
    clips[3].w = 27;
    clips[3].h = 45;

    //Frame 4
    clips[4].x =   570;
    clips[4].y =   93;
    clips[4].w = 45;
    clips[4].h = 45;
    this->position =position;
    this->target = target;
    this->width = clips[0].w;
    this->height = clips[0].h;

    //friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;
    counter=0;
    moves=0;
}

Turrets::~Turrets()
{
    std::cout<<"Turrets destroyed\n";
}

void Turrets::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( position.x, position.y, &clips[moves], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

    if ( target->Getx() < position.x - 200)
    {
        moves=0;


    }
    else if ( target->Getx() >= position.x - 200 && target->Getx() < position.x - 100)
    {
        moves=1;


    }
//    else if (target->Getx()>=200 && target->Getx()<400)
//    {
//        moves=1;
//    }
    else if (target->Getx() > position.x-100 && target->Getx() < position.x+100)
    {
        moves=2;
    }
//    else if (target->Getx()>=600 && target->Getx()<800)
//    {
//        moves=3;
//    }
    else if (target->Getx() >= position.x+ 100 && target->Getx()< position.x + 200)
    {
        moves=3;
    }
    else if (target->Getx() >= position.x+ 200)
    {
        moves=4;
    }

}

void Turrets::Move(int x, int y)
{
    this->position.x=x;
    this->position.y=y;
}



bool Turrets::GetAlive()
{
    return alive;
}
