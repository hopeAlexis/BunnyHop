#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.hpp"

using namespace game;

Game::Game() :
	window(sf::VideoMode(w_width, w_height), "Bunny Hop"),
	bg_texture(),
	bg_sprite(),
	bunny((w_width - 200) / 2, w_height - 200, 10.f, 6.f),
	cooldown(1)
{
	window.setFramerateLimit(30);
	bg_texture.loadFromFile("assets/sky.png", sf::IntRect(0, 0, w_width, w_height));
	bg_sprite.setTexture(bg_texture);
}

void Game::run()
{
	while (window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();


		if (event.type == sf::Event::KeyReleased)
		{
			handleKeyReleased(event.key.code);
		}
	}


}

void Game::handleKeyPressed()
{

	if (bunny.isHop())
	{
		return;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (!bunny.isHop())
		{
			bunny.setIsHop(true);
			cooldown = 1;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		bunny.moveRight();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		bunny.moveLeft();
	}
}

void Game::handleKeyReleased(sf::Keyboard::Key key)
{
	switch (key)
	{
	case sf::Keyboard::Right:
	case sf::Keyboard::Left:
	{
		bunny.changeSprite(1);
		break;
	}
	}
}

void Game::update()
{
	if (bunny.isHop())
		cooldown = bunny.hop(cooldown);

	handleKeyPressed();
}

void Game::render()
{
	window.clear();
	window.draw(bg_sprite);
	window.draw(bunny.getSprite());
	window.display();
}
