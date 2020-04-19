#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Graphics.hpp>
#include <string>
using namespace std;
using namespace sf;

class Enemy
{
public:
    Enemy();
    virtual ~Enemy();
    void init(string textureName, Vector2f position, float speed);
    void update(float deltaTime);
    Sprite getSprite();

private:
    Texture texture;
    Sprite sprite;
    Vector2f position;
    float velocity;
};

#endif // ENEMY_H
