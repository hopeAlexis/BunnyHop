#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.hpp"

using namespace game;

Game* Game::m_instance = nullptr;

Game::Game() {}

Game::~Game() {
	delete m_instance;
}

Game* Game::instance() {
	if (m_instance == nullptr) {
		m_instance = new Game;
	}
	return m_instance;
}

int Game::run() {
	sf::RenderWindow window(sf::VideoMode(800, 500), "Bunny Hop");
	window.setFramerateLimit(30);

	sf::Texture texture;
	texture.loadFromFile("assets\\sky.png");

	sf::Sprite backgroundSprite;
	backgroundSprite.setTexture(texture);

	Bunny bunny(300, 300, 10.f, 6.f);

	float cooldown = 1.f;

	while (window.isOpen()) {
		// Handle window events
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}

			if (event.type == sf::Event::KeyReleased) {
				if (bunny.getState() != BunnyState::Hopping) {
					bunny.setState(BunnyState::Idle);
				}
			}
		}

		// Handle pressed keys
		if (bunny.getState() != BunnyState::Hopping) {
			if (cooldown != 1.f) cooldown = 1.f;

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				bunny.moveLeft();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				bunny.moveRight();
			} if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				bunny.hop();
			}
		}
		else {
			cooldown = bunny.handleHop(cooldown);
		}

		// Render
		window.clear();
		window.draw(backgroundSprite);
		window.draw(bunny.getSprite());
		window.display();
	}

	return 0;
}