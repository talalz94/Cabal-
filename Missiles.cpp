#include "Missiles.h"

Missiles::Missiles()
{

}

Missiles::Missiles(LTexture* image, Point& departure, Unit* target)
{
    spriteSheetTexture = image;
    //Frame 0
    clips[0].x = 8;
    clips[0].y = 1;
    clips[0].w = 30;
    clips[0].h = 16;

    clips[1].x = 42;
    clips[1].y = 1;
    clips[1].w = 34;
    clips[1].h = 16;

    clips[2].x = 78;
    clips[2].y = 1;
    clips[2].w = 35;
    clips[2].h = 16;

    clips[3].x = 114;
    clips[3].y = 1;
    clips[3].w = 36;
    clips[3].h = 16;

    clips[4].x = 0;
    clips[4].y = 18;
    clips[4].w = 38;
    clips[4].h = 16;

    clips[5].x = 38;
    clips[5].y = 18;
    clips[5].w = 38;
    clips[5].h = 16;

    clips[6].x = 76;
    clips[6].y = 18;
    clips[6].w = 38;
    clips[6].h = 16;

    clips[7].x = 113;
    clips[7].y = 18;
    clips[7].w = 39;
    clips[7].h = 16;

    this->position = departure;         //initial co-ordinates of missile
    initial=departure;                  //target co-ordinates of player.
    this->target = target;
    this->width = clips[0].w;
    this->height = clips[0].h;

    type=13;
    friction = 1.02f;                   //used to accelerate speed of missile
    speedx = 5;
    speedy = 3;
    alive  = true;
    moves=0;                            //used in sprite animation
    ratioo=0;
    health=1;                           //determines damage of health to player

}


Missiles::~Missiles()
{
    std::cout<<"Missiles destroyed\n";
}

void Missiles::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[0+moves%7], ratioo, NULL, SDL_FLIP_VERTICAL, gRenderer );
    moves++;
}

void Missiles::Move()
{
    angle =atan2(target->Getx() - position.x, position.y);         //angle changes with the change with player.

    speedx=speedy*sin(angle)*3;                                    // speed in the x-direction

    position.x+=speedx;                                            //movement of missile in x-direction

    speedy = (speedy * friction) ;                                 //speed in y-direction
    position.y+=(speedy);                                          // movement in y-direction

    ratioo=90*((float)position.x/(float)target->Getx());           //ratioo determine the rotation of missile head
    if (ratioo > 170)
    {
        ratioo = 170;
    }

    if (ratioo < 0)
    {
        ratioo = 0;
    }


}

bool Missiles::GetAlive()
{
    if (position.y>640 || health==0)   //When missile goes out of the screen, it disappears
    {
        alive=false;
    }
    return alive;
}
