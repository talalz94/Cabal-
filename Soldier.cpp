#include "Soldier.h"

Soldier::Soldier()
{

}

Soldier::Soldier(LTexture* image, Point& position, int animation):Foots(image, position, animation)
{

    this->animation = animation;
    //IDLE
    clips[0].x = 247;
    clips[0].y = 10;
    clips[0].w = 28;
    clips[0].h = 55;

    //WALK
    clips[1].x = 190;
    clips[1].y = 9;
    clips[1].w = 33;
    clips[1].h = 55;

    clips[2].x = 128;
    clips[2].y = 9;
    clips[2].w = 38;
    clips[2].h = 55;

    clips[3].x = 75;
    clips[3].y = 9;
    clips[3].w = 26;
    clips[3].h = 55;

    //SHOOT
    clips[4].x = 367;
    clips[4].y = 10;
    clips[4].w = 25;
    clips[4].h = 55;

    //DIE
    clips[5].x = 422;
    clips[5].y = 12;
    clips[5].w = 33;
    clips[5].h = 53;

    clips[6].x = 17;
    clips[6].y = 78;
    clips[6].w = 33;
    clips[6].h = 46;

    clips[7].x = 72;
    clips[7].y = 78;
    clips[7].w = 40;
    clips[7].h = 46;

    clips[8].x = 131;
    clips[8].y = 78;
    clips[8].w = 40;
    clips[8].h = 46;

    clips[9].x = 185;
    clips[9].y = 78;
    clips[9].w = 51;
    clips[9].h = 46;

    this->position = position;

    this->width = clips[0].w;
    this->height = clips[0].h;

    this->type=2;
    speedx = 0;
    speedy = 0;
    alive  = true;
    moves=0;
    health=1;
    fire=0;
}

Soldier::~Soldier()
{
    spriteSheetTexture = NULL;
    std::cout<<"Soldier deallocated\n";
}

void Soldier::Render(long int& frame, SDL_Renderer* gRenderer)
{
    if(animation== IDLE)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    else if(animation== MOVE_LEFT)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[1 + moves%3], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        if (frame%12==0)
        {
            moves++;
        }
    }
    else if(animation== MOVE_RIGHT)
    {

        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[1 + moves%3], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );

        if (frame%12==0)
        {
            moves++;
        }
    }

    else if(animation== DIE)
    {

        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[5 + moves%5], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );

        if (frame%20==0)
        {
            moves++;
        }
        if (moves==5)
        {
            alive=false;
        }
    }


}

void Soldier::Move()
{
    if (animation==MOVE_LEFT)
    {
        speedx = -1;
    }
    else if (animation==MOVE_RIGHT)
    {
        speedx = 1;
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
        if (position.x>300 && position.x<350)
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
                fire=-1;
            }
            else if (position.x<800 && position.x>750)
            {
                SetState(MOVE_RIGHT);
                fire=-1;
            }
        }
    }
}

bool Soldier::GetAlive()
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
