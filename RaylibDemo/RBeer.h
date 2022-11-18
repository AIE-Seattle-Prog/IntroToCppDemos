#pragma once

#include "raylib-cpp.hpp"

class RBeer
{
public:
	raylib::Vector2 position;
	float speed = 100;

	void Update();
	void Draw();
};