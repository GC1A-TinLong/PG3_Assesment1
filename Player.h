#pragma once
#include "Enemy.h"
#include "Character.h"
#include "Novice.h"
#include "Input.h"

class Player :public Character
{
private:


public:
	void Initialize(Vector2& pos, float speed, int radius, uint32_t color)override;
	void Update()override;
	void Draw()override;

	void MoveControl();
};

