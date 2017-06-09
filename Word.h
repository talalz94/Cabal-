#pragma once

#include "Character.h"
#include "Point.h"
#include <iostream>

using namespace std;

class Word
{
private:
    char* str;
    Point start;
    LTexture* texture;
    SDL_Renderer* gRenderer;
    int sizeofword;
public:
    Word();
    Word(char* , LTexture*, SDL_Renderer*, int, int, int);
    void Display();
};

