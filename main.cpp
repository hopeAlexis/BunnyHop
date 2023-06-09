#include <iostream>
#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "bunny.hpp"

int main() {
    return game::Game::instance()->run();
}