#include "OptionWindowPrefab.h"
#include "StartMenu.h"
#include "CrosshairInteractButton.h"
#include "OptionWindowSystem.h"
#include "ButtonAnimation.h"
#include "GageSprite.h"

#include <GameObject.h>
#include <Canvas.h>
#include <SpriteRenderer.h>
#include <Collider2D.h>

using namespace GOTOEngine;
GameObject* GOTOEngine::OptionWindowPrefab::CreateOptionWindow()
{
    //��Ʈ ������Ʈ
	auto GO = new GameObject(L"OptionWindow");

	auto optionWindowSystem = GO->AddComponent<OptionWindowSystem>();

	// �� ��� â
	auto baseWindow = new GameObject(L"BaseWindow");
	auto baseWindowSprite = baseWindow->AddComponent<SpriteRenderer>();
	baseWindowSprite->SetSprite(L"../Resources/Demo/OptionWindow.png");
	baseWindowSprite->SetRenderOrder(500);
	baseWindow->GetTransform()->SetParent(GO->GetTransform(), false);
	baseWindow->GetTransform()->SetLocalScale({ 0.0f, 0.0f });

	optionWindowSystem->baseWindow = baseWindow->GetTransform();

	// �׸��
	//---- �����
	auto BGMGageSpriteGO = new GameObject(L"BG Gage");
	auto BGMGageSprite = BGMGageSpriteGO->AddComponent<GageSprite>();
	BGMGageSpriteGO->GetTransform()->SetParent(baseWindow->GetTransform());

	auto BGMGageBackGO = new GameObject(L"BG Gage - BackGround");
	BGMGageBackGO->GetTransform()->SetParent(BGMGageSpriteGO->GetTransform());
	auto BGMGageBackGORenderer = BGMGageBackGO->AddComponent<SpriteRenderer>();
	BGMGageSprite->backgroundRenderer = BGMGageBackGORenderer;


	BGMGageSpriteGO->GetTransform()->SetLocalPosition({ -580.0f * 0.5f,0.0f });

	auto BGMGageBarGO = new GameObject(L"BG Gage - GageBar");
	BGMGageBarGO->GetTransform()->SetParent(BGMGageSpriteGO->GetTransform());
	auto BGMGageBarGORenderer = BGMGageBarGO->AddComponent<SpriteRenderer>();
	BGMGageSprite->gagebarRenderer = BGMGageBarGORenderer;

	auto BGMGageHandleGO = new GameObject(L"BG Gage - GageHandle");
	BGMGageHandleGO->GetTransform()->SetParent(BGMGageSpriteGO->GetTransform());
	auto BGMGageHandleGORenderer = BGMGageHandleGO->AddComponent<SpriteRenderer>();
	BGMGageSprite->gagehandleRenderer = BGMGageHandleGORenderer;
	

	//---- ȿ����
	//---- 1P ����
	//---- 2P ����

	// ��Ŀ�� UI
	auto focusUI = new GameObject(L"FocusUI");
	auto focusUISprite = focusUI->AddComponent<SpriteRenderer>();
	focusUISprite->SetSprite(L"../Resources/Demo/FocusUI.png");
	focusUISprite->SetRenderOrder(501);
	focusUI->GetTransform()->SetParent(baseWindow->GetTransform(), false);

	optionWindowSystem->focusUITransform = focusUI->GetTransform();


    return GO;
}
