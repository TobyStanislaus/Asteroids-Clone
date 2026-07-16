#include "Bullet.hpp"
#include <cmath>
#include <numbers>

Bullet::Bullet(sf::Vector2f position, float direction)
    :direction(direction)
{
    shape.setSize({5.f, 20.f}); // width, height

    shape.setOrigin({2.5f, 10.f}); // centre the rectangle

    shape.setPosition(position);
    float dir = direction + static_cast<float>(std::numbers::pi)/2;
    shape.setRotation(sf::radians(dir));
}

void Bullet::update(float dt)
{
    sf::Vector2f velo = {
        velocity*std::cos(direction), 
        velocity*std::sin(direction)};

    shape.move(velo);
    lifetime -= dt;
}

void Bullet::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::Vector2f Bullet::getPosition() const
{
    return shape.getPosition();
}


bool Bullet::isAlive() const
{
    return lifetime > 0.f;
}