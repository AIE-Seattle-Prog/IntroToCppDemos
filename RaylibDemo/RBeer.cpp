#include "RBeer.h"

void RBeer::Update()
{
	position.x += speed * GetFrameTime();
}

void RBeer::Draw()
{
	DrawCircleV(position, 16.f, raylib::Color::Brown());
}