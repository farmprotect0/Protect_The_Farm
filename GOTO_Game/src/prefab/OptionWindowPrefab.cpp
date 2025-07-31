#include "OptionWindowPrefab.h"
#include "StartMenu.h"
#include "CrosshairInteractButton.h"
#include "OptionWindowSystem.h"
#include "ButtonAnimation.h"

#include <GameObject.h>
#include <Canvas.h>
#include <SpriteRenderer.h>
#include <Collider2D.h>

using namespace GOTOEngine;
GameObject* GOTOEngine::OptionWindowPrefab::CreateOptionWindow()
{
    //루트 오브젝트
	auto GO = new GameObject(L"OptionWindow");

	auto optionWindowSystem = GO->AddComponent<OptionWindowSystem>();

	auto baseWindow = new GameObject(L"BaseWindow");
	auto baseWindowSprite = baseWindow->AddComponent<SpriteRenderer>();
	baseWindowSprite->SetSprite(L"../Resources/Demo/OptionWindow.png");
	baseWindowSprite->SetRenderOrder(500);
	baseWindow->GetTransform()->SetParent(GO->GetTransform(), false);
	baseWindow->GetTransform()->SetLocalScale({ 0.0f, 0.0f });

	optionWindowSystem->baseWindow = baseWindow->GetTransform();

    return GO;
}
