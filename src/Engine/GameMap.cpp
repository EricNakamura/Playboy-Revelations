#include <GameMap.h>
#include <iostream>

plr::Map::Map()
{
	sprite.setPosition(0, 0);
}
plr::Map::Map(const std::string texturePath)
{
	sf::Texture temp;
	if (!temp.loadFromFile(texturePath)) {
		std::cerr << "Impossible to load " << texturePath << std::endl;
		return;
	}
	texture.update(temp);
	this->texture = temp;
	this->sprite.setTexture(this->texture);
	Init();
}

plr::Map::~Map()
{
}

void plr::Map::Init() {
	sprite.setOrigin(0, 0);
}

void plr::Map::Create(size_t width, size_t height)
{
}

void plr::Map::Load(std::string filename)
{
	sf::Texture texture;
	texture.loadFromFile(filename);
	this->texture = texture;
	sprite.setTexture(texture, true);
}

void plr::Map::scaleToScreen(sf::RenderWindow& renderWindow)
{
	float aspectRatio = (float)texture.getSize().x / texture.getSize().y;
	float screenAspectRatio = renderWindow.getView().getSize().x / renderWindow.getView().getSize().y;
	if (aspectRatio > screenAspectRatio) {
		sprite.setScale(renderWindow.getView().getSize().y / texture.getSize().y, renderWindow.getView().getSize().y / texture.getSize().y);
	}
	else {
		sprite.setScale(renderWindow.getView().getSize().x / texture.getSize().x, renderWindow.getView().getSize().x / texture.getSize().x);
	}
}

void plr::Map::Draw(sf::RenderWindow& renderWindow)
{
	renderWindow.draw(this->getSprite());
}

void plr::Map::Update()
{
}

int plr::Map::getWidth()
{
	return 0;
}

int plr::Map::getHeight()
{
	return 0;
}

sf::Sprite plr::Map::getSprite()
{
	return this->sprite;
}
