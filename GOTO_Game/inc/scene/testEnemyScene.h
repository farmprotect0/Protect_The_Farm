#pragma once
#include <Scene.h>
#include <string>
#include <memory>

// enemy test용으로 만든 씬

using namespace GOTOEngine;
class testEnemyScene : public Scene
{
public:
	testEnemyScene(const std::wstring& sceneName) : Scene(sceneName) {}
	void Initialize() override;
};