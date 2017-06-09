#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LTexture.h"
#include "FileManager.h"
#include "Queue.h"
#include "Player.h"
#include "HealthBar.h"
#include "Enemy.h"
#include "Bullets.h"
#include "Default.h"
#include "MachineGun.h"
#include "Missiles.h"
#include "Point.h"
#include "Commando.h"
#include "Soldier.h"
#include "Boss.h"
#include "Screen.h"
#include "Splash.h"
#include "AirCraft.h"
#include "Tank.h"
#include "Word.h"
#include "Character.h"
#include "Button.h"
#include "Button_Pos.h"
#include "MainMenu.h"
#include "string.h"

//Pre defined screen width and height
extern const int SCREEN_WIDTH = 1024;
extern const int SCREEN_HEIGHT = 640;

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;



LTexture gSpritePlayer;
LTexture gSpriteBoss;
LTexture gSpriteTank;
LTexture gSpriteEnemy;
LTexture gSpriteSoldier;
LTexture gSpriteCommando;
LTexture gSpriteAirCraft;
LTexture gSpriteBullet;
LTexture gScreen;
LTexture gHealth;
LTexture gBossHealth;
LTexture gMissile;
LTexture gexplode;
LTexture gbossexplode;
LTexture gpower;
LTexture gsplash;
LTexture gSprite;
LTexture gSprite2;
LTexture Image;

Mix_Chunk* Missile;
Mix_Chunk* MachineGuns;
Mix_Chunk* DefaultGun;
Mix_Chunk* ExplosionSound;
Mix_Chunk* StartGame;
Mix_Chunk* BackMusic;
Mix_Chunk* Bonus;
Mix_Chunk* Death;


FileManager file;

SDL_Rect ScreenClip;

bool init();
bool loadMedia();
void close();

