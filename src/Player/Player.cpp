#include <Player.h>
#include <iostream>
#include <Enums.h>
#include <iostream>
#include <cmath>
#include <Normalize.h>

plr::Player::Player()
{
	DefaultInit();
}

plr::Player::Player(const std::string texturePath)
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

plr::Player::Player(sf::Texture texture) {
	this->texture = texture;
	this->setSpriteTexture(texture);
	DefaultInit();
}

void plr::Player::setPosition(sf::Vector2f vector) {
	this->playerSprite.setPosition(vector);
}

void plr::Player::setSize(sf::Vector2f sizeVector) {
	sf::Vector2f size = sf::Vector2f( sizeVector.x / texture.getSize().x, sizeVector.y/texture.getSize().y );
	this->playerSprite.setScale(size);
}

void plr::Player::DefaultInit() {

	playerSprite.setOrigin(this->texture.getSize().x/2.0f, this->texture.getSize().y/2.0f);
}


sf::Sprite plr::Player::getSprite() {
	return this->playerSprite;
}

sf::Vector2f plr::Player::getPosition() {
	return playerSprite.getPosition();
}

void plr::Player::setSpriteTexture(const sf::Texture texture) {
	this->playerSprite.setTexture(texture);
}

void plr::Player::Draw(sf::RenderWindow& target) {
	target.draw(this->getSprite());
}

void plr::Player::Move(sf::Vector2f vector)
{
	playerSprite.move(vector);
}

void plr::Player::Update(float deltaTime)
{
	Move(speed);
	
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
		direction.y = -1;
	}
	plr::Normalize(direction);
	acel = sf::Vector2f(
		direction.x * moveSpeed * deltaTime,
		direction.y * jumpForce * deltaTime
	);
	drag = sf::Vector2f(
		dragForce * speed.x ,
		-0.02f+ dragForce * speed.y
	);
	speed = sf::Vector2f(
		speed.x + (acel.x - drag.x),
		speed.y + (acel.y - drag.y)
	);
	std::cout << deltaTime << std::endl;
}

void plr::Player::FixedUpdate(float time)
{

}

void plr::Player::LateUpdate(float deltaTime)
{
	direction.x = 0;
	direction.y = 0;
}