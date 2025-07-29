#pragma once
#include <ScriptBehaviour.h>

namespace GOTOEngine
{
    enum E_Enemy_Move_Type
    {
        NONE = 0,					// �ƹ� ������ ���� (0000)
        MOVE_LEFT_RIGHT = 1 << 0,	// �¿� �̵� (0001)
        MOVE_UP_DOWN = 1 << 1,		// ���� �̵� (0010)
        MOVE_CIRCULAR = 1 << 2,		// ���� �̵� (0100)
        //MOVE_PARABOLIC = 1 << 3,	// ������ �̵� (1000)
        // �̵� �߰�
    };
    enum class E_Move_Role
    {
        PATH,                       // �߽����� �����̴� ����
        OFFSET                      // �߽������κ����� �������� ����ϴ� ����
    };

    class BaseMovement : public ScriptBehaviour
    {
    protected:
        float m_moveSpeed = 10.0f;
        E_Move_Role m_role = E_Move_Role::PATH;

        // ���� ����
        bool m_isLoop = true;
        int m_flipDirection = 1;    // ���� (1: ������, -1: ������)
        float m_minBounds = 0.0f;   // �ּ� ���
        float m_maxBounds = 0.0f;   // �ִ� ���

    public:
    BaseMovement()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
    }
   
        virtual void Awake() {}
        virtual void Initialize() {}
        virtual Vector2 Move(float deltaTime) = 0;

        void SetLoopMode(float min, float max)
        {
            m_isLoop = true;
            m_minBounds = min;
            m_maxBounds = max;
        }

        virtual void FlipDirection()
        {
            m_flipDirection *= -1;
        }

        int GetDirection() const { return m_flipDirection; }
        bool IsLoop() const { return m_isLoop; }

        E_Move_Role GetRole() const { return m_role; }
    };
}