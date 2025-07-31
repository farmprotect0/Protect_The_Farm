#include "TutorialImage.h"

using namespace GOTOEngine;
TutorialImage* TutorialImage::instance = nullptr;

void TutorialImage::Awake() {
	if (!instance)
	{
		instance = this;
	}
	else
	{
		Destroy(GetGameObject());
	}
	auto canvas = GameObject::Find(L"Canvas");
	auto object = new GameObject;
	object->GetTransform()->SetParent(canvas->GetTransform());
	explanation = object->AddComponent<Image>();
	explanation->GetRectTransform()->SetAnchoredPosition({
		Screen::GetWidth() * 0.2f, Screen::GetHeight() * 0.2f });
	explanation->GetRectTransform()->SetSizeDelta({ 
		Screen::GetWidth() * 0.6f, Screen::GetHeight() * 0.6f });
}

void TutorialImage::OnDestroy() {
	if (instance == this)
		instance = nullptr;
}

void TutorialImage::Update() {
	switch (explainnum) {
	case 1:
		explanation->SetSprite(nullptr);
		if (INPUT_GET_KEYDOWN(KeyCode::RightShift)) {
			explainnum = 2;
		}
	case 2:
		explanation->SetSprite(nullptr);
		if (INPUT_GET_KEYDOWN(KeyCode::LeftShift)) {
			explainnum = 1;
		}
		if (INPUT_GET_KEYDOWN(KeyCode::RightShift)) {
			explainnum = 3;
		}
	case 3:
		explanation->SetSprite(nullptr);
		if (INPUT_GET_KEYDOWN(KeyCode::LeftShift)) {
			explainnum = 2;
		}
		if (INPUT_GET_KEYDOWN(KeyCode::RightShift)) {
			explainnum = 4;
		}
	case 4:
		explanation->SetSprite(nullptr);
		if (INPUT_GET_KEYDOWN(KeyCode::LeftShift)) {
			explainnum = 3;
		}
	}
}