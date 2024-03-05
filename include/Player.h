#pragma once
#include <SFML/Graphics.hpp>
#include <string>

namespace plr {
	class Player {
	private:
		sf::Vector2f position;

		int mass;

		int health;
		sf::Texture texture;
		sf::Sprite playerSprite;
		int index;


	public:
		Player();
		Player(std::string texturePath);

		void Move(sf::Vector2f vector);
	};
}