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
	class EnemySpawner;
	class GameManager : public ScriptBehaviour
	{
	private:
		bool p1active = false;
		bool p2active = false;
		float NormalTiming = 125.0f;
		float GimmickTiming = 120.0f;
		float ItemTiming = 120.0f;

		Text* P1sctext;
		Text* P2sctext;
		Text* Timetext;

		GameObject* Tutorial;
		EnemySpawner* EnemySpawner;

	public:
    GameManager()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
        REGISTER_BEHAVIOUR_MESSAGE(OnDestroy);
        REGISTER_BEHAVIOUR_MESSAGE(Start);
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }
		int P1Score = 0;
		int P2Score = 0;
		int P1Bonus = 1;
		int P2Bonus = 1;
		static int winner;
		float GameTimer = 120.0f;
		static GameManager* instance;
		bool setactive = false;
		void Awake();
		void Start();
		void Update();
		void OnDestroy();
	};
}