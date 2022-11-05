#pragma once

struct Vector2Int
{
	int x;
	int y;

	Vector2Int operator+ (const Vector2Int & other)
	{
		return { x + other.x, y + other.y };
	}

	Vector2Int operator- (const Vector2Int & other)
	{
		return { x - other.x, y - other.y };
	}
};