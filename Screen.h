#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include "LTexture.h"


using namespace std;


//enum MOTION { RIGHT, LEFT, UP, DOWN };

class Screen
{
protected:
	float x;
	float y;
	int width;
	int height;
	int type;
	bool condition;

	enum ANIMATION_FRAMES { FLYING_FRAMES = 36 };
	SDL_Rect spriteClips[FLYING_FRAMES];
	LTexture* spriteSheetTexture;

public:
	Screen(LTexture* image, float x, float y);
	Screen();
	virtual ~Screen();
	virtual void Render(SDL_Renderer* gRenderer);
	int getx();
	int gety();
	int getwidth();
	int getheight();
	int gettype();




};

