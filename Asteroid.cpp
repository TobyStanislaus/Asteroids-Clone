#include "Asteroid.hpp"


Asteroid::Asteroid(sf::Vector2f velocity, sf::Vector2f position) : velocity(velocity)
{
    shape.setRadius(20.f);
    shape.setOrigin({40.f, 40.f});

    shape.setPosition(position);
}


void Asteroid::update()
{
    shape.move(velocity);
    wrap();
}


void Asteroid::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}


bool Asteroid::check_pos()
{
    sf::Vector2f pos = shape.getPosition();
    if ((pos.x<-40.f)||(pos.y<-40.f)||(pos.x>880.f)||(pos.y>680.f)){return false;}
    return true;
}



sf::Vector2f Asteroid::getPosition() const
{
    return shape.getPosition();
}

float Asteroid::getRadius() const
{
    return shape.getRadius();
}


void Asteroid::wrap()
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
