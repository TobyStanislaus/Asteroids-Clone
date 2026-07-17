#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::RectangleShape shape;
    float velocity=0.2f;
    float direction;
    float lifetime = 3.f;
    float radius = 20.f;

public:
    Bullet(sf::Vector2f position, float rotation);

    void update(float dt);
    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;
    bool isAlive() const;
    float getRadius() const;
};