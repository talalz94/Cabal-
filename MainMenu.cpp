#include "MainMenu.h"

MainMenu::MainMenu()
{

}

MainMenu::MainMenu(LTexture* t, SDL_Renderer* render, int x1, int y1, int x2, int y2, int x3, int y3)
{
    texture = t;
    gRenderer = render;
    Button Newgame("NEW GAME", x1, y1, texture, gRenderer, 8);
    Button LoadGame("LOAD GAME", x2, y2, texture, gRenderer, 9);
    Button Quit("QUIT", x3, y3, texture, gRenderer, 4);
    Newgame.Display(0, 0, 0, 0);
    LoadGame.Display(0, 0, 0, 0);
    Quit.Display(0, 0, 0, 0);
    Newgamepos = Newgame.position();
    Loadgamepos = LoadGame.position();
    Quitpos = Quit.position();
}

void MainMenu::DisplayNewgame(int a, int b, int c, int d)
{

    Newgame.Display(a, b, c, d);

}


Button_Pos MainMenu::New_game()
{
   return Newgamepos;
}

Button_Pos MainMenu::Load_Game()
{
    Button_Pos LoadGame_Pos = LoadGame.position();
    return LoadGame_Pos;
}

Button_Pos MainMenu::Quit_()
{
    Button_Pos Quit_Pos = Quit.position();
    return Quit_Pos;
}

