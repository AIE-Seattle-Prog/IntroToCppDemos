#pragma once

#include "raylib-cpp.hpp"

#include "Vector2Int.h"
#include "GameState.h"

struct RBeerLane
{
	Vector2Int position;
	int length;
};

class TapperGameState : public GameState
{
	int playerLocation;
	static const int LANE_COUNT = 4;
	RBeerLane lanes[LANE_COUNT];
	
protected:
	void OnUpdate() override;
	void OnDraw() override;
};


