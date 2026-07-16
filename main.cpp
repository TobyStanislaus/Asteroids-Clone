#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Asteroid.hpp"
#include <random>
#include <iostream>

std::random_device rd;
std::mt19937 gen(rd());


bool checkCollision(Player& ship, Asteroid& asteroid)
{
    sf::Vector2f diff = ship.getPosition() - asteroid.getPosition();

    float distanceSquared = diff.x * diff.x + diff.y * diff.y;

    float radiusSum = ship.getRadius() + asteroid.getRadius();

    return distanceSquared < radiusSum * radiusSum;
}

int main()
{
    sf::Clock asteroidClock;
    std::vector<Asteroid> asteroids;

    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Asteroids"
    );

    std::uniform_real_distribution<float> xPos(0.f, 800.f);
    std::uniform_real_distribution<float> velocity(-0.1f, 0.1f);

    Player player;
    Asteroid asteroid(
    {velocity(gen), velocity(gen)},
    {xPos(gen), -40.f}
    );
    bool go=true;
    asteroids.emplace_back(asteroid);

    while (window.isOpen()&&go)
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (asteroidClock.getElapsedTime().asSeconds() >= 5.f)
        {
            asteroids.emplace_back(
                sf::Vector2f(velocity(gen), velocity(gen)),  
                sf::Vector2f(xPos(gen), -40.f)  
            );
            asteroidClock.restart();
        }


        window.clear();
        player.update();

        for (auto& asteroid : asteroids)
        {
            asteroid.update();
            if (checkCollision(player, asteroid)){go=false;}
            asteroid.draw(window);
        }

        player.draw(window);

        window.display();
    }
    std::cout<<"You Lose!";
}