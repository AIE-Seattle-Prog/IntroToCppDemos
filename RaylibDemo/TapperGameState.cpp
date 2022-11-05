#include "TapperGameState.h"

#include "MathUtils.h"

void TapperGameState::OnUpdate()
{
	int indxDelta = 0;
	indxDelta += IsKeyPressed(KEY_UP) ? 1 : 0;
	indxDelta += IsKeyPressed(KEY_DOWN) ? -1 : 0;

	playerLocation += indxDelta;
	playerLocation = Clamp(indxDelta, 0, 3);
}

void TapperGameState::OnDraw()
{
}