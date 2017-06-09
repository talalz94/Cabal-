#include "Default.h"
#include <math.h>


Default::Default()
{

}

Default::Default(LTexture* image, Point& departure, Point& destination)
{
    spriteSheetTexture = image;
    //Frame 0
    clips[0].x = 3;                      //sprite of the bullet represents it's image
    clips[0].y = 3;
    clips[0].w = 5;
    clips[0].h = 6;

    this->position = departure;         // initial co-ordinates of the bullet
    this->destination = destination;    // target co-ordinates of the bullet where the LMB is clicked.
    this->initial=departure;

    this->width = clips[0].w;
    this->height = clips[0].h;

    type=11;                              //type of bullet, to differentiate it from other objects in queue.
    speedx = 10;                          //speed is constant for all bullets
    speedy = 10;
    alive  = true;
    moves=0;
    //angle the bullet makes with it target.
    angle = (atan2(destination.x - position.x, position.y - destination.y  ) ) - (3.14/2) ;
}


Default::~Default()
{
    std::cout<<"Default deallocated\n";
}

void Default::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[0], 0.0, NULL, SDL_FLIP_VERTICAL, gRenderer );
}

void Default::Move()                            //The movement of the bullet depends upon the angle the bullet
{                                               //makes with the target. This makes the speed of bullet independent
    position.x += speedx*cos(angle);            //of the distance.
    position.y += speedx*sin(angle);

}

bool Default::GetAlive()                        //If the bullet is above this line, it is deallocated from queue.
{
    if (position.y<200)
    {
        alive=false;
    }
    return alive;
}
