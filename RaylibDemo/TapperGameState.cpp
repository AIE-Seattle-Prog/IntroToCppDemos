#include "TapperGameState.h"

#include "MathUtils.h"

TapperGameState::TapperGameState()
{
	grid = { 16, 9, 16 * 3 };

	lanes[0] = { 2, 1, 2 };
	lanes[1] = { 2, 3, 4 };
	lanes[2] = { 2, 5, 6 };
	lanes[3] = { 2, 7, 8 };

	playerLocation = 0;
	rbeerSpawnTimer = 0;
	rbeerSpawnInterval = 3;
}

void TapperGameState::OnUpdate()
{
	// player movement
	int indxDelta = 0;
	indxDelta += IsKeyPressed(KEY_UP) ? -1 : 0;
	indxDelta += IsKeyPressed(KEY_DOWN) ? +1 : 0;

	playerLocation += indxDelta;
	playerLocation = Clamp(playerLocation, 0, 3);

	// rootbeer spawning
	rbeerSpawnTimer -= GetFrameTime();
	if (rbeerSpawnTimer <= 0.0f)
	{
		rbeers.push_back(new RBeer());
		rbeers[rbeers.size() - 1]->position = grid.GetWorldPosition(lanes[GetRandomValue(0, LANE_COUNT)].position);

		rbeerSpawnTimer = rbeerSpawnInterval;
	}

	// rootbeer movement
	for (auto & rbeer : rbeers)
	{
		rbeer->Update();
	}
}

void TapperGameState::OnDraw()
{
	grid.DrawDebugLines();
	DrawCircleV(grid.GetWorldPosition(lanes[playerLocation].GetEndPosition()), 10.0f, raylib::Color::Blue());

	for (auto & rbeer : rbeers)
	{
		rbeer->Draw();
	}
}

Vector2Int RBeerLane::GetEndPosition()
{
	return { position.x + length, position.y };
}