int main( int argc, char* args[] )
{
    ScreenClip.x =  0;
    ScreenClip.y =  0;
    ScreenClip.w = 1024;
    ScreenClip.h = 640;
	//Start up SDL and create window
	Mix_OpenAudio(22050,MIX_DEFAULT_FORMAT, 2, 2046);
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{

			bool quit = false;                      //Main loop flag

			SDL_Event e;

			long int frame = 0;                     //Current animation frame

			/* initialize random seed: */
            srand (time(NULL));

            Uint8 alpha = 0;                       //Splash screen variables
			bool appear = false;
			bool done = false;
			bool play = false;
			bool splashscreen = true;
			int delay = 100;                    //Splash screen loading time

            /*Point p;                            //Main menu variables
            p.x = 20;
            p.y = 20;
            Character aa(&Image, 53);
            aa.SetPosition(&p);
            char* ch = "778789";  */              //

            int fire=0;
			Queue units;
			Point screen;
            screen.x=SCREEN_WIDTH/2;
            screen.y=SCREEN_HEIGHT-45;
            int health=10;
            int score=0;
            int counter=0;
            //file.LoadFile(screen, health, units, &gSpriteCommando, &gSpriteSoldier);
            Player* player = new Player(&gSpritePlayer, &gHealth, health, screen);
            Enemy* enemy=NULL;
            Bullets* guns=NULL;
            int keyflag = 0;
            Point haha(0,320);
            enemy=new Boss(&gSpriteBoss,&gBossHealth, haha, player);
            units.Enqueue(enemy);
            int x, y;
            char buff[32];
            char *strScore = itoa(score,buff, 10);
			Word* GameSCORE = new Word(strScore, &Image, gRenderer, strlen(strScore), 0, 50);
			Word* GameLost = NULL;

			while( !quit )                          //While application is running
			{
			    //Handle events on queue
                while (SDL_PollEvent(&e) != 0)
                {
                    //User requests quit
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }

			    if (splashscreen == true)                  //Splash screen
                {
                    if (appear == true)
					{
						delay -= 1;
						if (delay < 0)
						{
							alpha -= 1;
							if (alpha <= 0)
							{
								done = true;
								splashscreen = false;

							}
						}
					}
					else
					{
						alpha += 1;
						if (alpha == 255)
						{
							appear = true;
						}

					}



                    SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
                    SDL_RenderClear(gRenderer);

                    gSprite.SetAlpha(alpha);
                    Screen* scr = new Splash(&gSprite, 0, 0);
                    scr->Render(gRenderer);
                    SDL_RenderPresent(gRenderer);


                }                                            // splash screen end

                if (done == true)
                {
                    SDL_GetMouseState( &x, &y );

                    alpha=255;
                    if((e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && (x > 400) && (x<700))
                        && (y>200) && (y<270))
                    {
                        play = true;
                        done = false;
                    }
                    if((e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && (x > 450) && (x<610))
                        && (y>500) && (y<570))
                    {
                        quit=true;
                    }

                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );    //Clear screen
                    SDL_RenderClear( gRenderer );

                    gSprite2.SetAlpha(alpha);
                    Screen* scr = new Splash(&gSprite2, 0, 0);
                    scr->Render(gRenderer);

                    MainMenu menu(&Image, gRenderer, 400, 200, 400, 350, 450, 500);
                    SDL_RenderPresent( gRenderer );     //Update screen
                }




                if (play == true)        //Main game function start.
                {


                    srand(time(NULL));
                    if(frame%60 == 0)
                    {
                        int genrandom = rand() % 2 +1;
                        int xrandom = rand() % 2;
                        int yrandom = rand() % (SCREEN_HEIGHT-470)+360;    //from 370 to 530
                        Point Eposition;
                        int state;
                        if (xrandom==0)
                        {
                            Eposition.x=-5;
                            state=MOVE_RIGHT;

                        }
                        else if (xrandom==1)
                        {
                            Eposition.x=SCREEN_WIDTH+5;
                            state=MOVE_LEFT;
                        }

                        Eposition.y=yrandom;

                        if (genrandom==1)
                        {
                            enemy = new Commando(&gSpriteCommando, Eposition, state);
                        }
                        else if (genrandom==2)
                        {
                            enemy = new Soldier(&gSpriteSoldier, Eposition, state);
                        }
                        units.Enqueue(enemy);
                    }

                    if (frame%500==0)
                    {
                        int xrandomh = rand() % 2;
                        int yrandomh = rand() % 2;
                        Point Hposition;
                        int state;
                        if (xrandomh==0)
                        {
                            Hposition.x=-5;
                            state=MOVE_RIGHT;

                        }
                        else if (xrandomh==1)
                        {
                            Hposition.x=SCREEN_WIDTH+5;
                            state=MOVE_LEFT;
                        }
                        if (yrandomh==0)
                        {
                            Hposition.y=190;
                        }
                        else if (yrandomh==1)
                        {
                            Hposition.y=180;
                        }
                        enemy = new AirCraft(&gSpriteAirCraft, Hposition, state);
                        units.Enqueue(enemy);
                    }

                    if (frame%400==0)
                    {
                        int xrandomt = rand() % 2;
                        int yrandomt = rand() % 2;
                        Point Tposition;
                        int state;
                        if (xrandomt==0)
                        {
                            Tposition.x=-5;
                            state=MOVE_RIGHT;

                        }
                        else if (xrandomt==1)
                        {
                            Tposition.x=SCREEN_WIDTH+5;
                            state=MOVE_LEFT;
                        }
                        if (yrandomt==0)
                        {
                            Tposition.y=300;
                        }
                        else if (yrandomt==1)
                        {
                            Tposition.y=310;
                        }
                        enemy = new Tank(&gSpriteTank, Tposition, state);
                        units.Enqueue(enemy);
                    }

                    while( SDL_PollEvent( &e ) != 0 )   //Handle events on queue
                    {
                        //User requests quit
                        if( e.type == SDL_QUIT )
                        {
                            quit = true;
                        }

                    }
                    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

                    if (keyflag == 0)
                    {
                        if (player->GetState()!=DIE)
                        {
                            player->SetState(IDLE);
                        }
                        else if (player->GetAlive()==false )
                        {
                            done=true;
                            play=false;
                            Mix_PlayChannel(-1,Death,0);
                            char* over = "GAME OVER";
                            GameLost= new Word(over, &Image, gRenderer, strlen(over), SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
                            if (counter>=60)
                            {
                                quit=true;
                            }
                            counter++;

                        }

                    }

                    if(currentKeyStates[ SDL_SCANCODE_RIGHT ])
                    {
                        player->Move(RIGHT);
                        keyflag=1;
                    }
                    else
                    {
                        keyflag=0;
                    }

                    if(currentKeyStates[ SDL_SCANCODE_LEFT ])
                    {
                        player->Move(LEFT);
                        keyflag=1;
                    }

                    if(e.type == SDL_MOUSEMOTION)
                    {
                        SDL_GetMouseState( &x, &y );
                        keyflag=0;
                    }
                    if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT && player->GetAlive()==true)
                    {
                        if (fire > 16)
                        {
                            Point destination;
                            destination.x = x;
                            destination.y = y;
                            Point departure=player->GetPosition();
                            guns = new Default(&gSpriteBullet, departure, destination);    //generate bullet on the coordinates of plane
                            units.Enqueue(guns);
                            Mix_PlayChannel(-1,DefaultGun,0);
                            fire=0;
                        }
                        keyflag=0;
                    }
                    if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_RIGHT && player->GetAlive()==true)
                    {
                        if (fire > 2)
                        {
                            Point destination;
                            destination.x = x;
                            destination.y = y;
                            Point departure=player->GetPosition();
                            guns = new MachineGun(&gSpriteBullet, departure, destination);    //generate bullet on the coordinates of plane
                            units.Enqueue(guns);
                            Mix_PlayChannel(-1,MachineGuns,0);
                            fire=0;
                        }
                        keyflag=0;
                    }


                    SDL_SetRenderDrawColor( gRenderer, 0x00, 0x00, 0x00, 0xFF );    //Clear screen
                    SDL_RenderClear( gRenderer );
                    gScreen.Render(0, 0, &ScreenClip, 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                    units.Collision(&gexplode, &gpower, &gbossexplode, player, ExplosionSound, Bonus, &score);
                    units.Update(frame, gRenderer, player, &gSpriteBullet, &gMissile, DefaultGun, Missile);
                    player->Render(frame, gRenderer);
                    GameSCORE->Display();

                    strScore = itoa(score,buff, 10);
                    delete GameSCORE;
                    GameSCORE = new Word(strScore, &Image, gRenderer, strlen(strScore), 0, 50);
                    if (GameLost!=NULL)
                    {
                        GameLost->Display();
                    }
                    SDL_RenderPresent( gRenderer );     //Update screen

                    ++frame;                   //Go to next frame
                    fire++;

                }
			}
			Mix_FreeChunk(DefaultGun);
            Mix_FreeChunk(MachineGuns);
            Mix_FreeChunk(Missile);
            Mix_FreeChunk(ExplosionSound);
            Mix_FreeChunk(BackMusic);
            Mix_FreeChunk(StartGame);
            Mix_FreeChunk(Bonus);
            Mix_FreeChunk(Death);

            Mix_CloseAudio();
			file.SaveFile(player, units);
            delete player;

		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "CABAL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( !gSpriteAirCraft.LoadFromFile( "Images/Helicopter.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

	if( !gSpriteBoss.LoadFromFile( "Images/Boss.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

	if( !gSpriteCommando.LoadFromFile( "Images/Commando.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

	if( !gSpriteEnemy.LoadFromFile( "Images/Enemy.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

	if( !gSpritePlayer.LoadFromFile( "Images/Player.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

	if( !gSpriteSoldier.LoadFromFile( "Images/Soldier.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

	if( !gSpriteTank.LoadFromFile( "Images/Tank.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	if( !gSpriteBullet.LoadFromFile( "Images/Bullets.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	if( !gScreen.LoadFromFile( "Images/screen.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
    if( !gMissile.LoadFromFile( "Images/Missiles1.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	if( !gHealth.LoadFromFile( "Images/Health.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	if( !gBossHealth.LoadFromFile( "Images/BossHealth.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	if( !gexplode.LoadFromFile( "Images/Explosion.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	if( !gbossexplode.LoadFromFile( "Images/BossExplosion.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	if( !gpower.LoadFromFile( "Images/powerups.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}

	if( !Image.LoadFromFile( "Images/fontSprite.png", gRenderer  ) )
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
    if (!gSprite2.LoadFromFile("Images/menu2.jpg", gRenderer))
	{
		printf("Failed to load Splash Screen!\n");
		success = false;
	}

	if (!gSprite.LoadFromFile("Images/cabal.png", gRenderer))
	{
		printf("Failed to load Splash Screen!\n");
		success = false;
	}
	else
	{
		//Set standard alpha blending
		gSprite.SetBlendMode( SDL_BLENDMODE_BLEND );
	}
	DefaultGun=Mix_LoadWAV("sounds/gun.wav");
    Missile=Mix_LoadWAV("sounds/missile.wav");
    MachineGuns=Mix_LoadWAV("sounds/mgun1.wav");
    Death=Mix_LoadWAV("sounds/death.wav");
    BackMusic=Mix_LoadWAV("sounds/background.wav");
    Bonus=Mix_LoadWAV("sounds/bonus.wav");
    StartGame=Mix_LoadWAV("sounds/gamestart.wav");
    ExplosionSound=Mix_LoadWAV("sounds/Explosion.wav");
	return success;
}

void close()
{
	//Free loaded images
	gSpritePlayer.Free();
    gSpriteCommando.Free();
    gSpriteEnemy.Free();
    gSpriteSoldier.Free();
    gSpriteAirCraft.Free();
    gSpriteTank.Free();
    gSpriteBoss.Free();
    gSpriteBullet.Free();
    gScreen.Free();
    gMissile.Free();
    gHealth.Free();
    gBossHealth.Free();
    gexplode.Free();
    gbossexplode.Free();
    gsplash.Free();


	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}
