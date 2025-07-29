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
	auto p1item = new GameObject;
	auto p2item = new GameObject;
	p1item->GetTransform()->SetParent(canvas->GetTransform());
	p2item->GetTransform()->SetParent(canvas->GetTransform());
	p1itemImage = p1item->AddComponent<Image>();
	p2itemImage = p2item->AddComponent<Image>();
	p1itemImage->GetRectTransform()->SetAnchoredPosition({ Screen::GetWidth() * 0.2f, Screen::GetHeight() * 0.5f });
	p2itemImage->GetRectTransform()->SetAnchoredPosition({ Screen::GetWidth() * 0.8f, Screen::GetHeight() * 0.5f });
	p1itemImage->GetRectTransform()->SetSizeDelta({ 200.0f,200.0f });
	p2itemImage->GetRectTransform()->SetSizeDelta({ 200.0f,200.0f });
}

void ItemManager::Update(){

	auto sss = p1Items;

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
			//빙결 해제
		}
	}

	if (p2IceTimer > 0.0f) {
		p2IceTimer -= TIME_GET_DELTATIME();
		if (p2IceTimer <= 0.0f) {
			p2IceTimer = 0.0f;
			//빙결 해제
		}
	}
	if (!p1Items.empty()) {
		if (p1Items.front() == ItemType::Bomb) {
			p1itemImage->SetSprite(L"../Resources/ball2.png");
		}
		else if (p1Items.front() == ItemType::Icebomb) {
			p1itemImage->SetSprite(L"../Resources/ball3.png");
		}
		else if (p1Items.front() == ItemType::Ticket) {
			p1itemImage->SetSprite(L"../Resources/ball1.png");
		}
	}
	else {
		p1itemImage->SetSprite(nullptr);
	}
	if (!p2Items.empty()) {
		if (p2Items.front() == ItemType::Bomb) {
			p2itemImage->SetSprite(L"../Resources/ball2.png");
		}
		else if (p2Items.front() == ItemType::Icebomb) {
			p2itemImage->SetSprite(L"../Resources/ball3.png");
		}
		else if (p2Items.front() == ItemType::Ticket) {
			p2itemImage->SetSprite(L"../Resources/ball1.png");
		}
	}
	else {
		p2itemImage->SetSprite(nullptr);
	}
}

void ItemManager::UseItem(int player, ItemType item)
{
	switch (item) {
	case ItemType::Bomb:
		if (player == 1) {
			//P1의 동물리스트 내부 객체 카운트
			//P1의 동물리스트 내부 객체 전부 삭제
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
			//P2의 동물리스트 내부 객체 카운트
			//P2의 동물리스트 내부 객체 전부 삭제
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
			//P1의 동물리스트 내부 객체 전부 이동 정지
			//P1의 동물리스트 내부 객체 전부 디스폰 시간 정지
			p1IceTimer = timelimit;
		}
		else {
			//P2의 동물리스트 내부 객체 전부 이동 정지
			//P2의 동물리스트 내부 객체 전부 디스폰 시간 정지
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