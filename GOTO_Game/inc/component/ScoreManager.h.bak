#pragma once
#include <ScriptBehaviour.h>
#include <RenderManager.h>
#include <SpriteRenderer.h>
#include <TimeManager.h>
#include <InputManager.h>
#include <Text.h>
#include "RectTransform.h"
#include "Screen.h"

namespace GOTOEngine
{
	class ScoreManager : public ScriptBehaviour
	{
	public:
    ScoreManager()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }
		int P1Score = 0;
		int P2Score = 0;
		int P1Bonus = 1;
		int P2Bonus = 1;
		static int winner;
		float GameTimer = 120.0f;
		static ScoreManager* instance;
		Text* P1sctext;
		Text* P2sctext;
		Text* Timetext;
		void Awake();
		void Update();
	};
}