#pragma once

#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::ConvexShape shape;

    sf::Vector2f velocity;
    float rotation = 0;
    void wrap();
public:
    Player();

    void update();
    void draw(sf::RenderWindow& window);
};