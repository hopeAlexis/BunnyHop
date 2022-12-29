#include <iostream>
#include <SFML/Graphics.hpp>
#include "bunny.hpp"

int main()
{
    unsigned int w_width = 800, w_height = 500;
    sf::RenderWindow window(sf::VideoMode(w_width, w_height), "Bunny Hop");
    window.setFramerateLimit(60);
    sf::Texture bg_texture;
    bg_texture.loadFromFile("sky.png", sf::IntRect(0, 0, w_width, w_height));
    sf::Sprite bg_sprite;
    bg_sprite.setTexture(bg_texture);

    game::Bunny bunny((w_width - 200)/2, w_height - 200, 10.f, 6.f);

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
                    case sf::Keyboard::Space:
                    {
                        std::cout << "Entered hop! " << bunny.getY() << "\n";
                        float cooldown = 1;
                        bunny.changeSprite(4);
                        while (cooldown >= -1)
                        {
                            int neg = 1;
                            if (cooldown < 0)
                            {
                                neg = -1;
                                bunny.changeSprite(1);
                            }
                            bunny.setPosition(bunny.getX(), bunny.getY() - (bunny.getHopVel() * bunny.getHopVel()) * 0.5 * neg);
                            window.draw(bg_sprite);
                            window.draw(bunny.getSprite());
                            window.display();
                            cooldown -= 0.1;
                            std::cout << cooldown << "\n";
                        }
                        break;
                    }

                    case sf::Keyboard::Right:
                    {
                        bunny.right();
                        break;
                    }

                    case sf::Keyboard::Left:
                    {
                        bunny.left();
                        break;
                    }
                }
            }
            if (event.type == sf::Event::KeyReleased)
            {
                switch(event.key.code)
                {
                case sf::Keyboard::Right:
                {
                    bunny.changeSprite(1);
                    break;
                }

                case sf::Keyboard::Left:
                {
                    bunny.changeSprite(1);
                    break;
                }
                }
            }
        }

        window.draw(bg_sprite);
        window.draw(bunny.getSprite());
        window.display();
    }

    return 0;
}