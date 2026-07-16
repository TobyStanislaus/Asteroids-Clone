#include "Asteroid.hpp"


Asteroid::Asteroid(sf::Vector2f velocity, sf::Vector2f position) : velocity(velocity)
{
    shape.setRadius(40.f);
    shape.setOrigin({40.f, 40.f});

    shape.setPosition(position);
}

void Asteroid::update()
{
    shape.move(velocity);
}

void Asteroid::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

bool Asteroid::check_pos()
{
    sf::Vector2f pos = shape.getPosition();
    if ((pos.x<-40.f)||(pos.y<-40.f)||(pos.x>640.f)||(pos.y>840.f)){return false;}
    return true;
}