#include "FileManager.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>

void FileManager::LoadFile(Point& position, int& health, Queue& units, LTexture* commando, LTexture* soldier)
{
    FILE* filePointer;
    filePointer = fopen("game.txt", "r");    //Opening file as read only

    if (filePointer == NULL)
    {
        perror ("Error opening file");
        return;
    }
    fgets(buff, 32, (FILE*)filePointer);
    fgets(buff, 32, (FILE*)filePointer);
    position.x=atoi(buff);

    fgets(buff, 32, (FILE*)filePointer);
    position.y=atoi(buff);

    fgets(buff, 32, (FILE*)filePointer);
    health=atoi(buff);

    Unit* unit= NULL;
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
        if (type==1)
        {
            //unit=new Commando(commando, point, state);
        }
        else if (type==2)
        {
            unit=new Soldier(soldier, point, state);
        }
        units.Enqueue(unit);

    }
}

void FileManager::SaveFile(Unit* player, Queue& units)
{
    FILE* filewriter;
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

    units.Save(filewriter);

    fclose(filewriter);
}
