#include <SFML/Graphics.hpp>
#ifndef HERO_H
#define HERO_H
using namespace std;
using namespace sf;

class Hero
{
public:
    Hero();
    virtual ~Hero();
    void init(string textureName, Vector2f position, float mass);
    void update(float deltaTime);
    void jump(float velocity);
    Sprite getSprite();

protected:
private:
    Texture texture;
    Sprite sprite;
    Vector2f position;
    int jumpCount = 0;
    float mass;
    float velocity;
    const float gravity = 9.81f;
    bool isGrounded;
};

#endif // HERO_H
