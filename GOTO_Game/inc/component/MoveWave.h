#pragma once
#include "BaseMovement.h"
#include <TimeManager.h>
#include <math.h>

// enemy에 쓰이는 movement 입니다.

namespace GOTOEngine
{
    class MoveWave : public BaseMovement
    {
    private:
        float m_amplitude = 25.0f; // 진폭 (물결의 높이)
        float m_frequency = 5.0f;  // 진동수 (물결의 빽빽함)

    public:
        void Awake() override
        {
            __super::Awake();
            m_role = E_Move_Role::OFFSET;
        }

        Vector2 Move(float deltaTime) override
        {
            float totalTime = TimeManager::Get()->GetTime();
            float offsetY = sin(totalTime * m_frequency) * m_amplitude;
            return Vector2(0, offsetY);
        }
    };
}