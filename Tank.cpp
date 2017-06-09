#include "Tank.h"

Tank::Tank()
{

}

Tank::Tank(LTexture* image, Point& position, int animation):Vehicle(image, position, animation)
{
    //Frame 0
    clips[ 0 ].x = 3;
    clips[ 0 ].y = 3;
    clips[ 0 ].w = 85;
    clips[ 0 ].h = 67;

    //Frame 1
    clips[ 1 ].x = 98;
    clips[ 1 ].y = 4;
    clips[ 1 ].w = 85;
    clips[ 1 ].h = 69;

    //Frame 2
    clips[ 2 ].x = 199;
    clips[ 2 ].y = 8;
    clips[ 2 ].w = 85;
    clips[ 2 ].h = 67;

    //Frame 3
    clips[ 3 ].x = 299;
    clips[ 3 ].y = 7;
    clips[ 3 ].w = 77;
    clips[ 3 ].h = 67;

    //Frame 4
    clips[ 4 ].x = 390;
    clips[ 4 ].y = 7;
    clips[ 4 ].w = 99;
    clips[ 4 ].h = 64;

    this->position = position;

    this->width = clips[0].w;
    this->height = clips[0].h;

    this->type=4;
    speedx = 0;
    speedy = 0;
    alive  = true;
    moves=0;

    health=3;
    fire=0;
}

Tank::~Tank()
{
    spriteSheetTexture = NULL;
    std::cout<<"Tank deallocated\n";
}

void Tank::Render(long int& frame, SDL_Renderer* gRenderer)
{
    if(animation== IDLE)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[3], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    else if(animation== MOVE_LEFT)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[0 + moves%3], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        if (frame%12==0)
        {
            moves++;
        }
    }
    else if(animation== MOVE_RIGHT)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[0 + moves%3], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );

        if (frame%12==0)
        {
            moves++;
        }
    }

    else if(animation == DIE)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[4], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );

        if (frame%100==0)
        {
            alive=false;
        }
    }
}

void Tank::Move()
{
    if (animation==MOVE_LEFT)
    {
        speedx = -2;
    }
    else if (animation==MOVE_RIGHT)
    {
        speedx = 2;
    }
    else if(animation==DIE)
    {
        speedx=0;
    }
    if (animation!=IDLE)
    {
        position.x+=speedx;
    }
    if (fire==0)
    {
        if (position.x>400 && position.x<450)
        {
            SetState(IDLE);
            fire=1;
        }
        else if (position.x<700 && position.x>650)
        {
            SetState(IDLE);
            fire=1;
        }
    }
    if (fire==-1)
    {
        delay++;
    }

    if(delay>30)
    {
        if (animation==IDLE)
        {
            delay = 0;
            if (position.x>400 && position.x<450)
            {
                SetState(MOVE_LEFT);
                fire=-1;
            }
            else if (position.x<700 && position.x>650)
            {
                SetState(MOVE_RIGHT);
                fire=-1;
            }
        }
    }
}

bool Tank::GetAlive()
{
    if (position.x<0 && animation==MOVE_LEFT)
    {
        alive=false;
    }
    else if (position.x>1024 && animation==MOVE_RIGHT)
    {
        alive=false;
    }
    if (health==0)
    {
        health=-1;
        SetState(DIE);
    }
    return alive;
}
