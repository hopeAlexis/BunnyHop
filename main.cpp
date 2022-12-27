#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(500, 500), "Bunny Hop");
    float x0, y0;
    x0 = 150.f;
    y0 = 300.f;

    while (window.isOpen())
    {

        sf::Texture texture;
        texture.loadFromFile("chonk.png", sf::IntRect(0, 0, 200, 200));

        sf::Sprite sprite;
        sprite.setTexture(texture);

        sprite.setPosition(sf::Vector2f(x0, y0));
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
                    y0 -= 4.f;
                    sprite.setPosition(sf::Vector2f(x0, y0));
                    std::cout << x0 << " " << y0;
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(sprite);
        window.display();
    }

    return 0;
}