#include <SFML/Graphics.hpp>
using namespace sf;

Vector2f viewSize(1024, 768);
VideoMode videoMode(viewSize.x, viewSize.y);
RenderWindow gameWindow(videoMode, "Dark Age of Kirktus");
Texture playerTexture;
Sprite playerSprite;
void init()
{
    playerTexture.loadFromFile("assets/avatar.png");
    playerSprite.setTexture(playerTexture);
}
void draw()
{
    gameWindow.draw(playerSprite);
}
int main()
{
    init();
    while (gameWindow.isOpen())
    {
        gameWindow.clear(Color::Blue);
        draw();
        gameWindow.display();
    }
    return 0;
}