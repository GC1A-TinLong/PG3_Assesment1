#pragma once
#include "Enemy.h"
#include "Character.h"
#include "Novice.h"
#include "Input.h"
#include <vector>
#include <imgui.h>
#include "Bullet.h"
#include <list>

class Player :public Character
{
private:
	static inline const int32_t kBulletNum = 20;
	std::list<Bullet*>bullets_;

	bool bulletBreak = false;
	int kBulletCD = 0;

public:
	Player();
	~Player();

	void Initialize(Vector2& pos, float speed, int radius, uint32_t color)override;
	void Update()override;
	void Draw()override;

	const Vector2 GetPos()const { return pos_; }

	void MoveControl();
	void ShootControl();
};

