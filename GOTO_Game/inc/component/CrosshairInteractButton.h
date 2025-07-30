#pragma once
#include <ScriptBehaviour.h>
#include <TimeManager.h>
#include "IAttackAble.h"

namespace GOTOEngine
{
	class CrosshairInteractButton : public ScriptBehaviour, public IAttackAble
	{
	public:
    CrosshairInteractButton()
    {

    }
		Transform* parentButton = nullptr; // 부모 버튼 Transform
		float interactedTime;
		bool isInteracted;

		void TakeDamage(float dmg) override
		{
			isInteracted = true;
			interactedTime = TIME_GET_TOTALTIME();
		}
	};
}