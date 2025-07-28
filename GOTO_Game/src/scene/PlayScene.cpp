#include "PlayScene.h"
#include "Camera.h"
#include "SpriteRenderer.h"
#include "Animator.h"
#include "AnimatorController.h"
#include "PlayerFSMController.h"


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
}
