#include "GimmickManager.h"
#include <CrosshairMove.h>
#include "EnemySpawner.h"

using namespace GOTOEngine;

GimmickManager* GimmickManager::instance = nullptr;

void GimmickManager::Awake()
{
	if (!instance)
	{
		instance = this;
	}
	else
	{
		Destroy(GetGameObject());
	}
}
void GimmickManager::OnDestroy() {
	if (instance == this)
		instance = nullptr;
}

void GimmickManager::Update() {
	if (p1gimmick1Timer > 0.0f) {
		p1gimmick1Timer -= TIME_GET_DELTATIME();
		if (p1gimmick1Timer <= 0.0f) {
			p1gimmick1Timer = 0.0f;
			CrosshairMove::reverseInput2 = false;
		}
	}
	if (p2gimmick1Timer > 0.0f) {
		p2gimmick1Timer -= TIME_GET_DELTATIME();
		if (p2gimmick1Timer <= 0.0f) {
			p2gimmick1Timer = 0.0f;
			CrosshairMove::reverseInput1 = false;
		}
	}
	if (p1gimmick2Timer > 0.0f) {
		p1gimmick2Timer -= TIME_GET_DELTATIME();
		if (p1gimmick2Timer <= 0.0f) {
			p1gimmick2Timer = 0.0f;
			//플레이어2의 시야 가리기 해제
		}
	}
	if (p2gimmick2Timer > 0.0f) {
		p2gimmick2Timer -= TIME_GET_DELTATIME();
		if (p2gimmick2Timer <= 0.0f) {
			p2gimmick2Timer = 0.0f;
			//플레이어1의 시야 가리기 해제
		}
	}
	if (INPUT_GET_KEYDOWN(KeyCode::Alpha9)) {
		GimmickOn(1, 1);
	}
	if (INPUT_GET_KEYDOWN(KeyCode::Alpha0)) {
		GimmickOn(2, 1);
	}
};

void GimmickManager::GimmickOn(int player, int gimmick) {
	switch (gimmick)
	{
	case 1:
		if (player == 1) {
			CrosshairMove::reverseInput2 = true;
			p1gimmick1Timer = timelimit;
		}
		else {
			CrosshairMove::reverseInput1 = true;
			p2gimmick1Timer = timelimit;
		}
		break;
	case 2:
		if (player == 1) {
			//플레이어2의 시야 가리기
			p1gimmick2Timer = timelimit;
		}
		else {
			//플레이어1의 시야 가리기
			p2gimmick2Timer = timelimit;
		}
		break;
	case 3:
		for (int i = 0; i < 3; i++)
		{
			EnemySpawner::instance->CreateEnemy(player, 0b0001, true);
		}
		break;
	}
};