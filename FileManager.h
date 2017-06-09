#pragma once
#include "Queue.h"
#include "Point.h"
#include "Commando.h"
#include "Soldier.h"
#include "HealthBar.h"

class FileManager
{
    char buff[32];                              //Declaring a character array to store a line
public:
    void LoadFile(Point&, int&, Queue&, LTexture*, LTexture*);
    void SaveFile(Unit*, Queue&);
};
