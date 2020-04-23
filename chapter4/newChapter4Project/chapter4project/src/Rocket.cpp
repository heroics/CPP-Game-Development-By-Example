#include "Rocket.h"
#include <SFML/Graphics.hpp>
#include <string>

Rocket::Rocket()
{
    //ctor
}

Rocket::~Rocket()
{
    //dtor
}

void Rocket::init(string textureName, Vector2f position, float velocity)
{
    // Load Texture
    this->texture.loadFromFile(textureName.c_str());
    this->position = position;
    this->velocity = velocity;
    // Create Sprite and attach to a texture
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(this->position);
    this->sprite.setOrigin(this->texture.getSize().x / 2, this->texture.getSize().y / 2);
}

void Rocket::update(float deltaTime)
{
    this->sprite.move(this->velocity * deltaTime, 0);
}
Sprite Rocket::getSprite()
{
    return this->sprite;
}

