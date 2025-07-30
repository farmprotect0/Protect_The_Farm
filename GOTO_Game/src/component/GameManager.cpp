#include "GameManager.h"

using namespace GOTOEngine;
GameManager* GameManager::instance = nullptr;

void GameManager::Awake(){
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
	P1sctext = p1scitem->AddComponent<Text>();
	P2sctext = p2scitem->AddComponent<Text>();
	Timetext = timeitem->AddComponent<Text>();

	p1scitem->GetTransform()->SetParent(canvas->GetTransform());
	p2scitem->GetTransform()->SetParent(canvas->GetTransform());
	timeitem->GetTransform()->SetParent(canvas->GetTransform());

	P1sctext->GetRectTransform()->SetAnchoredPosition({
			Screen::GetWidth() * 0.2f, Screen::GetHeight() * 0.8f });
	P2sctext->GetRectTransform()->SetAnchoredPosition({
			Screen::GetWidth() * 0.8f, Screen::GetHeight() * 0.8f });
	Timetext->GetRectTransform()->SetAnchoredPosition({
			Screen::GetWidth() * 0.5f, Screen::GetHeight() * 0.8f });

	P1sctext->SetFont(L"../Resources/Maplestory Light.ttf");
	P2sctext->SetFont(L"../Resources/Maplestory Light.ttf");
	Timetext->SetFont(L"../Resources/Maplestory Light.ttf");
	P1sctext->SetColor({ 255,0,0,255 });
	P2sctext->SetColor({ 255,0,0,255 });
	Timetext->SetColor({ 255,0,0,255 });

}
void GameManager::Update() {
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
	if (P1Score < 0) {
		winner = 2;
	}
	if (P2Score < 0) {
		winner = 1;
	}

	P1sctext->text = std::to_wstring(P1Score);
	P2sctext->text = std::to_wstring(P2Score);
	Timetext->text = std::to_wstring(static_cast<int>(floor(GameTimer)));
}

int GOTOEngine::GameManager::winner = 0;