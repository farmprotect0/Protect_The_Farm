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
			//�÷��̾�2�� ���۹��� ����
		}
	}
	if (p2gimmick1Timer > 0.0f) {
		p2gimmick1Timer -= TIME_GET_DELTATIME();
		if (p2gimmick1Timer <= 0.0f) {
			p2gimmick1Timer = 0.0f;
			//�÷��̾�1�� ���۹��� ����
		}
	}
	if (p1gimmick2Timer > 0.0f) {
		p1gimmick2Timer -= TIME_GET_DELTATIME();
		if (p1gimmick2Timer <= 0.0f) {
			p1gimmick2Timer = 0.0f;
			//�÷��̾�2�� �þ� ������ ����
		}
	}
	if (p2gimmick2Timer > 0.0f) {
		p2gimmick2Timer -= TIME_GET_DELTATIME();
		if (p2gimmick2Timer <= 0.0f) {
			p2gimmick2Timer = 0.0f;
			//�÷��̾�1�� �þ� ������ ����
		}
	}
};

void GimmickManager::GimmickOn(int player, int gimmick) {
	switch (gimmick)
	{
	case 1:
		if (player == 1) {
			//�÷��̾�2�� ���� ����
			p1gimmick1Timer = timelimit;
		}
		else {
			//�÷��̾�1�� ���� ����
			p2gimmick1Timer = timelimit;
		}
		break;
	case 2:
		if (player == 1) {
			//�÷��̾�2�� �þ� ������
			p1gimmick2Timer = timelimit;
		}
		else {
			//�÷��̾�1�� �þ� ������
			p2gimmick2Timer = timelimit;
		}
		break;
	case 3:
		if (player == 1) {
			//�÷��̾�2�� ���� 3���� ����
		}
		else {
			//�÷��̾�1�� ���� 3���� ����
		}
		break;
	}
};