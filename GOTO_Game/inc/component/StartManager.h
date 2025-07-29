#pragma once
#include <ScriptBehaviour.h>
#include <RenderManager.h>
#include <SpriteRenderer.h>
#include <InputManager.h>
#include <SceneManager.h>
#include "Canvas.h"
#include "Image.h"
#include "RectTransform.h"
#include "Screen.h"

namespace GOTOEngine
{
	class StartManager : public ScriptBehaviour
	{
	public:
    StartManager()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }
		/*int menuchoice = 1;*/
		static StartManager* instance;
		void Awake() {

			if (!instance)
			{
				instance = this;
			}
			else
			{
				Destroy(GetGameObject());
			}
		}
		void Update() {
			//switch (menuchoice) {
			//case 1:
			//	if (INPUT_GET_KEYDOWN(KeyCode::Space)) {
			//		SCENE_CHANGE_SCENE(L"TestItemScene");
			//	}
			//	if (INPUT_GET_KEYDOWN(KeyCode::DownArrow)) {
			//		menuchoice = 2;
			//	}
			//case 2:
			//	if (INPUT_GET_KEYDOWN(KeyCode::Space)) {
			//		//메뉴창 띄우기
			//	}
			//	if (INPUT_GET_KEYDOWN(KeyCode::UpArrow)) {
			//		menuchoice = 1;
			//	}
			//	if (INPUT_GET_KEYDOWN(KeyCode::DownArrow)) {
			//		menuchoice = 3;
			//	}
			//case 3:
			//	if (INPUT_GET_KEYDOWN(KeyCode::Space)) {
			//		//게임종료
			//	}
			//	if (INPUT_GET_KEYDOWN(KeyCode::UpArrow)) {
			//		menuchoice = 2;
			//	}
			//}
		}
	};
}