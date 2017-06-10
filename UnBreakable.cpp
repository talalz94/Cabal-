#include "UnBreakable.h"
UnBreakable::UnBreakable()
{

}
UnBreakable::UnBreakable(LTexture* image, Point& position, int state)
{
    spriteSheetTexture = image;

    //Frame 0
    clips[ 0 ].x = 0;
    clips[ 0 ].y = 0;
    clips[ 0 ].w = 373;
    clips[ 0 ].h = 169;

    this->position.x = 700;
    this->position.y = 100;

    alive = true;
}

UnBreakable::~UnBreakable()
{
    std::cout<<"UnBreakable deallocated\n";
}

void UnBreakable::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render(position.x-width/2, position.y-height/2, &clips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

bool UnBreakable::GetAlive()
{
    return alive;
}
