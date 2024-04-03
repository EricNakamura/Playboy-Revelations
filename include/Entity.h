#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <Atributes.h>
#include <Rigidbody.h>

namespace plr {
	class Entity : public plr::Rigidbody {
	private:

		sf::Vector2<float> direction = sf::Vector2f(0, 0);

		float moveSpeed = 0.5f;
		float jumpForce = 5.0f;
		float airDrag = 0.5f;
		float dragForce = 10.f;
		float maxSpeed = 5.0f;
		float maxX;
		float maxY;

		sf::Vector2f size = sf::Vector2f(1.0f, 1.0f);

		int health = 3;
		sf::Texture texture;
		sf::Sprite playerSprite;
		int index;

		plr::Atributes playerAtributes;


	public:
		Entity();
		Entity(const std::string texturePath);
		Entity(sf::Texture texture);

		virtual void DefaultInit();

		virtual void Update(float deltaTime);
		virtual void FixedUpdate(float deltaTime = 0.002);
		virtual void LateUpdate(float deltaTime);

		virtual void HandleCollisions();

		void Draw(sf::RenderWindow& target);
		sf::Sprite getSprite();
		void setSpriteTexture(const sf::Texture);

		void setPosition(sf::Vector2f vector);
		void setmoveSpeed(float speed);
		void setJumpForce(float force);
		sf::Vector2f getPosition();
		void setSize(sf::Vector2f sizeVector);
		void setMaxX(float x);
		void setMaxY(float y);
		void setMaxBounds(sf::Vector2f maxBounds);

		void Move(sf::Vector2f vector);
	};
}