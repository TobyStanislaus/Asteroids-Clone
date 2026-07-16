#pragma once

#include <SFML/Graphics.hpp>

class Asteroid
{
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
public:
    Asteroid(sf::Vector2f velo, sf::Vector2f position);

    void update();
    void draw(sf::RenderWindow& window);
    bool check_pos();
    
    sf::Vector2f getPosition() const;
    void setPosition(sf::Vector2f position);

    sf::Vector2f getVelocity() const;
    void setVelocity(sf::Vector2f velocity);

};