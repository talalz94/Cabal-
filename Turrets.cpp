#include "Turrets.h"

Turrets::Turrets(LTexture* image ,Point& position, Unit* target)   //In This constructor I am calling function image of turret,positions and player's position.
{
    spriteSheetTexture = image;

    //Frame 0                   This sprite is for the image of turret which is pointing on left side
    clips[0].x =   415;
    clips[0].y =   93;
    clips[0].w = 45;
    clips[0].h = 45;

    //Frame 1                  This sprite is for the image of turret which is pointing between the left and center
    clips[1].x =   464;
    clips[1].y =   93;
    clips[1].w = 31;
    clips[1].h = 45;

    //Frame 2                  This sprite is for the image of turret which is pointing in the center
    clips[2].x =   502;
    clips[2].y =   93;
    clips[2].w = 26;
    clips[2].h = 45;

    //Frame 3                This sprite is for the image of turret which is pointing between the center and right
    clips[3].x =   535;
    clips[3].y =   93;
    clips[3].w = 27;
    clips[3].h = 45;

    //Frame 4               This sprite is for the image of turret which is pointing to right.
    clips[4].x =   570;
    clips[4].y =   93;
    clips[4].w = 45;
    clips[4].h = 45;
    this->position =position;           //using pointer to refer position
    this->target = target;              //referring pointer of player
    this->width = clips[0].w;
    this->height = clips[0].h;

    //friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;
    moves=0;
}

Turrets::~Turrets()             //calling deconstructor of turret
{
    std::cout<<"Turrets destroyed\n";
}

void Turrets::Render(long int& frame, SDL_Renderer* gRenderer)    //calling render function of turret.
{
    spriteSheetTexture->Render( position.x, position.y, &clips[moves], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

    if ( target->Getx() < position.x - 200)    //here I am making condition to detect player's location with .
    {
        moves=0;                               //if player's position is less than 200 from boss and turret's location then it will show turret with left.


    }
    else if ( target->Getx() >= position.x - 200 && target->Getx() < position.x - 100)   //if player's position is greater than -200 and less than -100 from boss and turret's location then it will show turret with left.
    {
        moves=1;
    }
    else if (target->Getx() > position.x-100 && target->Getx() < position.x+100)        //if player's position is greater than -100 and less than +100 from boss and turret's location then it will show turret with center.
    {
        moves=2;
    }
    else if (target->Getx() >= position.x+ 100 && target->Getx()< position.x + 200)    //if player's position is greater than +100 and less than +200 from boss and turret's location then it will show turret with right.
    {
        moves=3;
    }
    else if (target->Getx() >= position.x+ 200)    ////if player's position is greater than +200 from boss and turret's location then it will show turret with right.
    {
        moves=4;
    }

}

void Turrets::Move(int x, int y)            //This is my move function in which I am defining location of turret as location of boss.
{
    this->position.x=x;
    this->position.y=y;
}



bool Turrets::GetAlive()
{
    return alive;
}
