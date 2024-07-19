#include "StageScene.h"

StageScene::StageScene()
{
}

StageScene::~StageScene()
{
	delete player_;
	for (Enemy* enemy : enemies_) {
		delete enemy;
	}
	enemies_.clear();
}

void StageScene::Initialize()
{
	player_ = new Player;
	Vector2 playerPos = { 640.0f,500.0f };
	player_->Initialize(playerPos, 8.0f, 35, WHITE);

	for (int32_t i = 0; i < kEnemyNum; i++) {
		Enemy* newEnemy = new Enemy;
		Vector2 enemyPos = { 100.0f + float(i) * 200.0f,150.0f };
		newEnemy->Initialize(enemyPos, 5.0f, 50, BLACK);

		enemies_.push_back(newEnemy);	// adding the value to the last of the list
	}
}

void StageScene::Update()
{
	player_->Update();

	for (auto* enemies : enemies_) {
		if (enemies) {
			enemies->Update();
		}
	}

	if (Input::GetInstance()->TriggerKey(DIK_E)) {
		sceneNo = CLEAR;
	}
}

void StageScene::Draw()
{
	Novice::DrawSprite(0, 0, textureHandle_, 1.0f, 1.0f, 0, WHITE);

	if (player_) {
		player_->Draw();
	}

	for (auto* enemies : enemies_) {
		if (enemies) {
			enemies->Draw();
		}
	}
}
