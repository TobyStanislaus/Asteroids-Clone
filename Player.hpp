#pragma once

#include <SFML/Graphics.hpp>

class Player
{
private:
    sf::ConvexShape shape;

public:
    Player();

    void draw(sf::RenderWindow& window);
};