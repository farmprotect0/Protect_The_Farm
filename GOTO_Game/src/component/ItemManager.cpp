#include "ItemManager.h"
#include "ScoreManager.h"

using namespace GOTOEngine;

ItemManager* ItemManager::instance = nullptr;

void ItemManager::Awake() {

	if (!instance)
	{
		instance = this;
	}
	else
	{
		Destroy(GetGameObject());
	}
	auto canvas = GameObject::Find(L"Canvas");
	// �̹��� ���� �� �⺻ ��ġ ����
	float spacing = 60.0f;
	Vector2 p1StartPos = { Screen::GetWidth() * 0.1f, Screen::GetHeight() * 0.5f };
	Vector2 p2StartPos = { Screen::GetWidth() * 0.6f, Screen::GetHeight() * 0.5f };

	for (int i = 0; i < 7; ++i)
	{
		// �÷��̾� 1 ������ ������Ʈ ���� �� ����
		auto p1item = new GameObject;
		p1item->GetTransform()->SetParent(canvas->GetTransform());
		p1itemImage[i] = p1item->AddComponent<Image>();
		p1itemImage[i]->GetRectTransform()->SetAnchoredPosition({
			p1StartPos.x + spacing * i, p1StartPos.y });
		p1itemImage[i]->GetRectTransform()->SetSizeDelta({ 50.0f, 50.0f });

		// �÷��̾� 2 ������ ������Ʈ ���� �� ����
		auto p2item = new GameObject;
		p2item->GetTransform()->SetParent(canvas->GetTransform());
		p2itemImage[i] = p2item->AddComponent<Image>();
		p2itemImage[i]->GetRectTransform()->SetAnchoredPosition({
			p2StartPos.x + spacing * i, p2StartPos.y });
		p2itemImage[i]->GetRectTransform()->SetSizeDelta({ 50.0f, 50.0f });
	}
}

void ItemManager::Update(){

	auto sss = p1Items;

	if (INPUT_GET_KEYDOWN(KeyCode::Alpha1)) {
		if (!p1Items.empty()) {
			ItemType item = p1Items[0];
			UseItem(1, item);
			p1Items.erase(p1Items.begin());
		}
	}
	if (INPUT_GET_KEYDOWN(KeyCode::Alpha2)) {
		if (!p2Items.empty()) {
			ItemType item = p2Items[0];
			UseItem(2, item);
			p2Items.erase(p2Items.begin());
		}
	}
	if (INPUT_GET_KEYDOWN(KeyCode::Alpha3)) {
		AddItem(1, ItemType::Bomb);
	}
	if (INPUT_GET_KEYDOWN(KeyCode::Alpha4)) {
		AddItem(1, ItemType::Icebomb);
	}
	if (INPUT_GET_KEYDOWN(KeyCode::Alpha5)) {
		AddItem(1, ItemType::Ticket);
	}
	if (INPUT_GET_KEYDOWN(KeyCode::Alpha6)) {
		AddItem(2, ItemType::Bomb);
	}
	if (INPUT_GET_KEYDOWN(KeyCode::Alpha7)) {
		AddItem(2, ItemType::Icebomb);
	}
	if (INPUT_GET_KEYDOWN(KeyCode::Alpha8)) {
		AddItem(2, ItemType::Ticket);
	}
	if (p1TicketTimer > 0.0f) {
		p1TicketTimer -= TIME_GET_DELTATIME();
		if (p1TicketTimer <= 0.0f) {
			p1TicketTimer = 0.0f;
			ScoreManager::instance->P1Bonus = 1;
		}
	}

	if (p2TicketTimer > 0.0f) {
		p2TicketTimer -= TIME_GET_DELTATIME();
		if (p2TicketTimer <= 0.0f) {
			p2TicketTimer = 0.0f;
			ScoreManager::instance->P2Bonus = 1;
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
	for (int i = 0; i < 7; ++i) {
		if (i < p1Items.size()) {
			ItemType item = p1Items[i];
			switch (item) {
			case ItemType::Bomb:
				p1itemImage[i]->SetSprite(L"../Resources/ball2.png");
				break;
			case ItemType::Icebomb:
				p1itemImage[i]->SetSprite(L"../Resources/ball3.png");
				break;
			case ItemType::Ticket:
				p1itemImage[i]->SetSprite(L"../Resources/ball1.png");
				break;
			}
		}
		else {
			p1itemImage[i]->SetSprite(nullptr);
		}
	}
	for (int i = 0; i < 7; ++i) {
		if (i < p2Items.size()) {
			ItemType item = p2Items[i];
			switch (item) {
			case ItemType::Bomb:
				p2itemImage[i]->SetSprite(L"../Resources/ball2.png");
				break;
			case ItemType::Icebomb:
				p2itemImage[i]->SetSprite(L"../Resources/ball3.png");
				break;
			case ItemType::Ticket:
				p2itemImage[i]->SetSprite(L"../Resources/ball1.png");
				break;
			}
		}
		else {
			p2itemImage[i]->SetSprite(nullptr);
		}
	}
}

void ItemManager::UseItem(int player, ItemType item)
{
	switch (item) {
	case ItemType::Bomb:
		if (player == 1) {
			//P1�� ��������Ʈ ���� ��ü ī��Ʈ
			//P1�� ��������Ʈ ���� ��ü ���� ����
			if (p1count >= 1 && p1count <= 3) {
				ScoreManager::instance->P1Score += 3 * ScoreManager::instance->P1Bonus;
			}
			else if (p1count >= 4 && p1count <= 6) {
				ScoreManager::instance->P1Score += 5 * ScoreManager::instance->P1Bonus;
			}
			else if (p1count >= 7) {
				ScoreManager::instance->P1Score += 7 * ScoreManager::instance->P1Bonus;
			}
		}
		else {
			//P2�� ��������Ʈ ���� ��ü ī��Ʈ
			//P2�� ��������Ʈ ���� ��ü ���� ����
			if (p2count >= 1 && p2count <= 3) {
				ScoreManager::instance->P2Score += 3 * ScoreManager::instance->P2Bonus;
			}
			else if (p2count >= 4 && p2count <= 6) {
				ScoreManager::instance->P2Score += 5 * ScoreManager::instance->P2Bonus;
			}
			else if (p2count >= 7) {
				ScoreManager::instance->P2Score += 7 * ScoreManager::instance->P2Bonus;
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
			ScoreManager::instance->P1Bonus = 2;
			p1TicketTimer = timelimit;
		}
		else {
			ScoreManager::instance->P2Bonus = 2;
			p2TicketTimer = timelimit;
		}
		break;
	}
}

void ItemManager::AddItem(int player, ItemType item) {
	if (player == 1) {
		if (p1Items.size() < 7) {
			p1Items.push_back(item);
		}
	}
	else {
		if (p2Items.size() < 7) {
			p2Items.push_back(item);
		}
	}
}