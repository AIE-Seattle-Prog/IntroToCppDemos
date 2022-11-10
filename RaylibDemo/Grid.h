#pragma once

#include "raylib-cpp.hpp"
#include "Vector2Int.h"

class Grid
{
public:
	int rows = 9;
	int columns = 16;

	int tileSize = 16;

	Vector2Int GetTilePosition(Vector2 worldPosition) const;
	Vector2 GetWorldPosition(Vector2Int tilePosition) const;

	Vector2Int GetGridWorldSize() const;

	static Vector2Int GetGridWorldSize(int rows, int columns, int tileSize);

	void DrawDebugLines();
};