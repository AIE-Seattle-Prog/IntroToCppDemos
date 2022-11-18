#include "Patron.h"

#include "TapperGameState.h"

#include <cassert>

void Patron::QueueStateChange(State newState, float delay)
{
	if (newState == currentState) { return; }

	nextState = newState;
	stateChangeTimer = delay;

	// change immediately if delay is zero
	if (stateChangeTimer <= 0.0f)
	{
		ChangeState(newState);
	}
	// otherwise queue it up to be handled in Update
	else
	{
		isStatePending = true;
	}
}

void Patron::ChangeState(State newState)
{
	isStatePending = false;

	auto oldState = currentState;
	currentState = newState;

	switch (currentState)
	{
	case State::Waiting:
		break;
	case State::Knockback:
		QueueStateChange(State::Drinking, knockbackDuration);
		break;
	case State::Drinking:
		QueueStateChange(State::Waiting, drinkDuration);
		break;
	}
}

Patron::Patron(GameState * owningGameState) : GameObject(owningGameState) { }

void Patron::Update()
{
	if (isStatePending)
	{
		stateChangeTimer -= GetFrameTime();
		if (stateChangeTimer <= 0.0f)
		{
			ChangeState(nextState);
		}
	}

	float moveDir = 0;
	float speed = 0;
	switch (currentState)
	{
	case State::Waiting:
		moveDir = +1;
		speed = moveSpeed;
		break;
	case State::Knockback:
		moveDir = -1;
		speed = knockbackSpeed;
		break;
	case State::Drinking:
		moveDir = 0;
		break;
	default:
		assert(false);
	}

	position += raylib::Vector2(moveDir, 0) * speed * GetFrameTime();
}

void Patron::Draw()
{
	DrawRectangleV(position, { 16 * 3, 16 * 3 }, YELLOW);
}

void Patron::Serve()
{
	assert(currentState == State::Waiting);

	ChangeState(State::Knockback);
}

bool Patron::IsReadyToThirst() const
{
	return currentState == State::Waiting;
}
