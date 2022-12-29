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

    float cooldown = 1;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();            
            
            if(event.type == sf::Event::KeyPressed)
            {
                switch(event.key.code)
                {
                    case sf::Keyboard::Space:
                    {
                        if (!bunny.isHop())
                        {
                            bunny.setIsHop(true);
                            cooldown = 1;
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
                case sf::Keyboard::Left:
                {
                    bunny.changeSprite(1);
                    break;
                }
                }
            }
        }

        if (bunny.isHop())
            cooldown = bunny.hop(cooldown);

        window.draw(bg_sprite);
        window.draw(bunny.getSprite());
        window.display();
    }

    return 0;
}