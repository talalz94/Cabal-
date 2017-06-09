#include "HealthBar.h"

HealthBar::HealthBar()
{

}

HealthBar::HealthBar(LTexture* image, int health, int animation)
{
    spriteSheetTexture = image;
    this->animation=animation;
    //SELF
    if (animation==SELF)
    {
        int l = 1;
        for (int i=1; i<=10; i++)
        {
            clips[ l ].x = 0;
            clips[ l ].y = 2;
            clips[ l ].w = 58*i;
            clips[ l ].h = 44;
            l++;
        }
        this->health=health;
    }

    //Boss
    if (animation==BOSS)
    {
        int k = 15;
        for (int i=1; i<=15; i++)
        {
            clips[ k ].x = 0;
            clips[ k ].y = i*26.07;
            clips[ k ].w = 631;
            clips[ k ].h = 26.07;
            k--;
        }
        this->health=health;
    }

    this->width = clips[0].w;
    this->height = clips[0].h;

    alive  = true;
}

HealthBar::~HealthBar()
{
    spriteSheetTexture = NULL;
    std::cout<<"\nHealthBar deallocated\n";
}

void HealthBar::Render(long int& frame, SDL_Renderer* gRenderer)
{
    if (animation==SELF)
    {
        spriteSheetTexture->Render( 0, 0, &clips[health], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
    else if (animation==BOSS)
    {
        spriteSheetTexture->Render( 0, 605, &clips[health], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
    }
}

void HealthBar::Move(int health)
{
    this->health=health;
    if (health==0)
    {
        alive=false;
    }
}

bool HealthBar::GetAlive()
{
    return alive;
}

