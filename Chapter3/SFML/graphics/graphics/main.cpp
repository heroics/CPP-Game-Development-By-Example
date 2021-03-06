#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    //Create a view
    Vector2f viewSize(1024, 768);
    VideoMode videoMode(viewSize.x, viewSize.y);
    // Create the main window
    RenderWindow gameWindow(videoMode, "Chapter 3 - Example 2");

    // Load a sprite to display
    Texture texture;
    if (!texture.loadFromFile("avtar.png"))
        return EXIT_FAILURE;
    Sprite sprite(texture);

    // Draw a rectangle
    RectangleShape myRectangle(Vector2f(500.0f, 300.0f));
    myRectangle.setFillColor(Color::Green);
    myRectangle.setPosition(viewSize.x / 2, viewSize.y / 2);
    myRectangle.setOrigin(Vector2f(myRectangle.getSize().x / 2, myRectangle.getSize().y / 2));

    // Draw a circle
    CircleShape myCircle(100);
    myCircle.setFillColor(Color::Blue);
    myCircle.setPosition(viewSize.x / 2, viewSize.y / 2);
    myCircle.setOrigin(Vector2f(myCircle.getRadius(), myCircle.getRadius()));

    // Draw a triangle
    ConvexShape myTriangle;
    myTriangle.setPointCount(3);
    myTriangle.setPoint(0, Vector2f(-100.0f, 0));
    myTriangle.setPoint(1, Vector2f(0.0f, -100));
    myTriangle.setPoint(2, Vector2f(100.0f, 0));
    myTriangle.setFillColor(Color::Magenta);
    myTriangle.setPosition(viewSize.x / 2, viewSize.y / 2);
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
        gameWindow.clear(Color::Black);
        // Draw the sprite
        gameWindow.draw(myRectangle);
        gameWindow.draw(myCircle);
        gameWindow.draw(myTriangle);
        // Update the window
        gameWindow.display();
    }
    return EXIT_SUCCESS;
}
