#include <Normalize.h>
#include <cmath>
#include <iostream>

void plr::Normalize(sf::Vector2f vector) {
	auto normal = std::sqrt((vector.x * vector.x) + (vector.y * vector.y));
	vector.x = vector.x / normal;
	vector.y = vector.y / normal;
}