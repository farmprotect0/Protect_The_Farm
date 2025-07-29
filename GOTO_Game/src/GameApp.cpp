// �ܼ��� ����� �������� �����մϴ�.

// �⺻ ���̺귯��
#include <iostream>
#include <Windows.h>

// ���� �� �Ŵ���
#include "Engine.h"
#include "SceneManager.h"

// ��
#include "PlayScene.h"
#include "StartScene.h"
#include "TestItemScene.h"
#include "testEnemyScene.h"

void StartEngineLoop()
{
	ENGINE_INIT(1920, 1080, L"D2D Game");

	//�� �Ҵ� �� �߰�
	SCENE_ADD_SCENE<PlayScene>(L"PlayScene");
	SCENE_ADD_SCENE<TestItemScene>(L"TestItemScene");
	SCENE_ADD_SCENE<testEnemyScene>(L"testEnemyScene");
	SCENE_ADD_SCENE<StartScene>(L"StartScene");

	//ù ������ ��ȯ
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