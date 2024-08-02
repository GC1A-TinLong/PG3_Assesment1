#pragma once
#include "IScene.h"
#include "Input.h"
#include "Novice.h"
#include "Player.h"
#include "Enemy.h"
#include <list>
#include <cmath>

class StageScene:public IScene
{
public:
	StageScene();
	~StageScene();

	void Initialize() override;
	void Update() override;
	void Draw() override;

private:
	uint32_t textureHandle_ = Novice::LoadTexture("./Resources/stage.png");

	Player* player_ = nullptr;

	static inline const int32_t kBulletNum = 20;
	static inline const int kEnemyNum = 4;
	std::list<Enemy*> enemies_;
};

