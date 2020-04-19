#include "hero.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Vector2f viewSize(1024, 768);
Vector2f playerPosition;
bool isPlayerMoving = false;
VideoMode videoMode(viewSize.x, viewSize.y);
RenderWindow gameWindow(videoMode, "Dark Age of Kirktus - Damnation Vade Mecum");

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
    skySprite.setTexture(skyTexture);
}
void updateInput()
{
    Event event;
    while (gameWindow.pollEvent(event))
    {
        if (event.key.code == Keyboard::Escape || event.type == Event::Closed)
        {
            gameWindow.close();
        }
    }
}
void update(float deltaTime)
{
}
void draw()
{
    gameWindow.draw(skySprite);
    gameWindow.draw(backgroundSprite);
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
        gameWindow.clear(Color::Blue);
        draw();
        gameWindow.display()
    }
    return 0;
}