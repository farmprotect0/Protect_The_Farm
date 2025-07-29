#include "PlayScene.h"
#include "Camera.h"
#include "SpriteRenderer.h"
#include "Animator.h"
#include "AnimatorController.h"
#include "PlayerFSMController.h"
#include <Image.h>
#include <Canvas.h>
#include <RectTransform.h>


void PlayScene::Initialize()
{
	auto player1CamGO = Camera::CreateMainCamera();
	auto player1Cam = player1CamGO->GetComponent<Camera>();
	player1Cam->SetRect({ 0.0f, 0.0f, 0.5f, 1.0f });

	auto player2CamGO = Camera::CreateSubCamera();
	auto player2Cam = player2CamGO->GetComponent<Camera>();
	player2Cam->SetRect({ 0.5f, 0.0f, 0.5f, 1.0f });


	auto player = new GameObject(L"플레이어");

	player->AddComponent<SpriteRenderer>()->AddComponent<SpriteRenderer>();
	player->AddComponent<Animator>()->SetAnimatorController(Resource::Load<AnimatorController>(L"../Resources/Animation/controller/KnightAnimator_AnimController.json"));

	player->AddComponent<PlayerFSMController>();

	player->GetTransform()->SetLocalScale({ 10.0f,10.0f });


	auto canvasGO = new GameObject(L"UI");
	auto canvas = canvasGO->AddComponent<Canvas>();

	canvas->SetSortOrder(1000); // UI는 높은 렌더링 순서로 설정

	auto simpleImage = new GameObject(L"SimpleImage");
	auto imageComp = simpleImage->AddComponent<Image>();
	
	imageComp->SetSprite(Resource::Load<Sprite>(L"../Resources/Demo/Crosshair.png"));
	simpleImage->GetComponent<RectTransform>()->SetAnchoredPosition({ 960.0f, 540.0f });

	simpleImage->GetComponent<RectTransform>()->SetParent(canvasGO->GetTransform(), false);
}
