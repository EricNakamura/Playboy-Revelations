#include <Player.h>
#include <iostream>

plr::Player::Player()
{
}

plr::Player::Player(std::string texturePath)
{
	sf::Texture temp;
	if (!temp.loadFromFile(texturePath)) {
		std::cerr << "Impossible to load " << texturePath << std::endl;
	}
}

void plr::Player::Move(sf::Vector2f vector)
{
}
