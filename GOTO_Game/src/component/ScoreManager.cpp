#include "ScoreManager.h"
using namespace GOTOEngine;
ScoreManager* ScoreManager::instance = nullptr;

void ScoreManager::Awake(){
	if (!instance)
	{
		instance = this;
	}
	else
	{
		Destroy(GetGameObject());
	}
	auto canvas = GameObject::Find(L"Canvas");
	auto p1scitem = new GameObject;
	auto p2scitem = new GameObject;
	auto timeitem = new GameObject;
	p1scitem->GetTransform()->SetParent(canvas->GetTransform());
	p2scitem->GetTransform()->SetParent(canvas->GetTransform());
	timeitem->GetTransform()->SetParent(canvas->GetTransform());
	P1sctext = p1scitem->AddComponent<Text>();
	P2sctext = p1scitem->AddComponent<Text>();
	Timetext = p1scitem->AddComponent<Text>();
	P1sctext->GetRectTransform()->SetAnchoredPosition({
			Screen::GetWidth() * 0.2f, Screen::GetHeight() * 0.8f });
	P2sctext->GetRectTransform()->SetAnchoredPosition({
			Screen::GetWidth() * 0.8f, Screen::GetHeight() * 0.8f });
	Timetext->GetRectTransform()->SetAnchoredPosition({
			Screen::GetWidth() * 0.4f, Screen::GetHeight() * 0.8f });
}
void ScoreManager::Update() {
	if (GameTimer > 0.0f) {
		GameTimer -= TIME_GET_DELTATIME();
		if (GameTimer <= 0.0f) {
			GameTimer = 0.0f;
			if (P1Score > P2Score) {
				winner = 1;
			}
			else if (P1Score < P2Score) {
				winner = 2;
			}
			else {
				winner = 0;
			}
		}
	}
	P1sctext->SetFont(L"../Resources/Maplestory Light.ttf");
	P2sctext->SetFont(L"../Resources/Maplestory Light.ttf");
	Timetext->SetFont(L"../Resources/Maplestory Light.ttf");
	P1sctext->text = std::to_wstring(P1Score);
	P2sctext->text = std::to_wstring(P2Score);
	Timetext->text = std::to_wstring(GameTimer);
}