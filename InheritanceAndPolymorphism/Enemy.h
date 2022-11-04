#pragma once

#include "BaseEnemy.h"

class Enemy : public BaseEnemy
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void Update();
};
