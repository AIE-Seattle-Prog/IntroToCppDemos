#pragma once

#include "GameState.h"

class GameObject
{
	GameState * gameState;

public:
	GameObject(GameState * owningState) { gameState = owningState; }

	GameState * GetGameState() { return gameState; }
};