#include "Grid.h"

#include "raylib-cpp.hpp"
#include "physac.hpp"

Vector2Int Grid::GetTilePosition(Vector2 worldPosition) const
{
	int w = GetScreenWidth();
	int h = GetScreenHeight();

	int worldX = worldPosition.x;
	int worldY = worldPosition.y;

	return { worldX / tileSize, worldY / tileSize };
}

Vector2Int Grid::GetGridWorldSize() const
{
	return GetGridWorldSize(rows, columns, tileSize);
}

Vector2Int Grid::GetGridWorldSize(int rows, int columns, int tileSize)
{
	return { columns * tileSize, rows * tileSize };
}
