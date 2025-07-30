#include "CrosshairPrefab.h"
#include "CrosshairMove.h"
#include "CrosshairFire.h"

#include <GameObject.h>
#include <SpriteRenderer.h>
#include <Collider2D.h>

using namespace GOTOEngine;

GameObject* CrosshairPrefab::CreateCrosshair(int id)
{
	auto GO = new GameObject(L"Player");
	GO->AddComponent<CrosshairMove>()->id = id;
	GO->AddComponent<CrosshairFire>()->id = id;

	auto spriteRenderer = GO->AddComponent<SpriteRenderer>();
	spriteRenderer->SetSprite(id == 0 ? L"../Resources/Demo/Crosshair.png" : L"../Resources/Demo/Crosshair2.png");
	spriteRenderer->SetRenderOrder(1000 - id); // 커서가 항상 위에 보이도록 설정

    spriteRenderer->SetRenderLayer(static_cast<size_t>(1ULL << (id + 1)));

	GO->AddComponent<Collider2D>()->SetSize({ 100.0f, 100.0f }); // Collider 크기 조정

	return GO;
}