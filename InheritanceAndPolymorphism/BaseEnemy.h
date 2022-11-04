#pragma once

class BaseEnemy
{
public:
	virtual ~BaseEnemy() { };

	virtual void Update() = 0;
};
