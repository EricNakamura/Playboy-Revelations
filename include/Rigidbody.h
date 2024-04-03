#pragma once
#include <SFML/Graphics.hpp>

namespace plr {
	class Rigidbody {
	protected:
		bool grounded = false;
	private:
		float dragConstant = 0.1f;
		float airDragConstant = 0.1f;

		bool useGravity = false;

		sf::Vector2<float> velocity = sf::Vector2f(0, 0);
		sf::Vector2<float> drag = sf::Vector2f(0, 0);
		sf::Vector2<float> gravity = sf::Vector2f(0, 0);
		sf::Vector2<float> acceleration = sf::Vector2f(0, 0);

	public:
		Rigidbody();
		~Rigidbody();

		void ApplyForce(sf::Vector2<float> direction, float intensity, float deltaTime);
		void Jump(float intensity);
		void ground();

		void FlipVelocityX();
		void FlipVelocityY();

		virtual void HandleCollisions();

		void SetDragConstant(float dragConstant);
		void SetAirDragConstant(float airDragConstant);

		void setGravity(bool useGravity);

		sf::Vector2<float> GetVelocity();
		sf::Vector2<float> GetAcceleration();
		sf::Vector2<float> GetDrag();

		void Update(float deltaTime, sf::Transformable& target);

	};
}