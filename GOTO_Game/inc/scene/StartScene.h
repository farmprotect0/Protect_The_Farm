#pragma once
#include <Scene.h>
#include <string>
#include <memory>

using namespace GOTOEngine;
class StartScene : public Scene
{
public:
	StartScene(const std::wstring& sceneName) : Scene(sceneName) {}
	void Initialize() override;
};

