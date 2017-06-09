#pragma once
#include <string>
#include "Screen.h"
#include "LTexture.h"
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>


class Splash: public Screen
{
public:
	Splash();
	Splash(LTexture* image, float x, float y);
	~Splash();
	void Render(SDL_Renderer* gRenderer);
};

