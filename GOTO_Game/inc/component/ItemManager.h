#pragma once
#include <ScriptBehaviour.h>
#include <TimeManager.h>
#include <InputManager.h>
#include <RenderManager.h>
#include <SpriteRenderer.h>
#include "ScoreManager.h"
#include <queue>

namespace GOTOEngine
{
	enum class ItemType {
		Bomb = 0, Icebomb, Ticket
	};
	class ItemManager : public ScriptBehaviour
	{
	private:
		std::queue<ItemType> p1Items;
		std::queue<ItemType> p2Items;
		float p1TicketTimer = 0.0f;
		float p2TicketTimer = 0.0f;
		float p1IceTimer = 0.0f;
		float p2IceTimer = 0.0f;
		const float timelimit = 5.0f;
	public:
		int p1count = 0;
		int p2count = 0;
    ItemManager()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }
		ScoreManager* scoreManager = new ScoreManager;
		// �ν��Ͻ� ���� �����̱� ������ ���� ���� �Ұ�, ���� �ʿ�
		void Update() {
			if (INPUT_GET_KEYDOWN(KeyCode::Alpha1)) {
				if (!p1Items.empty()) {
					ItemType item = p1Items.front();
					UseItem(1, item);
					p1Items.pop();
				}
			}
			if (INPUT_GET_KEYDOWN(KeyCode::Alpha2)) {
				if (!p2Items.empty()) {
					ItemType item = p2Items.front();
					UseItem(2, item);
					p2Items.pop();
				}
			}
			if (INPUT_GET_KEYDOWN(KeyCode::Alpha3)) {
				p1Items.push(ItemType::Bomb);
			}
			if (INPUT_GET_KEYDOWN(KeyCode::Alpha4)) {
				p1Items.push(ItemType::Icebomb);
			}
			if (INPUT_GET_KEYDOWN(KeyCode::Alpha5)) {
				p1Items.push(ItemType::Ticket);
			}
			if (INPUT_GET_KEYDOWN(KeyCode::Alpha6)) {
				p2Items.push(ItemType::Bomb);
			}
			if (INPUT_GET_KEYDOWN(KeyCode::Alpha7)) {
				p2Items.push(ItemType::Icebomb);
			}
			if (INPUT_GET_KEYDOWN(KeyCode::Alpha8)) {
				p2Items.push(ItemType::Ticket);
			}
			if (p1TicketTimer > 0.0f) {
				p1TicketTimer -= TIME_GET_DELTATIME();
				if (p1TicketTimer <= 0.0f) {
					p1TicketTimer = 0.0f;
					scoreManager->P1Bonus = 1;
				}
			}

			if (p2TicketTimer > 0.0f) {
				p2TicketTimer -= TIME_GET_DELTATIME();
				if (p2TicketTimer <= 0.0f) {
					p2TicketTimer = 0.0f;
					scoreManager->P2Bonus = 1;
				}
			}
			if (p1TicketTimer > 0.0f) {
				p1TicketTimer -= TIME_GET_DELTATIME();
				if (p1TicketTimer <= 0.0f) {
					p1TicketTimer = 0.0f;
					scoreManager->P1Bonus = 1;
				}
			}

			if (p2TicketTimer > 0.0f) {
				p2TicketTimer -= TIME_GET_DELTATIME();
				if (p2TicketTimer <= 0.0f) {
					p2TicketTimer = 0.0f;
					scoreManager->P2Bonus = 1;
				}
			}
			if (p1IceTimer > 0.0f) {
				p1IceTimer -= TIME_GET_DELTATIME();
				if (p1IceTimer <= 0.0f) {
					p1IceTimer = 0.0f;
					//���� ����
				}
			}

			if (p2IceTimer > 0.0f) {
				p2IceTimer -= TIME_GET_DELTATIME();
				if (p2IceTimer <= 0.0f) {
					p2IceTimer = 0.0f;
					//���� ����
				}
			}
		}
		void UseItem(int player, ItemType item)
		{
			switch (item) {
			case ItemType::Bomb:
				if (player == 1) {
					//P1�� ��������Ʈ ���� ��ü ī��Ʈ
					//P1�� ��������Ʈ ���� ��ü ���� ����
					if (p1count >= 1 && p1count <= 3) {
						scoreManager->P1Score += 3 * scoreManager->P1Bonus;
					}
					else if (p1count >= 4 && p1count <= 6) {
						scoreManager->P1Score += 5 * scoreManager->P1Bonus;
					}
					else if (p1count >= 7) {
						scoreManager->P1Score += 7 * scoreManager->P1Bonus;
					}
				}
				else {
					//P2�� ��������Ʈ ���� ��ü ī��Ʈ
					//P2�� ��������Ʈ ���� ��ü ���� ����
					if (p2count >= 1 && p2count <= 3) {
						scoreManager->P2Score += 3 * scoreManager->P2Bonus;
					}
					else if (p2count >= 4 && p2count <= 6) {
						scoreManager->P2Score += 5 * scoreManager->P2Bonus;
					}
					else if (p2count >= 7) {
						scoreManager->P2Score += 7 * scoreManager->P2Bonus;
					}
				}
				break;
			case ItemType::Icebomb:
				if (player == 1) {
					//P1�� ��������Ʈ ���� ��ü ���� �̵� ����
					//P1�� ��������Ʈ ���� ��ü ���� ���� �ð� ����
					p1IceTimer = timelimit;
				}
				else {
					//P2�� ��������Ʈ ���� ��ü ���� �̵� ����
					//P2�� ��������Ʈ ���� ��ü ���� ���� �ð� ����
					p2IceTimer = timelimit;
				}
				break;
			case ItemType::Ticket:
				if (player == 1) {
					scoreManager->P1Bonus = 2;
					p1TicketTimer = timelimit;
				}
				else {
					scoreManager->P2Bonus = 2;
					p2TicketTimer = timelimit;
				}
				break;
			}
		}
	};
}