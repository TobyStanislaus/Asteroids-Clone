#include "Player.hpp"
#include <cmath>
#include <numbers>

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

void Player::update()
{
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {  
        float angle = shape.getRotation().asRadians() + (std::numbers::pi / 2);
        if (std::abs(velocity.x-0.0001f*std::cos(angle)) < 0.5f){velocity.x -= 0.0001f * std::cos(angle);}
        if (std::abs(velocity.y-0.0001f*std::sin(angle)) < 0.5f){velocity.y -= 0.0001f * std::sin(angle);}
        
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        shape.rotate(sf::degrees(-0.2));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        shape.rotate(sf::degrees(0.2));
    }

    velocity *= 0.9999f;
    shape.move(velocity);
    wrap();
}


sf::Vector2f Player::getPosition() const
{
    return shape.getPosition();
}

float Player::getRadius() const
{
    return radius;
}


void Player::wrap()
{
    sf::Vector2f position = shape.getPosition();

    float width = 800;
    float height = 600;

    float margin = 40;

    if (position.x < -margin)
    {
        position.x = width + margin;
    }
    else if (position.x > width + margin)
    {
        position.x = -margin;
    }

    if (position.y < -margin)
    {
        position.y = height + margin;
    }
    else if (position.y > height + margin)
    {
        position.y = -margin;
    }

    shape.setPosition(position);
}