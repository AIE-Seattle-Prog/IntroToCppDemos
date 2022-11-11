#include "Patron.h"

#include <cassert>

void Patron::Update()
{
	float moveDir = 0;
	switch (currentState)
	{
	case State::Waiting:
		moveDir = +1;
		break;
	case State::Satisfied:
		moveDir = -1;
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
