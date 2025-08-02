#pragma once
#include <ScriptBehaviour.h>
#include "RumbleAnimationClip.h"

namespace GOTOEngine
{
	class GamepadRumbleManager : public ScriptBehaviour
	{
	private:
		struct ActiveRumble
		{
			RumbleAnimationClip clip;
			float elapsedTime = 0.0f;
			float weight = 1.0f;
			int id = -1;

			bool isFinished = false; // <-- 애니메이션 종료를 나타내는 플래그
			ActiveRumble(int id, const RumbleAnimationClip& clip, float weight)
				: id(id)
				, clip(clip)
				, weight(weight)
			{

			}
		};
		std::vector<ActiveRumble> m_activeRumbles;
	public:
    GamepadRumbleManager()
    {
        SetExecutionOrder(-10);
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }
		static GamepadRumbleManager* instance;
		void Update();
		void Awake();
		void Play(int padID, const RumbleAnimationClip& rumbleClip, float weight);
		void ClearFinishedClips();
	};
}