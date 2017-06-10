#include "FileManager.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

void FileManager::LoadFile(Unit* target, Point& position, int& health, int& score, Queue& units, LTexture* commando, LTexture* soldier, LTexture* jahaaz, LTexture* bosss, LTexture* goli,
                           LTexture* tank,  LTexture* bosshealthbar, LTexture* missileshot, LTexture* explosion, LTexture* bossexplosion,
                           LTexture* power)
{
    FILE* filePointer;                          //A pointer is created for file manipulation
    filePointer = fopen("game.txt", "r");    //Opening file as read only

    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return;
    }
    fgets(buff, 32, (FILE*)filePointer);
    fgets(buff, 32, (FILE*)filePointer);
    position.x=atoi(buff);                      //gets position for x-axis

    fgets(buff, 32, (FILE*)filePointer);
    position.y=atoi(buff);                      //gets position for y-axis

    fgets(buff, 32, (FILE*)filePointer);
    health=atoi(buff);                          //gets health

    fgets(buff, 32, (FILE*)filePointer);
    score=atoi(buff);                           //gets score

    Unit* unit= NULL;                               //pointer is initially set to NULL
    while(fgets(buff, 32, (FILE*)filePointer)!=NULL)   //If line read is not NULL
    {
        Point point;
        fgets(buff, 32, (FILE*)filePointer);
        point.x=atoi(buff);
        fgets(buff, 32, (FILE*)filePointer);
        point.y=atoi(buff);
        fgets(buff, 32, (FILE*)filePointer);
        int state = atoi(buff);
        fgets(buff, 32, (FILE*)filePointer);
        int type = atoi(buff);
        if (type==1)                                        //checks for the type whether a soldier or a tank or an aircraft etc
        {
            unit=new Commando(commando, point, state);
        }
        else if (type==2)
        {
            unit=new Soldier(soldier, point, state);
        }
        else if (type==3)
        {
            unit=new AirCraft(jahaaz, point, state);
        }
        else if (type==4)
        {
            unit=new Tank(tank, point, state);
        }
        else if (type==5)
        {
            unit=new Boss(bosss, bosshealthbar, point, target);
        }
        else if (type==11)
        {
            unit=new Default(goli, point, position);
        }
        else if (type==12)
        {
            unit=new MachineGun(goli, point, position);
        }
        else if (type==13)
        {
            unit=new Missiles(missileshot, point, target);
        }
        else if (type==14)
        {
            unit=new EBullet(goli, point, position);
        }
        else if (type==21)
        {
            unit=new Explosion(explosion, point, state);
        }
        else if (type==22)
        {
            unit=new Explosion(bossexplosion, point, state);
        }
        else if (type==50)
        {
            unit=new Powerups(power, point, state);
        }
        else if (type==51)
        {
            unit=new Powerups(power, point, state);
        }
        units.Enqueue(unit);

    }
}

void FileManager::SaveFile(Unit* player, Queue& units, int& score)
{
    FILE* filewriter;                       //A new pointer is created
    filewriter = fopen("game.txt", "w");    //Opening file as read only

    if (filewriter == NULL)
    {
        perror ("New Game");
        return;
    }
    fputs("[Player]\n", (FILE*)filewriter);
    fputs(itoa(player->Getx(), buff, 10), (FILE*)filewriter); fputs("\n", (FILE*)filewriter);
    fputs(itoa(player->Gety(), buff, 10), (FILE*)filewriter); fputs("\n", (FILE*)filewriter);
    fputs(itoa(player->GetHealth(), buff, 10), (FILE*)filewriter); fputs("\n", (FILE*)filewriter);
    fputs(itoa(score, buff, 10), (FILE*)filewriter); fputs("\n", (FILE*)filewriter);

    units.Save(filewriter);

    fclose(filewriter);
}
