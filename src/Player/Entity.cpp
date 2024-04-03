#include <Entity.h>
#include <iostream>
#include <Enums.h>
#include <iostream>
#include <cmath>
#include <Normalize.h>

plr::Entity::Entity()
{
	DefaultInit();
}

plr::Entity::Entity(const std::string texturePath)
{
	sf::Texture temp;
	if (!temp.loadFromFile(texturePath)) {
		std::cerr << "Impossible to load " << texturePath << std::endl;
		return;
	}

	this->texture = temp;
	this->playerSprite.setTexture(this->texture);
	DefaultInit();
}

plr::Entity::Entity(sf::Texture texture) {
	this->texture = texture;
	this->setSpriteTexture(texture);
	DefaultInit();
}

void plr::Entity::setPosition(sf::Vector2f vector) {
	this->playerSprite.setPosition(vector);
}

void plr::Entity::setSize(sf::Vector2f sizeVector) {
	sf::Vector2f size = sf::Vector2f(sizeVector.x / texture.getSize().x, sizeVector.y / texture.getSize().y);
	this->playerSprite.setScale(size);
}

void plr::Entity::setmoveSpeed(float speed)
{
	this->moveSpeed = speed;

}

void plr::Entity::setJumpForce(float force)
{
	this->jumpForce = force;
}

void plr::Entity::setMaxX(float x)
{
	this->maxX = x;
}

void plr::Entity::setMaxY(float y)
{
	this->maxY = y;
}

void plr::Entity::setMaxBounds(sf::Vector2f maxBounds)
{
	setMaxX(maxBounds.x);
	setMaxY(maxBounds.y);
}

void plr::Entity::DefaultInit() {

	// INITIAL CONFIGURATION
	SetDragConstant(dragForce);
	playerSprite.setOrigin(this->texture.getSize().x / 2.0f, this->texture.getSize().y / 2.0f);
}


sf::Sprite plr::Entity::getSprite() {
	return this->playerSprite;
}

sf::Vector2f plr::Entity::getPosition() {
	return playerSprite.getPosition();
}

void plr::Entity::setSpriteTexture(const sf::Texture texture) {
	this->playerSprite.setTexture(texture);
}

void plr::Entity::Draw(sf::RenderWindow& target) {
	target.draw(this->getSprite());
}

void plr::Entity::Move(sf::Vector2f vector)
{
	playerSprite.move(vector);
}

void plr::Entity::HandleCollisions() {
	// check if the player is out of bounds
	if (playerSprite.getPosition().x + GetVelocity().x < 0) {
		FlipVelocityX();
	}
	if (playerSprite.getPosition().x + GetVelocity().x > maxX) {
		FlipVelocityX();
	}
	if (playerSprite.getPosition().y + GetVelocity().y < 0) {
		FlipVelocityY();
	}
	if (playerSprite.getPosition().y + GetVelocity().y >= (maxY - 50)) {
		setGravity(false);
		ground();
	}
	else {
		setGravity(true);
	}

}

void plr::Entity::Update(float deltaTime)
{
	// gives the player a force in the direction of the arrow keys
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		direction.x = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		direction.x = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		direction.y = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (grounded) {
			direction.y = -1;
			Jump(jumpForce);
		}
	}

	//update the rigidbody
	Rigidbody::Update(deltaTime, playerSprite);
	// Apply the force to the player
	ApplyForce(direction, moveSpeed, deltaTime);
}

void plr::Entity::FixedUpdate(float deltaTime)
{
}

void plr::Entity::LateUpdate(float deltaTime)
{
	direction.x = 0;
	direction.y = 0;
}