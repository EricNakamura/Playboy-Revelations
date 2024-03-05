#include <Player.h>
#include <iostream>

plr::Player::Player() {
}

plr::Player::Player(std::string texturePath) {
	sf::Texture texture;

	if (!texture.loadFromFile(texturePath)) {
		std::cerr << "Impossible to load " << texturePath << std::endl; 
	}

	this->texture = texture;
}