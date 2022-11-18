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

void TapperGameState::InsertPatronOrdered(std::deque<Patron *> & deque, Patron *& patron)
{
	for (auto it = deque.begin(); it != deque.end();  ++it)
	{
		if (patron->position.x > patron->position.x)
		{
			deque.insert(it, patron);
			return;
		}
	}

	// not anywhere before the end, so add it to the end
	deque.push_back(patron);
}

void TapperGameState::OnUpdate()
{
	// player movement
	int indxDelta = 0;
	indxDelta += IsKeyPressed(KEY_UP) ? -1 : 0;
	indxDelta += IsKeyPressed(KEY_DOWN) ? +1 : 0;

	playerLocation += indxDelta;
	playerLocation = Clamp(playerLocation, 0, LANE_COUNT-1);

	// rootbeer spawning
	if (IsKeyPressed(KEY_SPACE))
	{
		lanesBeers[playerLocation].push_back(new RBeer());
		lanesBeers[playerLocation][lanesBeers[playerLocation].size() - 1]->position = grid.GetWorldPosition(lanes[playerLocation].GetEndPosition());
	}

	// patron spawning
	patronSpawnTimer -= GetFrameTime();
	if (patronSpawnTimer <= 0.0f)
	{
		int targetLane = GetRandomValue(0, LANE_COUNT-1);

		lanesPatrons[targetLane].push_back(new Patron(this));
		lanesPatrons[targetLane].back()->position = grid.GetWorldPosition(lanes[targetLane].position);

		patronSpawnTimer += patronSpawnInterval;
	}

	// patron movement
	for (auto & laneOfPatrons : lanesPatrons)
	{
		for (auto & patron : laneOfPatrons)
		{
			patron->Update();
		}
	}

	// rootbeer movement
	for (auto & laneOfBeers : lanesBeers)
	{
		for (auto & rbeer : laneOfBeers)
		{
			rbeer->Update();
		}
	}

	// Drink-Patron "Collision" Detection
	// iterate over every lane ...
	for (int curLane = 0; curLane < LANE_COUNT; ++curLane)
	{
		// test against patrons in this lane
		if (lanesBeers[curLane].size() > 0 && lanesPatrons[curLane].size() > 0 &&
			lanesBeers[curLane].front()->position.x < lanesPatrons[curLane].front()->position.x)
		{
			// drink reached customer!

			// - stage their beer for return (TODO: implement chance!)
			// lanesBeers[curLane].front()->speed *= -1;
			// 
			// lanesReturnBeers[curLane].push_back(lanesBeers[curLane].front());
			// lanesBeers[curLane].pop_front();
			delete lanesBeers[curLane].front();
			lanesBeers[curLane].pop_front();

			// - stage patron for return
			lanesPatrons[curLane].front()->Serve();

			lanesReturnPatrons[curLane].push_back(lanesPatrons[curLane].front());
			lanesPatrons[curLane].pop_front();
		}
	}
	
	// Update Satisfied Patrons
	for (int lane = 0; lane < LANE_COUNT; ++lane)
	{
		std::vector<Patron *> removeQueue;
		for (int i = 0; i < lanesReturnPatrons[lane].size(); ++i)
		{
			lanesReturnPatrons[lane][i]->Update();
			if (lanesReturnPatrons[lane][i]->IsReadyToThirst())
			{
				InsertPatronOrdered(lanesPatrons[lane], lanesReturnPatrons[lane][i]);
				removeQueue.push_back(lanesReturnPatrons[lane][i]);
			}
		}

		for (auto & removedPatron : removeQueue)
		{
			auto it = std::find(lanesReturnPatrons[lane].begin(), lanesReturnPatrons[lane].end(), removedPatron);
			lanesReturnPatrons[lane].erase(it);
		}
	}


	// Update Return Rbeers
	for (auto & laneOfBeers : lanesReturnBeers)
	{
		for (auto & rbeer : laneOfBeers)
		{
			rbeer->Update();
		}
	}
}

void TapperGameState::OnDraw()
{
	grid.DrawDebugLines();
	
	// patron movement
	for (auto & laneOfPatrons : lanesPatrons)
	{
		for (auto & patron : laneOfPatrons)
		{
			patron->Draw();
		}
	}

	// rootbeer movement
	for (auto & laneOfBeers : lanesBeers)
	{
		for (auto & rbeer : laneOfBeers)
		{
			rbeer->Draw();
		}
	}

	// return patron movement
	for (auto & laneOfPatrons : lanesReturnPatrons)
	{
		for (auto & patron : laneOfPatrons)
		{
			patron->Draw();
		}
	}

	// return rootbeer movement
	for (auto & laneOfBeers : lanesReturnBeers)
	{
		for (auto & rbeer : laneOfBeers)
		{
			rbeer->Draw();
		}
	}

	DrawCircleV(grid.GetWorldPosition(lanes[playerLocation].GetEndPosition()), 10.0f, raylib::Color::Blue());
}

Vector2Int RBeerLane::GetEndPosition()
{
	return { position.x + length, position.y };
}
