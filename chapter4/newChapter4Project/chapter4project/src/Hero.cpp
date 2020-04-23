#include "Hero.h"
#include <SFML/Graphics.hpp>
#include <string>
Hero::Hero()
{
    //ctor
}
Hero::~Hero()
{
    //dtor
}
void Hero::init(string textureName, int frameCount, float animationDuration, Vector2f position, float mass)
{
    this->position = position;
    this->mass = mass;
    this->isGrounded = false;
    this->frameCount = frameCount;
    this->animationDuration = animationDuration;
    this->spriteSize = Vector2i(92, 126);
    // Load the texture
    this->texture.loadFromFile(textureName.c_str());
    // Create Sprite and Attach a Texture
    this->sprite.setTexture(this->texture);
    this->sprite.setTextureRect(IntRect(0, 0, this->spriteSize.x, this->spriteSize.y));
    this->sprite.setPosition(this->position);
    this->sprite.setOrigin(this->spriteSize.x / 2, this->spriteSize.y / 2);
}

void Hero::update(float deltaTime)
{
    // Animate Sprite
    this->elapsedTime += deltaTime;
    int animateFrame = static_cast<int>((this->elapsedTime / this->animationDuration) * this->frameCount) % this->frameCount;
    this->sprite.setTextureRect(IntRect(animateFrame * this->spriteSize.x, 0, this->spriteSize.x, this->spriteSize.y));
    this->velocity -= this->mass * this->gravity * deltaTime;
    this->position.y -= this->velocity * deltaTime;
    this->sprite.setPosition(this->position);
    if (this->position.y >= 768 * 0.75f)
    {
        this->position.y = 768 * 0.75;
        this->velocity = 0;
        this->isGrounded = true;
        this->jumpCount = 0;
    }
}

void Hero::jump(float velocity)
{
    if (jumpCount < 2)
    {
        jumpCount++;
        this->velocity = velocity;
        this->isGrounded = false;
    }
}

Sprite Hero::getSprite()
{
    return this->sprite;
}
