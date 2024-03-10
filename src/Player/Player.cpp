#include <Player.h>
#include <iostream>
#include <Enums.h>
#include <iostream>

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
	this->playerSprite.setScale(sizeVector);
}

void plr::Player::DefaultInit() {
	this->playerSprite.setScale(this->size);
	this->playerSprite.setOrigin(this->texture.getSize().x/2.0f, this->texture.getSize().y/2.0f);
}


sf::Sprite plr::Player::getSprite() {
	return this->playerSprite;
}

void plr::Player::setSpriteTexture(const sf::Texture texture) {
	this->playerSprite.setTexture(texture);
}

void plr::Player::Draw(sf::RenderWindow& target) {
	target.draw(this->getSprite());
}

void plr::Player::Move(sf::Vector2f vector)
{
}

void plr::Player::Update(float deltaTime)
{
}

void plr::Player::LateUpdate(float deltaTime)
{
}