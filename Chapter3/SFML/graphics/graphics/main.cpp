#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
    // Create the main window
    RenderWindow gameWindow(VideoMode(800, 600), "Chapter 3 - Example 1");
    // Load a sprite to display
    Texture texture;
    if (!texture.loadFromFile("avtar.png"))
        return EXIT_FAILURE;
    Sprite sprite(texture);
    // Start the game loop
    while (gameWindow.isOpen())
    {
        // Process events
        Event event;
        while (gameWindow.pollEvent(event))
        {
            // Close window : exit
            if (event.type == Event::Closed)
                gameWindow.close();
        }
        // Clear screen
        gameWindow.clear(Color::Yellow);
        // Draw the sprite
        // gameWindow.draw(sprite);
        // Update the window
        gameWindow.display();
    }
    return EXIT_SUCCESS;
}
