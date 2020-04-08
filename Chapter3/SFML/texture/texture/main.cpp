#include <SFML/Graphics.hpp>
using namespace sf;

Vector2f viewSize(1024, 768);
VideoMode videoMode(viewSize.x, viewSize.y);
RenderWindow gameWindow(videoMode, "Dark Age of Kirktus");
Texture playerTexture;
Texture backgroundTexture;
Sprite backgroundSprite;
Sprite playerSprite;
Vector2f playerPosition;
bool isPlayerMoving = false;

void init()
{
    playerTexture.loadFromFile("assets/avatar.png");
    playerSprite.setTexture(playerTexture);
    backgroundTexture.loadFromFile("assets/background.png");
    backgroundSprite.setTexture(backgroundTexture);
}
void draw()
{
    gameWindow.draw(backgroundSprite);
    gameWindow.draw(playerSprite);
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
        // Player Movement
        if (event.type == Event::KeyPressed)
        {
            if (event.key.code == Keyboard::Right)
            {
                isPlayerMoving = true;
            }
        }
        if (event.type == Event::KeyReleased)
        {
            if (event.key.code == Keyboard::Right)
            {
                isPlayerMoving = false;
            }
        }
    }
}
void update(float direction)
{
    if (isPlayerMoving)
    {
        playerSprite.move(50.0f * direction, 0);
    }
}
int main()
{
    Clock clock;
    init();
    while (gameWindow.isOpen())
    {
        // Update Input
        updateInput();
        Time time = clock.restart();
        update(time.asSeconds());
        gameWindow.clear(Color::Blue);
        draw();
        gameWindow.display();
    }
    return 0;
}
