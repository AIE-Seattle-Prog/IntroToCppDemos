#pragma once

#include "raylib-cpp.hpp"

#include "GameObject.h"

class Patron : public GameObject
{
	enum class State
	{
		None,
		Waiting,
		Knockback,
		Drinking,
	};
	bool isStatePending = false;
	State currentState = State::Waiting;
	State nextState = State::None;

	float stateChangeTimer = 0.0f;

	void QueueStateChange(State newState, float delay);
	void ChangeState(State newState);

public:
	Patron(GameState * owningGameState);

	raylib::Vector2 position;
	float moveSpeed = 15;

	float knockbackSpeed = 75;
	float knockbackDuration = 2.0f;

	float drinkDuration = 4.0f;

	void Update();
	void Draw();

	void Serve();

	bool IsReadyToThirst() const;
};