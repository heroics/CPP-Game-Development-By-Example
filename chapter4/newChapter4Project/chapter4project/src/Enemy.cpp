#include "Enemy.h"
#include <SFML/Graphics.hpp>
#include <string>

Enemy::Enemy()
{
    //ctor
}

Enemy::~Enemy()
{
    //dtor
}

void Enemy::init(string textureName, Vector2f position, float velocity)
{
    this->velocity = velocity;
    this->position = position;
    this->texture.loadFromFile(textureName.c_str());

    // Create Sprite and attach to a texture
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(this->position);
    this->sprite.setOrigin(this->texture.getSize().x / 2, this->texture.getSize().y / 2);
}

void Enemy::update(float deltaTime)
{
    this->sprite.move(this->velocity * deltaTime, 0);
}

Sprite Enemy::getSprite()
{
    return this->sprite;
}
