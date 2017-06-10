#pragma once
#include "Queue.h"
#include "Point.h"
#include "Commando.h"
#include "Soldier.h"
#include "Default.h"
#include "MachineGun.h"
#include "Missiles.h"
#include "Boss.h"
#include "AirCraft.h"
#include "Tank.h"


class FileManager
{
    char buff[32];                              //Declaring a character array to store a line
public:
    void LoadFile(Unit* target, Point& position, int& health,int& score, Queue& units, LTexture* commando, LTexture* soldier, LTexture* jahaaz, LTexture* bosss, LTexture* goli,
                           LTexture* tank,  LTexture* bosshealthbar, LTexture* missileshot, LTexture* explosion, LTexture* bossexplosion,
                           LTexture* power);
    void SaveFile(Unit*, Queue&, int&);
};
