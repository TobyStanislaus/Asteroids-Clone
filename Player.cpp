#include "Player.hpp"

Player::Player()
{
    shape.setPointCount(3);

    shape.setPoint(0, {0, -20});
    shape.setPoint(1, {10, 20});
    shape.setPoint(2, {-10, 20});

    shape.setPosition({400, 300});
}

void Player::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}