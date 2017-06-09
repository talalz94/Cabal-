#pragma once
#include "Node.h"
#include "Point.h"
#include "Enemy.h"
#include "Explosion.h"
#include "EBullet.h"
#include "Powerups.h"
#include "Missiles.h"
#include <SDL_mixer.h>
#include <stdlib.h>
#include <iostream>

class Queue
{
    Node* head;
    Node* tail;
public:
    Queue();
    ~Queue();
    void Enqueue(Unit*);
    void Update(long int&, SDL_Renderer*, Unit*, LTexture*, LTexture*, Mix_Chunk*, Mix_Chunk*);
    void Save(FILE*);
    void Collision(LTexture*, LTexture*, LTexture*, Unit*, Mix_Chunk*, Mix_Chunk*, int*);
};
