// PlayboyRevelations.cpp: define o ponto de entrada para o aplicativo.
//

#include <SFML/Graphics.hpp>
#include <Player.h>	

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Playboy Revelations", sf::Style::Default);
	sf::Clock clock;

	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();
		sf::Event event{};

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear();

		window.display();
	}

	return 0;
}
