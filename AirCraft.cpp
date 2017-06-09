#include "AirCraft.h"

AirCraft::AirCraft()
{

}

AirCraft::AirCraft(LTexture* image, Point& position, int animation):Vehicle(image, position, animation)
{

    this->animation = animation;
    spriteSheetTexture = image;

    //Frame 0
    clips[ 0 ].x = 16;
    clips[ 0 ].y = 18;
    clips[ 0 ].w = 83;
    clips[ 0 ].h = 72;

    //Frame 1
    clips[ 1 ].x = 116;
    clips[ 1 ].y = 18;
    clips[ 1 ].w = 69;
    clips[ 1 ].h = 72;

    //Frame 2
    clips[ 2 ].x = 208;
    clips[ 2 ].y = 19;
    clips[ 2 ].w = 72;
    clips[ 2 ].h = 72;

    //Frame 3
    clips[ 3 ].x = 12;
    clips[ 3 ].y = 105;
    clips[ 3 ].w = 59;
    clips[ 3 ].h = 73;


    //Frame 4
    clips[ 4 ].x = 77;
    clips[ 4 ].y = 105;
    clips[ 4 ].w = 67;
    clips[ 4 ].h = 73;

    //Frame 5
    clips[ 5 ].x = 155;
    clips[ 5 ].y = 103;
    clips[ 5 ].w = 60;
    clips[ 5 ].h = 72;

    //Frame 6
    clips[ 6 ].x = 231;
    clips[ 6 ].y = 105;
    clips[ 6 ].w = 48;
    clips[ 6 ].h = 72;

//Frame 7
    clips[ 7 ].x = 289;
    clips[ 7 ].y = 101;
    clips[ 7 ].w = 60;
    clips[ 7 ].h = 72;

//Frame 8
    clips[ 8 ].x = 367;
    clips[ 8 ].y = 102;
    clips[ 8 ].w = 46;
    clips[ 8 ].h = 73;

//Frame 9
    clips[ 9 ].x = 427;
    clips[ 9 ].y = 106;
    clips[ 9 ].w = 54;
    clips[ 9 ].h = 73;

//Frame 10
    clips[ 10 ].x = 11;
    clips[ 10 ].y = 184;
    clips[ 10 ].w = 61;
    clips[ 10 ].h = 73;

//Frame 11
    clips[ 11 ].x = 83;
    clips[ 11 ].y = 187;
    clips[ 11 ].w = 46;
    clips[ 11 ].h = 72;

//Frame 12
    clips[ 12 ].x = 146;
    clips[ 12 ].y = 189;
    clips[ 12 ].w = 47;
    clips[ 12 ].h = 72;

//Frame 13
    clips[ 13 ].x = 201;
    clips[ 13 ].y = 187;
    clips[ 13 ].w = 64;
    clips[ 13 ].h = 72;

//Frame 14
    clips[ 14 ].x = 274;
    clips[ 14 ].y = 185;
    clips[ 14 ].w = 64;
    clips[ 14 ].h = 89;

//Frame 15
    clips[ 15 ].x = 369;
    clips[ 15 ].y = 187;
    clips[ 15 ].w = 47;
    clips[ 15 ].h = 87;

    this->position = position;

    this->width = clips[0].w;
    this->height = clips[0].h;

    this->type=3;
    speedx = 0;
    speedy = 0;
    alive  = true;
    moves=0;
    health=4;
    fire=0;
}

AirCraft::~AirCraft()
{
    spriteSheetTexture = NULL;
    std::cout<<"AirCraft deallocated\n";
}

void AirCraft::Render(long int& frame, SDL_Renderer* gRenderer)
{
    if(animation== IDLE)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[10 +moves%6], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        if (frame%8==0)
        {
            moves++;
            if (moves==6)
            {
                fire=1;
            }
        }
    }
    else if(animation== MOVE_LEFT)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[0 + moves%9], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        if (frame%12==0)
        {
            moves++;
        }
    }
    else if(animation== MOVE_RIGHT)
    {

        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[0 + moves%9], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );

        if (frame%12==0)
        {
            moves++;
        }
    }


}

void AirCraft::Move()
{
    if (animation==MOVE_LEFT)
    {
        speedx = -2;
    }
    else if (animation==MOVE_RIGHT)
    {
        speedx = 2;
    }
    if (animation!=IDLE)
    {
        position.x+=speedx;
    }
    if (fire==0)
    {
        if (position.x>500 && position.x<540)
        {
            SetState(IDLE);
            fire=-2;
        }
        else if (position.x<600 && position.x>560)
        {
            SetState(IDLE);
            fire=-2;
        }
    }
    if (fire==-1)
    {
        delay++;
    }

    if(delay>45)
    {
        if (animation==IDLE)
        {
            delay = 0;
            if (position.x>500 && position.x<540)
            {
                SetState(MOVE_LEFT);
                fire=-1;
            }
            else if (position.x<600 && position.x>560)
            {
                SetState(MOVE_RIGHT);
                fire=-1;
            }
        }
    }
}

bool AirCraft::GetAlive()
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
        alive = false;
    }
    return alive;
}
