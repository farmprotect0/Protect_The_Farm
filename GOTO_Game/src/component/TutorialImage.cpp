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
	auto expobject = new GameObject;
	Tutorialobject.push_back(expobject);
	expobject->GetTransform()->SetParent(canvas->GetTransform());
	explanation = expobject->AddComponent<Image>();
	explanation->GetRectTransform()->SetAnchoredPosition({
		Screen::GetWidth() * 0.2f, Screen::GetHeight() * 0.2f });
	explanation->GetRectTransform()->SetSizeDelta({ 
		Screen::GetWidth() * 0.6f, Screen::GetHeight() * 0.6f });
	auto p1bobject = new GameObject;
	Tutorialobject.push_back(p1bobject);
	p1bobject->GetTransform()->SetParent(canvas->GetTransform());
	p1button = p1bobject->AddComponent<Image>();
	p1button->GetRectTransform()->SetAnchoredPosition({
		Screen::GetWidth() * 0.25f, Screen::GetHeight() * 0.23f });
	p1button->GetRectTransform()->SetSizeDelta({
		Screen::GetWidth() * 0.021f, Screen::GetHeight() * 0.035f });
	auto p2bobject = new GameObject;
	Tutorialobject.push_back(p2bobject);
	p2bobject->GetTransform()->SetParent(canvas->GetTransform());
	p2button = p2bobject->AddComponent<Image>();
	p2button->GetRectTransform()->SetAnchoredPosition({
		Screen::GetWidth() * 0.72f, Screen::GetHeight() * 0.23f });
	p2button->GetRectTransform()->SetSizeDelta({
		Screen::GetWidth() * 0.021f, Screen::GetHeight() * 0.035f });
	p1button->SetSprite(L"../Resources/artResource/UI/Tutorial/OKButton_basic.png");
	p2button->SetSprite(L"../Resources/artResource/UI/Tutorial/OKButton_basic.png");
}

void TutorialImage::OnDestroy() {
	if (instance == this)
		instance = nullptr;
	for (auto obj : Tutorialobject) {
		Destroy(obj);
		obj = nullptr;
	}
}

void TutorialImage::Update() {
	switch (explainnum) {
	case 1:
		explanation->SetSprite(L"../Resources/artResource/UI/Tutorial/Tutorial_1.png");
		if (INPUT_GET_KEYDOWN(KeyCode::RightShift)) {
			explainnum = 2;
		}
		break;
	case 2:
		explanation->SetSprite(L"../Resources/artResource/UI/Tutorial/Tutorial_2.png");
		if (INPUT_GET_KEYDOWN(KeyCode::LeftShift)) {
			explainnum = 1;
		}
		if (INPUT_GET_KEYDOWN(KeyCode::RightShift)) {
			explainnum = 3;
		}
		break;
	case 3:
		explanation->SetSprite(L"../Resources/artResource/UI/Tutorial/Tutorial_3.png");
		if (INPUT_GET_KEYDOWN(KeyCode::LeftShift)) {
			explainnum = 2;
		}
		if (INPUT_GET_KEYDOWN(KeyCode::RightShift)) {
			explainnum = 4;
		}
		break;
	case 4:
		explanation->SetSprite(L"../Resources/artResource/UI/Tutorial/Tutorial_4.png");
		if (INPUT_GET_KEYDOWN(KeyCode::LeftShift)) {
			explainnum = 3;
		}
		if (INPUT_GET_KEYDOWN(KeyCode::RightShift)) {
			explainnum = 5;
		}
		break;
	case 5:
		explanation->SetSprite(L"../Resources/artResource/UI/Tutorial/Tutorial_5.png");
		if (INPUT_GET_KEYDOWN(KeyCode::LeftShift)) {
			explainnum = 4;
		}
		break;
	}
	if (INPUT_GET_KEYDOWN(KeyCode::Alpha1)) {
		p1button->SetSprite(L"../Resources/artResource/UI/Tutorial/OKButton_1.png");
	}
	if (INPUT_GET_KEYDOWN(KeyCode::Alpha0)) {
		p2button->SetSprite(L"../Resources/artResource/UI/Tutorial/OKButton_2.png");
	}
}