#pragma once
#include <Scene.h>
#include <string>
#include <memory>

using namespace GOTOEngine;
class TestItemScene : public Scene
{
public:
	TestItemScene(const std::wstring& sceneName) : Scene(sceneName) {}
	void Initialize() override;
};

