#include "Button.h"

#include "Character.h"
#include "Point.h"
#include "String.h"
#include <iostream>

using namespace std;

Button::Button()
{

}

Button::Button(char* a, int x, int y, LTexture* texture, SDL_Renderer* render, int sizeofword)
{
    this->texture = texture;
    gRenderer = render;
    start.x = x;
    start.y = y;
    Word s(a, texture, render, sizeofword, x + 10, y + 10);
    word = s;
    siz = sizeofword;
}

void Button::Display(int a, int b, int c, int d)
{
    SDL_SetRenderDrawColor(gRenderer, a, b, c, d);
    SDL_Rect rect = {start.x, start.y, 35 * siz + 20, 68};
    SDL_RenderFillRect(gRenderer, &rect);
    word.Display();
}

Button_Pos Button::position()
{
    pos.x_start = start.x;
    pos.x_end = start.x + 35 * siz + 20;
    pos.y_start = start.y;
    pos.y_end = 68 + start.y;
    return pos;
}


