#pragma once

#include "Enemy.h"

class Grunt : public Enemy
{
public:
	Grunt();
	~Grunt() override;

	void Update() override;
};