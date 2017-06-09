#include <iostream>
#include "Splash.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

Splash::Splash()
{
	std::cout << "Splash screen constructor" << std::endl;
}

Splash::Splash(LTexture* image, float x, float y):Screen(image,x,y)
{
	spriteClips[0].x = 0;
	spriteClips[0].y = 0;
	spriteClips[0].w = 1250;
	spriteClips[0].h = 700;
	this->width = spriteClips[0].w;
	this->height = spriteClips[0].h;
}

Splash::~Splash()
{
	spriteSheetTexture = NULL;
	printf("SPlash destructor called\n");
}

void Splash::Render(SDL_Renderer* gRenderer)
{
	spriteSheetTexture->Render(x, y, &spriteClips[0], 0.0, NULL,SDL_FLIP_NONE, gRenderer);
}
