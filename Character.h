#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"

#include "Point.h"

class Character
{
private:
    Point position;
    LTexture* Image;
    int CharacterValue;
    SDL_Rect rect;
    int width;
    int height;
public:
    Character();
    Character(LTexture*, int);
    ~Character();
    void SetPosition(Point*);
    void Render(SDL_Renderer* gRenderer);
};


