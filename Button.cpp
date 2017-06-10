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
    start.x = x;                                                    //The starting point for the x-coordinate of the button
    start.y = y;                                                    //The starting point for the y-coordinate of the button
    Word s(a, texture, render, sizeofword, x + 10, y + 10);         //An object for word class is created
    word = s;
    siz = sizeofword;
}

void Button::Display(int a, int b, int c, int d)                //For displaying the button
{
    SDL_SetRenderDrawColor(gRenderer, a, b, c, d);
    SDL_Rect rect = {start.x, start.y, 35 * siz + 20, 68};
    SDL_RenderFillRect(gRenderer, &rect);
    word.Display();
}

Button_Pos Button::position()
{
    pos.x_start = start.x;                              //position given where the x-coordinate of button begins
    pos.x_end = start.x + 35 * siz + 20;                //position given where the x-coordinate of button ends in accordance with the size of word
    pos.y_start = start.y;                              //position given where the y-coordinate of button begins
    pos.y_end = 68 + start.y;                           //position given where the x-coordinate of button ends in accordance with the size of word
    return pos;
}


