#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "sound_player.hpp"
#include "bunny.hpp"
#include "magic_ball.hpp"
#include "mushroom.hpp"
#include "background.hpp"

namespace game {
	std::unique_ptr<Game> Game::m_instance;

	Game* Game::instance() {
		if (!m_instance) {
			m_instance = std::unique_ptr<Game>(new Game);
		}

		return Game::m_instance.get();
	}

	int Game::run() {
		sf::RenderWindow window(sf::VideoMode(800, 500), "Bunny Hop");
		window.setFramerateLimit(30);

		Bunny bunny(300, 300, 10.f, 6.f);

		Mushroom mushroom;
		MagicBall magicBall;
		Background background;

		SoundPlayer::playMusic();

		m_bunny = &bunny;
		m_mushroom = &mushroom;
		m_magicBall = &magicBall;
		m_background = &background;

		mushroom.setRandomPosition();
		magicBall.setRandomPosition();

		while (window.isOpen()) {
			sf::Event event;
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::Closed) {
					window.close();
					return 0;
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
				break;
			}

			bunny.update();
			mushroom.update();
			magicBall.update();

			window.clear();

			background.update(window);

			window.draw(mushroom.getSprite());
			window.draw(magicBall.getSprite());
			window.draw(bunny.getSprite());
			window.display();
		}

		return 0;
	}

	Bunny* Game::getBunny() {
		return m_bunny;
	}

	Mushroom* Game::getMushroom() {
		return m_mushroom;
	}

	MagicBall* Game::getMagicBall() {
		return m_magicBall;
	}

	Background* Game::getBackground() {
		return m_background;
	}
}