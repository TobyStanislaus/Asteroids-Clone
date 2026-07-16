#pragma once

#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::ConvexShape shape;

    sf::Vector2f velocity;
    float rotation = 0;
    float radius = 23.f;
    void wrap();
public:
    Player();

    void update();
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition() const;
    float getRadius() const;
    sf::Vector2f getVelocity() const;
    float getDirection() const;

};