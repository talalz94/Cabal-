#include "Screen.h"


Screen::Screen()
{

}

Screen::Screen(LTexture* image, float x, float y)
{
	spriteSheetTexture = image;

	this->x = x;
	this->y = y;

	this->width = spriteClips[0].w;
	this->height = spriteClips[0].h;



}


Screen::~Screen()
{
	spriteSheetTexture = NULL;
}




void Screen::Render(SDL_Renderer* gRenderer)
{
	///if (condition== true)
	spriteSheetTexture->Render( x ,y , &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
	/*}
	else if (condition == false)
	{
	cout<<"Hello";
	spriteSheetTexture->Render( pos.x - width/2, pos.y - height/2, &spriteClips[ (frame % (FLYING_FRAMES-3)+3 )], 0.0, NULL, SDL_FLIP_VERTICAL, gRenderer );

	}*/
	//SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0x00, 0xFF);
	//SDL_RenderDrawRect(gRenderer, &mcollider);
}

int Screen::getx()
{
	return x;
}
int Screen::gety()
{
	return y;
}

int Screen::gettype()
{
	return type;
}


int Screen::getwidth()
{
	return width;
}
int Screen::getheight()
{
	return height;
}
