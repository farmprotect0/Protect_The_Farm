#include "CrosshairPrefab.h"
#include "CrosshairCollide.h"
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
	GO->AddComponent<CrosshairCollide>()->id = id;
	GO->layer = (1 << (id + 1)) | (1 << 0); // ���̾� ����: 1 << 1 for Player 1, 1 << 2 for Player 2

	auto spriteRenderer = GO->AddComponent<SpriteRenderer>();
	spriteRenderer->SetSprite(id == 0 ? L"../Resources/Demo/Crosshair.png" : L"../Resources/Demo/Crosshair2.png");
	spriteRenderer->SetRenderOrder(1000 - id); // Ŀ���� �׻� ���� ���̵��� ����

    spriteRenderer->SetRenderLayer((1 << (id + 1)));

	GO->AddComponent<Collider2D>()->SetSize({ 45.0f, 45.0f }); // Collider ũ�� ����

	return GO;
}