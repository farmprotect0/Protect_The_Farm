#pragma once
#include "BaseMovement.h"
#include <TimeManager.h>

#include <math.h>

// enemy에 쓰이는 movement 입니다.

namespace GOTOEngine
{
    class MoveUpDown : public BaseMovement
    {
    private:
        Vector2 m_initialPosition;
        float m_distance = 5.0f;

    public:
        void Awake() override
        {
            __super::Awake();

            m_initialPosition = GetGameObject()->GetTransform()->GetPosition();

            m_moveSpeed = 140.0f;

            m_role = E_Move_Role::PATH;
        }
        Vector2 Move(float deltaTime) override
        {
            if (m_isLoop)
            {
                return Vector2(0, m_moveSpeed * m_flipDirection * deltaTime);
            }
            else
            {
                float totalTime = TimeManager::Get()->GetTime();
                float deltaY = sin(deltaTime * m_moveSpeed) * m_distance;
                return Vector2(0, deltaY);
            }
        }

    };
}