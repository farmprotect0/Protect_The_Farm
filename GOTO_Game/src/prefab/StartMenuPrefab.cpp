#include "StartMenuPrefab.h"
#include <GameObject.h>
#include <Canvas.h>

using namespace GOTOEngine;
GameObject* StartMenuPrefab::CreateStartMenu()
{
	auto GO = new GameObject(L"StartMenu");


	return GO;
}
