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
            // �̹� �����ӿ� ������ x�� �������� ���
            float deltaX = sin(deltaTime * m_moveSpeed) * m_distance;

            // ���� ��ǥ�� �����ϴ� ���, '�̹� �������� ������'�� Vector3�� ��ȯ
            // ���� ��ġ�� ������� �� ��ȭ���� ��ȯ�ؾ� ��Ȯ������, ���⼭�� ������ ���÷� ��ü ��ǥ�� ������� ���
            // �� ��Ȯ�� ������ (���� ��ġ + ��ȭ��) - ���� ��ġ = ��ȭ�� �� ��ȯ�ϴ� ����Դϴ�.
            // ���⼭�� ������ ���� x ��ġ�� ���� ������Ʈ�� x ��ġ�� ���̸� ��ȯ�ϴ� ������ ������ �� �ֽ��ϴ�.
            //float currentX = GetGameObject()->GetTransform()
            float nextX = m_initialPosition.x + deltaX;

            return Vector2(nextX - m_initialPosition.x, 0);
        }
    };
}