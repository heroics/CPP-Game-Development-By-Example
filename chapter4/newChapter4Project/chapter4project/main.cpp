#include "Enemy.h"
#include "Hero.h"
#include "Rocket.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
using namespace sf;
// Function Prototypes
Vector2f viewSize(1024, 768);
Vector2f playerPosition;
bool isPlayerMoving = false;
VideoMode videoMode(viewSize.x, viewSize.y);
RenderWindow gameWindow(videoMode, "Chapter 4 Project - SFML");
void spawnEnemy();
void shootRocket();
bool checkCollision(Sprite sprite1, Sprite sprite2);
void reset();
// Instance Variables
Texture skyTexture;
Texture backgroundTexture;
Sprite skySprite;
Sprite backgroundSprite;
Hero player;
vector<Enemy *> enemies;
vector<Rocket *> rockets;
float currentTime;
float prevTime = 0.0f;
int score = 0;
bool gameOver = true;
Font headerFont;
Font scoreFont;
Text tutorialText;
Text scoreText;
Text headerText;
Music backgroundMusic;
SoundBuffer hitBuffer;
SoundBuffer shootBuffer;
Sound shootSound(shootBuffer);
Sound hitSound(hitBuffer);
void init()
{
    // Load Audio
    backgroundMusic.openFromFile("Assets/audio/backgroundMusic.wav");
    hitBuffer.loadFromFile("Assets/audio/hitSound.wav");
    shootBuffer.loadFromFile("Assets/audio/shootSound.wav");
    // Load textures
    skyTexture.loadFromFile("Assets/graphics/sky.png");
    backgroundTexture.loadFromFile("Assets/graphics/bg.png");
    backgroundSprite.setTexture(backgroundTexture);
    // Load Font
    headerFont.loadFromFile("Assets/fonts/gameFont.ttf");
    scoreFont.loadFromFile("Assets/fonts/scoreFont.ttf");
    // Set Game Title
    headerText.setFont(headerFont);
    headerText.setString("Tiny Bazooka");
    headerText.setCharacterSize(84);
    headerText.setFillColor(Color::Black);
    // Set Score Text
    scoreText.setFont(scoreFont);
    scoreText.setString("Score: 0");
    scoreText.setCharacterSize(45);
    scoreText.setFillColor(Color::Black);
    // Set tutorial
    tutorialText.setFont(scoreFont);
    tutorialText.setString("Press Down Arrow to Fire and Start Game, Up Arrow to Jump");
    tutorialText.setCharacterSize(18);
    tutorialText.setFillColor(Color::Black);
    // Set Bounds
    FloatRect headerBounds = headerText.getLocalBounds();
    FloatRect scoreBounds = scoreText.getLocalBounds();
    FloatRect tutorialBounds = tutorialText.getLocalBounds();
    // Set Origins for Text
    headerText.setOrigin(headerBounds.width / 2, headerBounds.height / 2);
    scoreText.setOrigin(scoreBounds.width / 2, scoreBounds.height / 2);
    tutorialText.setOrigin(tutorialBounds.width / 2, tutorialBounds.height / 2);
    // Set Position
    headerText.setPosition(Vector2f(viewSize.x * 0.5f, viewSize.y * .10f));
    scoreText.setPosition(Vector2f(viewSize.x * 0.5f, viewSize.y * .10f));
    tutorialText.setPosition(Vector2f(viewSize.x * 0.5f, viewSize.y * .20f));
    // Load Player
    player.init("Assets/graphics/hero.png", Vector2f(viewSize.x * 0.25f, viewSize.y * 0.5f), 200);
    skySprite.setTexture(skyTexture);
    // Seed the random generator
    srand((int)time(0));
}
void spawnEnemy()
{
    int random = rand() % 3;
    Vector2f enemyPosition;
    float velocity;
    switch (random)
    {
    case 0:
        enemyPosition = Vector2f(viewSize.x, viewSize.y * 0.75f);
        velocity = -400;
        break;
    case 1:
        enemyPosition = Vector2f(viewSize.x, viewSize.y * 0.60f);
        velocity = -500;
        break;
    case 2:
        enemyPosition = Vector2f(viewSize.x, viewSize.y * 0.40f);
        velocity = -650;
        break;
    default:
        printf("Incorrect Y value\n");
        break;
    }
    Enemy *ptrEnemy = new Enemy();
    ptrEnemy->init("Assets/graphics/enemy.png", enemyPosition, velocity);
    enemies.push_back(ptrEnemy);
}
void shootRocket()
{
    Rocket *rocket = new Rocket();
    rocket->init("Assets/graphics/rocket.png", player.getSprite().getPosition(), 400.0f);
    rockets.push_back(rocket);
    shootSound.play();
}
bool checkCollision(Sprite sprite1, Sprite sprite2)
{
    FloatRect shape1 = sprite1.getGlobalBounds();
    FloatRect shape2 = sprite2.getGlobalBounds();
    if (shape1.intersects(shape2))
    {
        return true;
    }
    else
    {
        return false;
    }
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
        if (event.type == Event::KeyPressed)
        {
            if (event.key.code == Keyboard::Space)
            {
                if (gameOver)
                {
                    gameOver = false;
                    reset();
                }
                else
                {
                    shootRocket();
                }
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
    currentTime += deltaTime;
    // Spawn Enemies
    if (currentTime >= prevTime + 1.125f)
    {
        spawnEnemy();
        prevTime = currentTime;
    }
    // Update Enemies
    for (unsigned int i = 0; i < enemies.size(); i++)
    {
        Enemy *enemy = enemies[i];
        enemy->update(deltaTime);
        if (enemy->getSprite().getPosition().x < 0)
        {
            enemies.erase(enemies.begin() + i);
            delete (enemy);
            backgroundMusic.stop();
            gameOver = true;
        }
    }
    // Update Rockets
    for (unsigned int i = 0; i < rockets.size(); i++)
    {
        Rocket *rocket = rockets[i];
        rocket->update(deltaTime);
        if (rocket->getSprite().getPosition().x < 0)
        {
            rockets.erase(rockets.begin() + i);
            delete (rocket);
        }
    }
    // Check for collisions between rockets and enemies
    for (unsigned int i = 0; i < rockets.size(); i++)
    {
        for (unsigned int j = 0; j < enemies.size(); j++)
        {
            Rocket *rocket = rockets[i];
            Enemy *enemy = enemies[j];
            if (checkCollision(rocket->getSprite(), enemy->getSprite()))
            {
                hitSound.play();
                score++;
                rockets.erase(rockets.begin() + i);
                enemies.erase(enemies.begin() + j);
                delete (rocket);
                delete (enemy);
                printf("Rocket X Enemy collision\n");
            }
        }
    }
    string finalScore = "Score: " + to_string(score);
    scoreText.setString(finalScore);
    FloatRect scorebounds = scoreText.getLocalBounds();
    scoreText.setOrigin(scorebounds.width / 2, scorebounds.height / 2);
    scoreText.setPosition(sf::Vector2f(viewSize.x * 0.5f, viewSize.y * 0.10f));
}
void reset()
{
    score = 0;
    currentTime = 0.0f;
    prevTime = 0.0f;
    scoreText.setString("Score: 0");
    for (Enemy *enemy : enemies)
    {
        delete (enemy);
    }
    for (Rocket *rocket : rockets)
    {
        delete (rocket);
    }
    enemies.clear();
    rockets.clear();
    backgroundMusic.play();
}
void draw()
{
    gameWindow.draw(skySprite);
    gameWindow.draw(backgroundSprite);
    gameWindow.draw(player.getSprite());
    if (gameOver)
    {
        gameWindow.draw(headerText);
        gameWindow.draw(tutorialText);
    }
    else
    {
        gameWindow.draw(scoreText);
    }

    for (Enemy *enemy : enemies)
    {
        gameWindow.draw(enemy->getSprite());
    }
    for (Rocket *rocket : rockets)
    {
        gameWindow.draw(rocket->getSprite());
    }
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
        if (!gameOver)
        {
            update(deltaTime.asSeconds());
        }
        gameWindow.clear(Color::Blue);
        draw();
        gameWindow.display();
    }
    return 0;
}
