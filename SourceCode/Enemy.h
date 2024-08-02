#pragma once
#include "Player.h"
#include "Novice.h"
#include "Character.h"

class Enemy :public Character
{
private:


public:
	void Initialize(Vector2& pos, float speed, int radius, uint32_t color)override;
	void Update()override;
	void Draw()override;

	const Vector2 GetPos()const { return pos_; }
	const int GetRadius()const { return radius_; }
};

