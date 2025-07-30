#include "GimmickManager.h"

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
			//플레이어2의 조작반전 해제
		}
	}
	if (p2gimmick1Timer > 0.0f) {
		p2gimmick1Timer -= TIME_GET_DELTATIME();
		if (p2gimmick1Timer <= 0.0f) {
			p2gimmick1Timer = 0.0f;
			//플레이어1의 조작반전 해제
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
};

void GimmickManager::GimmickOn(int player, int gimmick) {
	switch (gimmick)
	{
	case 1:
		if (player == 1) {
			//플레이어2의 조작 반전
			p1gimmick1Timer = timelimit;
		}
		else {
			//플레이어1의 조작 반전
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
		if (player == 1) {
			//플레이어2에 몬스터 3마리 스폰
		}
		else {
			//플레이어1에 몬스터 3마리 스폰
		}
		break;
	}
};