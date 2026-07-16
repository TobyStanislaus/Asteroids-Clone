#include <SFML/Graphics.hpp>
#include "Player.hpp"

int main()
{
    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Asteroids"
    );

    Player player;

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();

        player.update();

        player.draw(window);

        window.display();
    }
}