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

Vector2 Grid::GetWorldPosition(Vector2Int tilePosition) const
{
	return { (float)tilePosition.x * tileSize, (float)tilePosition.y * tileSize };
}

Vector2Int Grid::GetGridWorldSize() const
{
	return GetGridWorldSize(rows, columns, tileSize);
}

Vector2Int Grid::GetGridWorldSize(int rows, int columns, int tileSize)
{
	return { columns * tileSize, rows * tileSize };
}

void Grid::DrawDebugLines()
{
	for (int i = 0; i < columns; ++i)
	{
		DrawLine(0, i * tileSize,
			GetScreenWidth(),
			i * tileSize,
			raylib::Color::LightGray());
	}

	for (int i = 0; i < rows; ++i)
	{
		DrawLine(i * tileSize, 0,
			i * tileSize, GetScreenHeight(),
			raylib::Color::LightGray());
	}
}
