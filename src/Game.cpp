#include <Game.h>
#include <Player.h>
#include <iostream>

plr::Player player("assets/player/player.png");

void Initilize()
{
	player.setSize(sf::Vector2f(10.f, 10.f));
	player.setPosition(sf::Vector2f(0, 0));

}

void Update(float deltaTime)
{
	player.Update(deltaTime);
	player.FixedUpdate();
	player.LateUpdate(deltaTime);
}

void LateUpdate(float deltaTime)
{
	system("cls");
}

void Render(sf::RenderWindow& target) {
	
	player.Draw(target);

}

