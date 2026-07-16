#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Asteroid.hpp"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());


int main()
{
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Asteroids"
    );

    std::uniform_real_distribution<float> xPos(0.f, 800.f);

    std::uniform_real_distribution<float> velocity(0.f, 0.3f);

    Player player;
    Asteroid asteroid(
    {velocity(gen), velocity(gen)},
    {xPos(gen), 0}
    );


    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        player.update();
        asteroid.update();

        player.draw(window);
        asteroid.draw(window);

        window.display();
    }
}