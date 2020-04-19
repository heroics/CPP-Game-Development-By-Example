#include "Hero.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

Vector2f viewSize(1024, 768);
Vector2f playerPosition;
bool isPlayerMoving = false;
VideoMode videoMode(viewSize.x, viewSize.y);
RenderWindow gameWindow(videoMode, "Chapter 4 Project - SFML");

Texture skyTexture;
Texture backgroundTexture;
Sprite skySprite;
Sprite backgroundSprite;
Hero player;

void init()
{
    skyTexture.loadFromFile("Assets/graphics/sky.png");
    backgroundTexture.loadFromFile("Assets/graphics/bg.png");
    backgroundSprite.setTexture(backgroundTexture);
    player.init("Assets/graphics/hero.png", Vector2f(viewSize.x * 0.25f, viewSize.y * 0.5f), 200);
    skySprite.setTexture(skyTexture);
}
void updateInput()
{
    Event event;
    while (gameWindow.pollEvent(event))
    {
        if (event.type == Event::KeyPressed)
        {
            if (event.key.code == Keyboard::Up)
            {
                player.jump(750.0f);
            }
        }
        if (event.key.code == Keyboard::Escape || event.type == Event::Closed)
        {
            gameWindow.close();
        }
    }
}
void update(float deltaTime)
{
    player.update(deltaTime);
}
void draw()
{
    gameWindow.draw(skySprite);
    gameWindow.draw(backgroundSprite);
    gameWindow.draw(player.getSprite());
}

int main()
{
    Clock gameClock;
    gameWindow.setFramerateLimit(60);
    init();
    while (gameWindow.isOpen())
    {
        updateInput();
        Time deltaTime = gameClock.restart();
        update(deltaTime.asSeconds());
        gameWindow.clear(Color::Blue);
        draw();
        gameWindow.display();
    }
    return 0;
}
