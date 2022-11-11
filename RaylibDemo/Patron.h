#pragma once

#include "raylib-cpp.hpp"

class Patron
{
	enum class State
	{
		Waiting,
		Satisfied,
	};
	State currentState = State::Waiting;

public:
	raylib::Vector2 position;
	float speed = 15;

	void Update();
	void Draw();
};