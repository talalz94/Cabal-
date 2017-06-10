#include "Breakable.h"
Breakable::Breakable()
{

}
Breakable::Breakable(LTexture* image, Point& position, int state)
{
    spriteSheetTexture = image;

    //Frame 0
    clips[ 0 ].x = 6;
    clips[ 0 ].y = 181;
    clips[ 0 ].w = 258;
    clips[ 0 ].h = 111;

    this->position.x = 200;
    this->position.y = clips[ 0 ].y;

    alive = true;
    health=1;
}

Breakable::~Breakable()
{
    std::cout<<"Breakable deallocated\n";
}

void Breakable::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render(position.x-width/2, position.y-height/2, &clips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
}

bool Breakable::GetAlive()
{
    return alive;
}
