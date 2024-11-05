#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <random>

class Bullet
{
public:
    Bullet();
    ~Bullet();
    void Update();
    void Draw(sf::RenderWindow& window);
    void Fire(float posX, float posY, float dirX, float dirY);
    int GetDamage() { return damage; }
    bool GetIsActive() { return isActive; }
    sf::Sprite GetBulletSprite() { return bulletSprite; }
    void SetBulletSprite(bool isActive);

private:
    sf::Texture* bulletTexture;
    sf::Sprite bulletSprite;
    sf::Clock* timer;

    const float BULLET_LIFETIME = 0.65f;
    const float MAX_SPREAD_ANGLE = 4.0f; 
    float initialBulletSpeed = 750.0f;
    float bulletSpeed = 650.0f;
    bool isActive = false;
    int damage = 10;
    float scaleX = 0.20f;
    float scaleY = 0.20f;
    float posX = 0.0f;
    float posY = 0.0f;
    float bulletDirX = 0.0f;
    float bulletDirY = 0.0f;

    int intRectPosX = 0;
    sf::IntRect textureRect;
    sf::Clock animationClock;

    void SetTextureValues();
    void BulletMovement();
    void BulletTimer();
    void SetRotation();
    void SetPosition();

    // Random number generator components
    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<float> dis;

    // Spread functions
    float getRandomDeviation();
    float degToRad(float degrees);
    sf::Vector2f rotateVector(const sf::Vector2f& vec, float angleRadians);
    void UpdateFameAnimation();
};
