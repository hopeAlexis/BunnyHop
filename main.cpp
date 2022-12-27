#include <iostream>
#include <SFML/Graphics.hpp>
#include "bunny.hpp"

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(500, 500), "Bunny Hop");
    game::Bunny bunny(150.f, 300.f, 10.f);
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
                switch(event.key.code)
                {
                    case sf::Keyboard::Up:
                    {
                        if (bunny.checkCollision(bunny.getX(), bunny.getY() - bunny.getVel()))
                        {
                            bunny.setPosition(bunny.getX(), bunny.getY() - bunny.getVel());
                        }
                        break;
                    }

                    case sf::Keyboard::Right:
                    {
                        if (bunny.checkCollision(bunny.getX() + bunny.getVel(), bunny.getY()))
                        {
                            bunny.setPosition(bunny.getX() + bunny.getVel(), bunny.getY());
                            
                        }break;
                    }

                    case sf::Keyboard::Left:
                    {
                        if (bunny.checkCollision(bunny.getX() - bunny.getVel(), bunny.getY()))
                        {
                            bunny.setPosition(bunny.getX() - bunny.getVel(), bunny.getY());
                            
                        }break;
                    }
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(bunny.getSprite());
        window.display();
    }

    return 0;
}