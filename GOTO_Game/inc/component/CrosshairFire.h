#pragma once
#include <ScriptBehaviour.h>
#include <GameObject.h>
#include <Delegate.h>
#include <CrosshairCollide.h>
#include "IAttackAble.h"
#include "GamepadRumbleManager.h"
#include "RumbleAnimationClip.h"

namespace GOTOEngine
{
	class CrosshairFire : public ScriptBehaviour
	{
	private:
		CrosshairCollide* m_collider = nullptr; // Collider2D ������Ʈ
		float m_fireCooldown = 0.0f; // �߻� ��Ÿ��

		bool m_RightTriggerCheckTrigger;
		bool m_RightTriggerPressed;

		static RumbleAnimationClip* s_pfireRumbleClip;
		static int s_crosshairCount;
	public:
    CrosshairFire()
    {
        SetExecutionOrder(10);
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
        REGISTER_BEHAVIOUR_MESSAGE(OnDestroy);
        REGISTER_BEHAVIOUR_MESSAGE(OnEnable);
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }

		float fireRate = 0.5f; // �߻� ����
		int id = 0;
		Delegate<void,int> onFire;

		void Awake();

		void OnEnable();

		void OnDestroy();
		
		void TriggerPressedCheck();

		void TriggerPressedCheckReset();

		void Update();
	};
}