#include "Player.h"

Player::Player()
{

}

Player::Player(LTexture* image, LTexture* healthimage, int health, Point& position):Unit(image, position)
{
    spriteSheetTexture = image;
    animation = IDLE;
    //IDLE
    clips[0].x =  232;
    clips[0].y =  7;
    clips[0].w = 26;
    clips[0].h = 52;

    //WALK
    clips[1].x = 182;
    clips[1].y = 5;
    clips[1].w = 44;
    clips[1].h = 53;

    clips[2].x = 149;
    clips[2].y = 4;
    clips[2].w = 30;
    clips[2].h = 55;

    clips[3].x = 97;
    clips[3].y = 6;
    clips[3].w = 45;
    clips[3].h = 50;

    clips[4].x = 53;
    clips[4].y = 5;
    clips[4].w = 40;
    clips[4].h = 53;

    clips[5].x = 5;
    clips[5].y = 5;
    clips[5].w = 38;
    clips[5].h = 55;

    //AIM
    clips[6].x = 267;
    clips[6].y = 6;
    clips[6].w = 34;
    clips[6].h = 52;

    //SHOOT
    clips[7].x = 364;
    clips[7].y = 6;
    clips[7].w = 41;
    clips[7].h = 52;

    //DIE
    clips[8].x = 12;
    clips[8].y = 72;
    clips[8].w = 31;
    clips[8].h = 53;

    clips[9].x = 52;
    clips[9].y = 66;
    clips[9].w = 48;
    clips[9].h = 60;

    clips[10].x = 109;
    clips[10].y = 72;
    clips[10].w = 53;
    clips[10].h = 55;

    clips[11].x = 170;
    clips[11].y = 72;
    clips[11].w = 55;
    clips[11].h = 53;

    clips[12].x = 236;
    clips[12].y = 72;
    clips[12].w = 57;
    clips[12].h = 53;

    clips[13].x = 307;
    clips[13].y = 72;
    clips[13].w = 57;
    clips[13].h = 53;

    this->position = position;

    this->width = clips[0].w;
    this->height = clips[0].h;

    this->health=health;

    healthbar = new HealthBar(healthimage, health, SELF);

    speedx = 0;
    speedy = 0;
    alive  = true;
    moves=0;
}

Player::~Player()
{
    delete healthbar;
    spriteSheetTexture = NULL;
    std::cout<<"Player destroyed\n";
}

void Player::Render(long int& frame, SDL_Renderer* gRenderer)
{
    if(animation== IDLE)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    else if(animation== MOVE_LEFT)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[1 + moves%5], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        if (frame%8==0)
        {
            moves++;
        }
    }
    else if(animation== MOVE_RIGHT)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[1 + moves%5], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );

        if (frame%8==0)
        {
            moves++;
        }
    }

    else if(animation== DIE && alive==true)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[8 + moves%6], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

        if (frame%12==0)
        {
            moves++;
        }
        if (moves==6)
        {
            alive=false;
        }
    }
    healthbar->Move(health);
    healthbar->Render(frame,gRenderer);

}

void Player::Move(int direction)
{
    if (animation!=DIE)
    {
        if(direction==LEFT)
        {
            animation = MOVE_LEFT;
            speedx = -5;
        }

        if(direction==RIGHT)
        {
            animation = MOVE_RIGHT;
            speedx = 5;
        }

        if (position.x<15)
        {
            position.x+=1;
        }
        else if (position.x>1000)
        {
            position.x-=1;
        }
        else
        {
            position.x+=speedx;
        }
    }

}

bool Player::GetAlive()
{
    if (health==0)
    {
        SetState(DIE);
    }
    return alive;
}
