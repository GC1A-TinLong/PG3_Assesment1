#pragma once
#include "Enemy.h"
#include "Character.h"
#include "Novice.h"
#include "Input.h"
#include <vector>
#include <imgui.h>

class Player :public Character
{
private:
	std::vector<float*>bullets_;

public:
	void Initialize(Vector2& pos, float speed, int radius, uint32_t color)override;
	void Update()override;
	void Draw()override;

	void MoveControl();
	void ShootControl();
};

