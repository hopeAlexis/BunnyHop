#include <iostream>
#include <SFML/Graphics.hpp>
#include "bunny.hpp"

int main()
{
    unsigned int w_width = 800, w_height = 500;
    sf::RenderWindow window(sf::VideoMode(w_width, w_height), "Bunny Hop");
    game::Bunny bunny((w_width - 200)/2, w_height - 200, 5.f);
;
    while (window.isOpen())
    {
        window.clear(sf::Color::White);
        sf::Texture bg_texture;
        bg_texture.loadFromFile("sky.png", sf::IntRect(0, 0, w_width, w_height));
        sf::Sprite bg_sprite;
        bg_sprite.setTexture(bg_texture);
        int jumpCount = 10;

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
                        float vel = 1;
                        while (vel >= -1)
                        {
                            int neg = 1;
                            if (vel < 0)
                                neg = -1;
                            bunny.setPosition(bunny.getX(), bunny.getY() - (bunny.getVel() * bunny.getVel()) * 0.5 * neg);
                            window.draw(bg_sprite);
                            window.draw(bunny.getSprite());
                            window.display();
                            vel -= 0.1;
                            std::cout << vel << "\n";
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
        }

        window.draw(bg_sprite);
        window.draw(bunny.getSprite());
        window.display();
    }

    return 0;
}