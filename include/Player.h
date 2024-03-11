#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <Atributes.h>

namespace plr {
	class Player {
	private:
		void DefaultInit();

		sf::Vector2<float> acel = sf::Vector2f(0, 0);
		sf::Vector2<float> speed = sf::Vector2f(0, 0);
		sf::Vector2<float> drag = sf::Vector2f(0, 0);
		sf::Vector2<float> direction = sf::Vector2f(0, 0);
		float moveSpeed = 1.5f;
		float jumpForce = 20.0f;
		float dragForce = 0.08f;
		float maxSpeed = 20.f;

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
		void FixedUpdate(float time = 0.002);
		void LateUpdate(float deltaTime);

		void Draw(sf::RenderWindow& target);
		sf::Sprite getSprite();
		void setSpriteTexture(const sf::Texture);

		void setPosition(sf::Vector2f vector);
		sf::Vector2f getPosition();
		void setSize(sf::Vector2f sizeVector);

		void Move(sf::Vector2f vector);
	};
}