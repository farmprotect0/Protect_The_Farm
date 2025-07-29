#pragma once
#include "BaseMovement.h"
#include <math.h>

namespace GOTOEngine
{
    class MoveLeftRight : public BaseMovement
    {
    private:
        Vector2 m_initialPosition;

        float m_distance = 5.0f;

    public:
        void Awake() override
        {
            __super::Awake();
            
            m_initialPosition = GetGameObject()->GetTransform()->GetPosition();

        }
        Vector2 Move(float deltaTime) override
        {
            // 이번 프레임에 움직일 x축 변위값만 계산
            float deltaX = sin(deltaTime * m_moveSpeed) * m_distance;

            // 절대 좌표를 설정하는 대신, '이번 프레임의 움직임'만 Vector3로 반환
            // 이전 위치를 기반으로 한 변화량을 반환해야 정확하지만, 여기서는 간단한 예시로 전체 좌표를 기반으로 계산
            // 더 정확한 구현은 (현재 위치 + 변화량) - 현재 위치 = 변화량 을 반환하는 방식입니다.
            // 여기서는 간단히 계산된 x 위치와 현재 오브젝트의 x 위치의 차이를 반환하는 식으로 구현할 수 있습니다.
            //float currentX = GetGameObject()->GetTransform()
            float nextX = m_initialPosition.x + deltaX;

            return Vector2(nextX - m_initialPosition.x, 0);
        }
    };
}