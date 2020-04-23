#ifndef ROCKET_H
#define ROCKET_H
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class Rocket
{
public:
    Rocket();
    virtual ~Rocket();
    void init(string textureName, Vector2f position, float velocity);
    void update(float deltaTime);
    Sprite getSprite();

private:
    Texture texture;
    Sprite sprite;
    Vector2f position;
    float velocity;
};

#endif // ROCKET_H
