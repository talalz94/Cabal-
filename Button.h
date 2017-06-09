#pragma once

#include "Character.h"
#include "Point.h"
#include "Word.h"
#include <iostream>
#include "Button_Pos.h"
#include "SDL.h"

using namespace std;

class Button
{
private:
    Word word;
    Point start;
    LTexture* texture;
    SDL_Renderer* gRenderer;
    int siz;
    Button_Pos pos;
public:
    Button();
    Button(char*, int, int, LTexture*, SDL_Renderer*, int);
    void Display(int, int, int, int);
    Button_Pos position();
};


