#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Asteroid.hpp"
#include "Bullet.hpp"
#include <random>
#include <iostream>
#include <algorithm>

std::random_device rd;
std::mt19937 gen(rd());


template<typename T1, typename T2>
bool checkCollision(const T1& a, const T2& b)
{
    sf::Vector2f diff = a.getPosition() - b.getPosition();

    float distanceSquared = diff.x * diff.x + diff.y * diff.y;

    float radiusSum = a.getRadius() + b.getRadius();

    return distanceSquared < radiusSum * radiusSum;
}

int main()
{
    sf::Clock asteroidClock;
    sf::Clock bulletClock;

    std::vector<Asteroid> asteroids;
    std::vector<Bullet> bullets;
    sf::Clock clock;

    sf::RenderWindow window(
        sf::VideoMode({800, 600}),
        "Asteroids"
    );

    std::uniform_real_distribution<float> xPos(0.f, 800.f);
    std::uniform_real_distribution<float> velocity(-0.1f, 0.1f);

    Player player;
    Asteroid asteroid({velocity(gen), velocity(gen)},{xPos(gen), -40.f});
    bool running=true;

    asteroids.emplace_back(asteroid);

    while (window.isOpen()&&running)
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        if (asteroidClock.getElapsedTime().asSeconds() >= 0.75f)
        {  
            asteroids.emplace_back(
                sf::Vector2f(velocity(gen), velocity(gen)),  
                sf::Vector2f(xPos(gen), -40.f)  
            );
            asteroidClock.restart();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) && bulletClock.getElapsedTime().asSeconds() >=0.5f){
            Bullet bullet(player.getPosition(), player.getDirection());
            bullets.emplace_back(bullet);
            bulletClock.restart();
        }
        
        window.clear();
        player.update();
        player.draw(window);


        // ALL of the bullet stuff


        float dt = clock.restart().asSeconds();
        for (auto& bullet : bullets)
        {
            bullet.update(dt);
            bullet.draw(window);

            asteroids.erase(
                std::remove_if(
                    asteroids.begin(),
                    asteroids.end(),
                    [bullet](Asteroid& asteroid)
                    {
                        return checkCollision(bullet, asteroid);
                    }),

                    asteroids.end()
            );
        }

        bullets.erase(
            std::remove_if(
                bullets.begin(),
                bullets.end(),
                [](Bullet& bullet)
                {
                    return !bullet.isAlive();
                }),
            bullets.end()
        );
        //



        for (auto& asteroid : asteroids)
        {
            asteroid.update();
            if (checkCollision(player, asteroid)){running=false;}

            asteroid.draw(window);
        }

        window.display();
    }
    std::cout<<"You Lose!";
}