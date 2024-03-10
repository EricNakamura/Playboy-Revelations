#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <Atributes.h>

namespace plr {
	class Player {
	private:
		void DefaultInit();

		sf::Vector2f position = sf::Vector2f(0,0);
		sf::Vector2f size = sf::Vector2f(1.0f,1.0f);

		int mass;

		int health = 3;
		sf::Texture texture;
		sf::Sprite playerSprite;
		int index;

		plr::Atributes playerAtributes;


	public:
		Player();
		Player(const std::string texturePath);
		Player(sf::Texture texture);

		void Update(float deltaTime);
		void LateUpdate(float deltaTime);

		void Draw(sf::RenderWindow& target);
		sf::Sprite getSprite();
		void setSpriteTexture(const sf::Texture);

		void setPosition(sf::Vector2f vector);
		void setSize(sf::Vector2f sizeVector);

		void Move(sf::Vector2f vector);
	};
}