#pragma once

#include <vector>

#include "raylib-cpp.hpp"

#include "Vector2Int.h"
#include "Grid.h"

#include "RBeer.h"
#include "Patron.h"
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
	std::vector<Patron *> patrons;

	float patronSpawnTimer;

protected:
	void OnUpdate() override;
	void OnDraw() override;

public:

	float patronSpawnInterval = 3;

	TapperGameState();
};


