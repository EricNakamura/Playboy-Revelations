#include <Rigidbody.h>
#include <Normalize.h>
#include <iostream>

plr::Rigidbody::Rigidbody() {}

plr::Rigidbody::~Rigidbody()
{
}

void plr::Rigidbody::HandleCollisions()
{
}

void plr::Rigidbody::ground()
{
	velocity.y = 0;
	grounded = true;
}

void plr::Rigidbody::FlipVelocityX()
{
	velocity.x = -velocity.x;
}

void plr::Rigidbody::FlipVelocityY()
{
	velocity.y = -velocity.y;
}

void plr::Rigidbody::ApplyForce(sf::Vector2<float> direction, float intensity, float deltaTime)
{
	// Normalize the direction vector
	plr::Normalize(direction);

	sf::Vector2f force(direction.x * intensity, direction.y * intensity);

	// Apply the force to the acceleration
	acceleration.x = (force.x) * deltaTime;
	acceleration.y = (force.y) * deltaTime;
}

void plr::Rigidbody::Jump(float jumpIntensity)
{
	grounded = false;

	sf::Vector2f force(0, -1 * jumpIntensity * 10);

	// Apply the force to the acceleration
	acceleration.y = (force.y) * 0.002;
}

void plr::Rigidbody::SetAirDragConstant(float airDragConstant)
{
	this->airDragConstant = airDragConstant;
}

void plr::Rigidbody::SetDragConstant(float dragConstant)
{
	this->dragConstant = dragConstant;
}

void plr::Rigidbody::setGravity(bool useGravity)
{
	this->useGravity = useGravity;
}


sf::Vector2<float> plr::Rigidbody::GetVelocity()
{
	return velocity;
}

sf::Vector2<float> plr::Rigidbody::GetAcceleration()
{
	return acceleration;
}

sf::Vector2f plr::Rigidbody::GetDrag()
{
	return drag;
}

void plr::Rigidbody::Update(float deltaTime, sf::Transformable& target)
{
	drag.x = velocity.x * dragConstant * deltaTime;
	drag.y = velocity.y * dragConstant * deltaTime;

	// Apply the gravity
	if (useGravity) {
		gravity.y = 0.8f;
		acceleration.y += gravity.y * deltaTime;
		drag.y = velocity.y * (airDragConstant)*deltaTime;
	}

	// Apply the acceleration to the velocity
	velocity.x += GetAcceleration().x - drag.x;
	velocity.y += GetAcceleration().y - drag.y;

	// Call the collisions logic
	// // NOTE: THIS FUNCTIONS HAS TO BE BEFORE THE MOVE FUNCTION
	// // AND MUST BE OVERRIDEN IN THE CHILD CLASS
	HandleCollisions();

	// Move the target
	target.move(velocity);
}