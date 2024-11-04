#include "Bullet.h"
#include <iostream>
#include "../Utilities/WrappingScreenUtility.h"
#include "../Utilities/Framerate.h"
#include "../Utilities/ResourceManager.h"
#include "../Utilities/RandomUtility.h"

Bullet::Bullet() : gen(rd()), dis(-MAX_SPREAD_ANGLE, MAX_SPREAD_ANGLE)
{
    this->bulletTexture = ResourceManager::GetBulletTexture();
    timer = new sf::Clock;
    SetTextureValues();
}

Bullet::~Bullet()
{
    if (timer != nullptr)
    {
        delete timer;
        timer = nullptr;
    }
}

void Bullet::SetTextureValues()
{
    if (bulletTexture != nullptr)
    {
        bulletSprite.setTexture(*bulletTexture);
        bulletSprite.setScale(scaleX, scaleY);
        sf::FloatRect bounds = bulletSprite.getLocalBounds();
        bulletSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
    }
    else
        std::cout << "DEBUG: Error!!!!!!!! LOADING BULLET TEXTURE" << std::endl;
}

void Bullet::Fire(float posX, float posY, float dirX, float dirY)
{
    // Normalize the original direction vector
    sf::Vector2f originalDir(dirX, dirY);
    float length = std::sqrt(originalDir.x * originalDir.x + originalDir.y * originalDir.y);
    if (length != 0)
        originalDir /= length;
    else
        originalDir = sf::Vector2f(1.0f, 0.0f); // Default direction if zero vector

    // Get a random deviation in degrees and convert to radians
    float deviationDegrees = getRandomDeviation();
    float deviationRadians = degToRad(deviationDegrees);

    // Rotate the original direction by the deviation angle
    sf::Vector2f deviatedDir = rotateVector(originalDir, deviationRadians);

    // Set the bullet's direction
    this->bulletDirX = deviatedDir.x;
    this->bulletDirY = deviatedDir.y;

    this->posX = posX;
    this->posY = posY;
    isActive = true;
    timer->restart();
    SetPosition();
    SetRotation();
    BulletTimer();
}

//Get random deviation
float Bullet::getRandomDeviation()
{
    return dis(gen); // Returns a random float between -MAX_SPREAD_ANGLE and +MAX_SPREAD_ANGLE
}

//Convert degrees to radians
float Bullet::degToRad(float degrees)
{
    return degrees * (3.14159265f / 180.0f);
}

//Rotate a vector by a given angle in radians
sf::Vector2f Bullet::rotateVector(const sf::Vector2f& vec, float angleRadians)
{
    float cosA = std::cos(angleRadians);
    float sinA = std::sin(angleRadians);
    return sf::Vector2f(
        vec.x * cosA - vec.y * sinA,
        vec.x * sinA + vec.y * cosA
    );
}

// Set rotation based on direction
void Bullet::SetRotation()
{
    // Adjust based on sprite orientation
    float angleInRadians = std::atan2(bulletDirY, bulletDirX);
    float angleDegrees = angleInRadians * 180 / 3.14159265f;
    bulletSprite.setRotation(angleDegrees + 90); 
}

void Bullet::SetPosition()
{
    bulletSprite.setPosition(posX, posY);
}

void Bullet::BulletMovement()
{
    bulletSpeed = initialBulletSpeed;
    bulletSprite.move(bulletDirX * bulletSpeed * Framerate::getDeltaTime(), bulletDirY * bulletSpeed * Framerate::getDeltaTime());
    posX = bulletSprite.getPosition().x;
    posY = bulletSprite.getPosition().y;
}

void Bullet::BulletTimer()
{
    if (timer->getElapsedTime().asSeconds() > BULLET_LIFETIME)
    {
        isActive = false;
    }
}

void Bullet::Update()
{
    if (!isActive)
        return;
    BulletMovement();
    BulletTimer();
    WrapAroundScreen(posX, posY, bulletDirX, bulletDirY, 5.0f, bulletSprite);
    bulletSprite.setPosition(posX, posY);
}

void Bullet::Draw(sf::RenderWindow& window)
{
    if (!isActive)
        return;
    window.draw(bulletSprite);
}

void Bullet::SetBulletSprite(bool isActive)
{
    this->isActive = isActive;

    if (!isActive)
    {
        bulletSprite.setPosition(-100, -100);
        bulletSpeed = 0.0f;
    }
}
