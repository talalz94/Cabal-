#include "Commando.h"

Commando::Commando()
{

}

Commando::Commando(LTexture* image, Point& position, int animation):Foots(image, position, animation)
{
    //image->SetScale(position.y);

    //IDLE                              //Different images are clipped from the spritesheet to perform animation
    clips[0].x =  9;
    clips[0].y =  5;
    clips[0].w = 26;
    clips[0].h = 57;

    //WALK
    clips[1].x = 223;
    clips[1].y = 6;
    clips[1].w = 51;
    clips[1].h = 55;

    clips[2].x = 173;
    clips[2].y = 7;
    clips[2].w = 45;
    clips[2].h = 54;

    clips[3].x = 126;
    clips[3].y = 7;
    clips[3].w = 42;
    clips[3].h = 55;

    clips[4].x = 84;
    clips[4].y = 6;
    clips[4].w = 35;
    clips[4].h = 56;

    clips[5].x = 36;
    clips[5].y = 5;
    clips[5].w = 43;
    clips[5].h = 57;

    //SHOOT
    clips[6].x = 314;
    clips[6].y = 5;
    clips[6].w = 45;
    clips[6].h = 57;

    //DIE
    clips[7].x = 6;
    clips[7].y = 74;
    clips[7].w = 44;
    clips[7].h = 50;

    clips[8].x = 58;
    clips[8].y = 74;
    clips[8].w = 39;
    clips[8].h = 50;

    clips[9].x = 106;
    clips[9].y = 74;
    clips[9].w = 54;
    clips[9].h = 50;

    clips[10].x = 166;
    clips[10].y = 74;
    clips[10].w = 59;
    clips[10].h = 50;

    this->position = position;

    this->width = clips[0].w;
    this->height = clips[0].h;

    this->type=1;
    speedx = 0;             //Speed in x-axis
    speedy = 0;             //Speed in y-axis
    alive  = true;
    moves=0;

    health=2;               //health is set
    fire=0;
    //std::cout<<(position.y)<<"\n";
}

Commando::~Commando()
{
    spriteSheetTexture = NULL;
    std::cout<<"Commando deallocated\n";
}

void Commando::Render(long int& frame, SDL_Renderer* gRenderer)
{
    if(animation== IDLE)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    else if(animation== MOVE_LEFT)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[1 + moves%5], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        if (frame%12==0)
        {
            moves++;
        }
    }
    else if(animation== MOVE_RIGHT)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[1 + moves%5], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );

        if (frame%12==0)
        {
            moves++;
        }
    }

    else if(animation== DIE)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[7 + moves%4], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );

        if (frame%25==0)
        {
            moves++;
        }
        if (moves==4)
        {
            alive=false;
        }
    }
}

void Commando::Move()
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
        if (position.x>300 && position.x<350)   // At this position, it stops and fires.
        {
            SetState(IDLE);
            fire=1;
        }
        else if (position.x<800 && position.x>750)
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
            if (position.x>300 && position.x<350)
            {
                SetState(MOVE_LEFT);
                fire=-1;    // fire is stopped
            }
            else if (position.x<800 && position.x>750)
            {
                SetState(MOVE_RIGHT);
                fire=-1;
            }
        }
    }
}

bool Commando::GetAlive()
{
    if (position.x<0 && animation==MOVE_LEFT)   // If commando moves outside screen, it dies.
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
        SetState(DIE);  //After 2 bullets are hit, commando dies.
    }
    return alive;
}
