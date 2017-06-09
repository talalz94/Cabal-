#pragma once

#include "SDL.h"
#include "Button.h"
#include "Button_Pos.h"
#include "SDL_image.h"
#include <iostream>

using namespace std;

class MainMenu
{
private:
    LTexture* texture;
    SDL_Renderer* gRenderer;
    Button Newgame;
    Button LoadGame;
    Button Quit;
    Button_Pos Newgamepos;
    Button_Pos Loadgamepos;
    Button_Pos Quitpos;
public:
    MainMenu();
    MainMenu(LTexture* t, SDL_Renderer* r, int x1, int y1, int x2, int y2, int x3, int y3);
    MainMenu MenuPic(SDL_Renderer* r, int, int);
    void Display(const std::string &image_path);
    void DisplayNewgame(int, int, int, int);
    void DisplayLoadgame(int, int, int, int);
    void Background(int w, int h, const std::string &image_path);
    Button_Pos New_game();
    Button_Pos Load_Game();
    Button_Pos Quit_();
};


