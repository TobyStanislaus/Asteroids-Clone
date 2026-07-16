#pragma once

#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::RectangleShape shape;
    float velocity=0.2f;
    float direction;

public:
    Bullet(sf::Vector2f position, float rotation);

    void update();
    void draw(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;
};