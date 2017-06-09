#include "Enemy.h"

Enemy::Enemy()
{

}

Enemy::Enemy(LTexture* image, Point& position, int animation):Unit(image, position)
{
    this->animation = animation;
}

Enemy::~Enemy()
{

}

void Enemy::Render(long int& frame, SDL_Renderer* gRenderer)
{

}

void Enemy::Move()
{

}

bool Enemy::GetAlive()
{
    return alive;
}
