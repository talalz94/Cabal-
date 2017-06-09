#pragma once
#include "Point.h"
#include "LTexture.h"
#include "SDL.h"

enum {RIGHT, LEFT, UP, DOWN, IDLE, MOVE_LEFT, MOVE_RIGHT, SHOOT, DIE, ENEMY, BOSS, SELF};

class Unit
{
protected:
    bool alive;
    int health;
    Point position;
    float speedx;
    float speedy;
    int width;
    int height;
    int type;
    long int moves;
    int animation;
    int fire;
    int delay;
    int friction;

    LTexture* image;
    LTexture* spriteSheetTexture;
    SDL_Rect clips[40];

public:
    Unit(LTexture*, const Point&);
    Unit();
    virtual ~Unit();
    virtual void Render(long int&, SDL_Renderer*);
    virtual void Move();
    virtual void Move(int);
    virtual void Move(int, int);
    virtual void Move(long int&);
    int GetType();
    void SetAlive(bool);
    virtual bool GetAlive();
    void SetPosition(Point&);
    virtual Point GetPosition();
    virtual void SetState(int);
    int Attack();
    int GetState();
    int Getx();
    int Gety();
    void SetHealth(int);
    int GetHealth();
    int top();
    int bottom();
    int left();
    int right();
    void Setfire(int);
};
