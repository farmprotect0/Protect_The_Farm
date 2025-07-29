#include "CrosshairPrefab.h"
#include "CrosshairMove.h"
#include "CrosshairFire.h"

#include <GameObject.h>
#include <SpriteRenderer.h>

using namespace GOTOEngine;

GameObject* CrosshairPrefab::CreateCrosshair(int id)
{
	auto GO = new GameObject(L"Player");
	GO->AddComponent<CrosshairMove>()->id = id;
	GO->AddComponent<CrosshairFire>()->id = id;

	auto spriteRenderer = GO->AddComponent<SpriteRenderer>();
	spriteRenderer->SetSprite(id == 0 ? L"../Resources/Demo/Crosshair.png" : L"../Resources/Demo/Crosshair2.png");
	spriteRenderer->SetRenderOrder(1000 - id); // 커서가 항상 위에 보이도록 설정

	return GO;
}