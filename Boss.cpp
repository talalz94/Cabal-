#include "Boss.h"

Boss::Boss()
{

}

Boss::Boss(LTexture* image, LTexture* healthimage, Point& position,Unit* target)
{
    spriteSheetTexture = image;

    clips[ 0 ].x = 415;
    clips[ 0 ].y = 0;
    clips[ 0 ].w = 180;
    clips[ 0 ].h = 90;

    this->position = position;

    this->width = clips[0].w;
    this->height = clips[0].h;

    type=5;
    speedx = 2;
    speedy = 0;
    alive  = true;
    moves=0;

    health=15;
    fire=0;
    t1  = new Turrets(image,position,target);
    c = 0;
    healthbar = new HealthBar(healthimage, health, BOSS);
}

Boss::~Boss()
{
    spriteSheetTexture = NULL;
    std::cout<<"Boss deallocated\n";
}

void Boss::Render(long int& frame, SDL_Renderer* gRenderer)
{
    t1->Render(frame, gRenderer);
    spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    healthbar->Move(health);
    healthbar->Render(frame,gRenderer);

}

void Boss::Move(long int& frame)
{
    if (frame%300==0)
    {
        fire=1;
    }
    else
    {
        fire=0;
    }
    c++;
    //std::cout<<"c: "<<c<<"\n";
                                                        // Set vertical speed
    position.x+=speedx;
    position.y+=speedy;

    if (position.x==550 && position.y == 320)
    {
        speedx = 0;

        if (c > 400)
        {
            speedx=2;
            c=0;
        }
    }

    if (position.x == 900 && position.y == 320)
    {
        speedx =0;

        if (c > 220)
        {
            speedy=1;
            c=0;
        }
    }

    if (position.x == 900 && position.y == 330)
    {
        speedy=0;

        if (c > 300)
        {
            speedx=-2;
            c=0;
        }
    }

    if (position.x == 550 && position.y == 330)
    {
        speedx=0;

        if (c > 200)
        {
            speedy=5;
            c=0;
        }
    }

    if (position.x == 550 && position.y == 550)
    {
        speedx=0;

        if (c > 20)
        {
            speedy=-2;
            c=0;
        }
    }


    if (position.x == 550 && position.y == 320)
    {
        speedy=0;

        if (c > 300)
        {
            speedx=2;
            c=0;
        }
    }

    t1->Move( position.x + 27,position.y - 60);
}

bool Boss::GetAlive()
{
    if (health==0)
    {
        alive=false;
    }
    return alive;
}
