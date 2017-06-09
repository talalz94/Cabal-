#include "Character.h"
#include "Point.h"
#include "Word.h"
#include <iostream>

using namespace std;

Word::Word()
{

}

Word::Word(char *a, LTexture* t, SDL_Renderer* render, int s, int x, int y)
{
    texture = t;
    str = a;
    gRenderer = render;
    sizeofword = s;
    start.x = x;
    start.y = y;
}

void Word::Display()
{

    int character;
    for (int i = 0; i < sizeofword; i++)
    {
        Point p;
        p.x = 20 + i*35 + start.x;
        p.y = 20 + start.y;
        if (str[i] != ' ')
        {
            if (str[i] == 'A')
        {
            character = 0;
        }
        else if (str[i] == 'B')
        {
            character = 1;
        }
        else if (str[i] == 'C')
        {
            character = 2;
        }
        else if (str[i] == 'D')
        {
            character = 3;
        }
        else if (str[i] == 'E')
        {
            character = 4;
        }
        else if (str[i] == 'F')
        {
            character = 5;
        }
        else if (str[i] == 'G')
        {
            character = 6;
        }
        else if (str[i] == 'H')
        {
            character = 7;
        }
        else if (str[i] == 'I')
        {
            character = 8;
        }
        else if (str[i] == 'J')
        {
            character = 9;
        }
        else if (str[i] == 'K')
        {
            character = 10;
        }
        else if (str[i] == 'L')
        {
            character = 11;
        }
        else if (str[i] == 'M')
        {
            character = 12;
        }
        else if (str[i] == 'N')
        {
            character = 13;
        }
        else if (str[i] == 'O')
        {
            character = 14;
        }
        else if (str[i] == 'P')
        {
            character = 15;
        }
        else if (str[i] == 'Q')
        {
            character = 16;
        }
        else if (str[i] == 'R')
        {
            character = 17;
        }
        else if (str[i] == 'S')
        {
            character = 18;
        }
        else if (str[i] == 'T')
        {
            character = 19;
        }
        else if (str[i] == 'U')
        {
            character = 20;
        }
        else if (str[i] == 'V')
        {
            character = 21;
        }
        else if (str[i] == 'W')
        {
            character = 22;
        }
        else if (str[i] == 'X')
        {
            character = 23;
        }
        else if (str[i] == 'Y')
        {
            character = 24;
        }
        else if (str[i] == 'Z')
        {
            character = 25;
        }
        else if (str[i] == 'a')
        {
            character = 26;
        }
        else if (str[i] == 'b')
        {
            character = 27;
        }
        else if (str[i] == 'c')
        {
            character = 28;
        }
        else if (str[i] == 'd')
        {
            character = 29;
        }
        else if (str[i] == 'e')
        {
            character = 30;
        }
        else if (str[i] == 'f')
        {
            character = 31;
        }
        else if (str[i] == 'g')
        {
            character = 32;
        }
        else if (str[i] == 'h')
        {
            character = 33;
        }
        else if (str[i] == 'i')
        {
            character = 34;
        }
        else if (str[i] == 'j')
        {
            character = 35;
        }
        else if (str[i] == 'k')
        {
            character = 36;
        }
        else if (str[i] == 'l')
        {
            character = 37;
        }
        else if (str[i] == 'm')
        {
            character = 38;
        }
        else if (str[i] == 'n')
        {
            character = 39;
        }
        else if (str[i] == 'o')
        {
            character = 40;
        }
        else if (str[i] == 'p')
        {
            character = 41;
        }
        else if (str[i] == 'q')
        {
            character = 42;
        }
        else if (str[i] == 'r')
        {
            character = 43;
        }
        else if (str[i] == 's')
        {
            character = 44;
        }
        else if (str[i] == 't')
        {
            character = 45;
        }
        else if (str[i] == 'u')
        {
            character = 46;
        }
        else if (str[i] == 'v')
        {
            character = 47;
        }
        else if (str[i] == 'w')
        {
            character = 48;
        }
        else if (str[i] == 'x')
        {
            character = 49;
        }
        else if (str[i] == 'y')
        {
            character = 50;
        }
        else if (str[i] == 'z')
        {
            character = 51;
        }
        else if (str[i] == '0')
        {
            character = 52;
        }
        else if (str[i] == '1')
        {
            character = 53;
        }
        else if (str[i] == '2')
        {
            character = 54;
        }
        else if (str[i] == '3')
        {
            character = 55;
        }
        else if (str[i] == '4')
        {
            character = 56;
        }
        else if (str[i] == '5')
        {
            character = 57;
        }
        else if (str[i] == '6')
        {
            character = 58;
        }
        else if (str[i] == '7')
        {
            character = 59;
        }
        else if (str[i] == '8')
        {
            character = 60;
        }
        else if (str[i] == '9')
        {
            character = 61;
        }









        Character a(texture, character);
        a.SetPosition(&p);
        a.Render(gRenderer);
        }
    }
}


