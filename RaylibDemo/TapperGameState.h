#pragma once

#include <vector>

#include "raylib-cpp.hpp"

#include "Vector2Int.h"
#include "Grid.h"

#include "RBeer.h"
#include "GameState.h"

struct RBeerLane
{
	Vector2Int position;
	int length;

	Vector2Int GetEndPosition();
};

class TapperGameState : public GameState
{
	Grid grid;

	int playerLocation;
	static const int LANE_COUNT = 4;
	RBeerLane lanes[LANE_COUNT];
	std::vector<RBeer *> rbeers;

	float rbeerSpawnTimer;

protected:
	void OnUpdate() override;
	void OnDraw() override;

public:
	TapperGameState();

	float rbeerSpawnInterval = 3.0f;
};


