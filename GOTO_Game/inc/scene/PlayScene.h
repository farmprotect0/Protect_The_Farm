#pragma once
#include "Scene.h"

using namespace GOTOEngine;
class PlayScene : public Scene
{
public:
	PlayScene(const std::wstring& sceneName) : Scene(sceneName) {}
	void Initialize() override;
};
