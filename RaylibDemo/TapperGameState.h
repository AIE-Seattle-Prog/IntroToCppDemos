#pragma once

#include <deque>
#include <vector>
#include <queue>

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

	std::deque<RBeer *> lanesBeers[LANE_COUNT];
	std::deque<Patron *> lanesPatrons[LANE_COUNT];

	std::deque<RBeer *> lanesReturnBeers[LANE_COUNT];
	std::deque<Patron *> lanesReturnPatrons[LANE_COUNT];

	float patronSpawnTimer; // TODO: refactor this to be per lane

	void InsertPatronOrdered(std::deque<Patron *> & deque, Patron *& patron);

protected:
	void OnUpdate() override;
	void OnDraw() override;

public:

	float patronSpawnInterval = 5;

	TapperGameState();
};


