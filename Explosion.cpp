#include "Explosion.h"

Explosion::Explosion()
{

}

Explosion::Explosion(LTexture* image, Point& position, int animation):Unit(image, position)
{
    spriteSheetTexture = image;                                     //sprite sheet is loaded
    this->animation=animation;
    //Helicopter and Tank
    if (animation==ENEMY)
    {                                                           //images are clipped so that animation can be performed
        clips[0].x = 5;
        clips[0].y = 39;
        clips[0].w = 21;
        clips[0].h = 19;

        clips[1].x = 41;
        clips[1].y = 33;
        clips[1].w = 29;
        clips[1].h = 30;

        clips[2].x = 78;
        clips[2].y = 30;
        clips[2].w = 37;
        clips[2].h = 38;

        clips[3].x = 119;
        clips[3].y = 30;
        clips[3].w = 36;
        clips[3].h = 37;

        clips[4].x = 159;
        clips[4].y = 30;
        clips[4].w = 36;
        clips[4].h = 37;

        clips[5].x = 199;
        clips[5].y = 30;
        clips[5].w = 36;
        clips[5].h = 37;

        clips[6].x = 238;
        clips[6].y = 30;
        clips[6].w = 37;
        clips[6].h = 37;

        this->type=21;
    }


    //Boss
    else
    {
        int k = 0;
        for (int j=0; j<5; j++)
        {
            for (int i=0; i<5; i++)
            {
                clips[ k ].x = i*200;
                clips[ k ].y = j*145.4;
                clips[ k ].w = 200;
                clips[ k ].h = 145.4;
                k++;
            }
        }
        this->type=22;
    }




    this->position = position;

    this->width = clips[0].w;
    this->height = clips[0].h;
    speedx = 0;                                 //speed in x-coordinate
    speedy = 0;                                 //speed in y-coordinate
    alive  = true;
    moves=0;
}

Explosion::~Explosion()
{
    spriteSheetTexture = NULL;
    std::cout<<"Explosion deallocated\n";
}

void Explosion::Render(long int& frame, SDL_Renderer* gRenderer)
{
    if (animation==ENEMY)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[0+moves%7], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        if (frame%12==0)
        {
            moves++;
            if (moves==7)
            {
                alive=false;
            }
        }
    }
    if (animation==BOSS)
    {
        spriteSheetTexture->Render( position.x - width/2, position.y - height/2, &clips[0+moves%25], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
        if (frame%6==0 && moves<=18)
        {
            moves++;
        }
        else
        {
            if (frame%8==0)
            {
                moves++;
                if (moves==25)
                {
                    alive=false;
                }
            }

        }
    }
}

bool Explosion::GetAlive()
{
    return alive;
}

