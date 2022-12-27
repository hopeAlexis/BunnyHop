#include <iostream>
#include <SFML/Graphics.hpp>
#include "bunny.hpp"

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(500, 500), "Bunny Hop");
    game::Bunny bunny(150.f, 300.f, 5.f);
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();            
            
            if(event.type == sf::Event::KeyPressed)
            {
                std::cout << "pressed! ";
                if (event.key.code == sf::Keyboard::Space)
                {
                    bunny.setPosition(bunny.getX(), bunny.getY() - bunny.getVel());
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(bunny.getSprite());
        window.display();
    }

    return 0;
}