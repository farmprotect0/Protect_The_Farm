// 콘솔을 겸용한 진입점을 정의합니다.

// 기본 라이브러리
#include <iostream>
#include <Windows.h>

// 엔진 및 매니저
#include "Engine.h"
#include "SceneManager.h"

// 씬
//#include "TitleScene.h"
//#include "SampleScene.h"
//#include "AnimationScene.h"
//#include "PhysicsScene.h"
#include "PlayScene.h"
#include "StartScene.h"
#include "TestItemScene.h"

void StartEngineLoop()
{
	ENGINE_INIT(1920, 1080, L"D2D Game");

	//씬 할당 및 추가
	//SCENE_ADD_SCENE<TitleScene>(L"Title");
	//SCENE_ADD_SCENE<SampleScene>(L"SampleScene");
	//SCENE_ADD_SCENE<AnimationScene>(L"AnimationScene");
	//SCENE_ADD_SCENE<PhysicsScene>(L"PhysicsScene");
	SCENE_ADD_SCENE<PlayScene>(L"PlayScene");
	SCENE_ADD_SCENE<TestItemScene>(L"TestItemScene");
	SCENE_ADD_SCENE<StartScene>(L"StartScene");

	//첫 씬으로 변환
	SCENE_CHANGE_SCENE(L"StartScene");

	ENGINE_RUN();
	ENGINE_SHUTDOWN();
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	StartEngineLoop();
	return 0;
}

int main()
{
	StartEngineLoop();
	return 0;
}