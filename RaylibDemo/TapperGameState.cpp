#include "TapperGameState.h"

#include "MathUtils.h"

TapperGameState::TapperGameState()
{
	grid = { 16, 9, 16 * 3 };

	lanes[0] = { 2, 1, 3 };
	lanes[1] = { 2, 3, 5 };
	lanes[2] = { 2, 5, 7 };
	lanes[3] = { 2, 7, 8 };

	playerLocation = 0;

	patronSpawnInterval = 3;
	patronSpawnTimer = patronSpawnInterval;
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
	if (IsKeyPressed(KEY_SPACE))
	{
		rbeers.push_back(new RBeer());
		rbeers[rbeers.size() - 1]->position = grid.GetWorldPosition(lanes[playerLocation].GetEndPosition());
	}

	// patron spawning
	patronSpawnTimer -= GetFrameTime();
	if (patronSpawnTimer <= 0.0f)
	{
		patrons.push_back(new Patron());
		patrons.back()->position = grid.GetWorldPosition(lanes[GetRandomValue(0, LANE_COUNT)].position);

		patronSpawnTimer += patronSpawnInterval;
	}

	// rootbeer movement
	for (auto & rbeer : rbeers)
	{
		rbeer->Update();
	}

	// patron movement
	for (auto & patron : patrons)
	{
		patron->Update();
	}
}

void TapperGameState::OnDraw()
{
	grid.DrawDebugLines();
	
	for (auto & rbeer : rbeers)
	{
		rbeer->Draw();
	}

	for (auto & patron : patrons)
	{
		patron->Draw();
	}

	DrawCircleV(grid.GetWorldPosition(lanes[playerLocation].GetEndPosition()), 10.0f, raylib::Color::Blue());
}

Vector2Int RBeerLane::GetEndPosition()
{
	return { position.x + length, position.y };
}
