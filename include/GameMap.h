#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

namespace plr {
	class Map {
	private:
		std::vector<std::vector<int>> grid;
		sf::Texture texture;
		sf::Sprite sprite;
		void Init();

	public:
		Map();
		Map(const std::string texturePath);
		~Map();

		void Create(size_t width, size_t height);

		void Load(std::string filename);
		void Draw(sf::RenderWindow& renderWindow);
		void Update();

		void scaleToScreen(sf::RenderWindow& renderWindow);

		int getWidth();
		int getHeight();
		sf::Sprite getSprite();
	};
}