#include <Game.h>
#include <Player.h>

plr::Player player("assets/player/player.png");

void Initilize()
{
	player.setSize(sf::Vector2f(1.f, 1.f));
}

void Update(float deltaTime)
{
}

void LateUpdate(float deltaTime)
{
}

void Render(sf::RenderWindow& target) {
	
	player.Draw(target);

}

