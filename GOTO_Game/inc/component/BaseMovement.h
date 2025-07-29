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
        MOVE_PARABOLIC = 1 << 3,	// ������ �̵� (1000)
        // �̵� �߰�
    };

    class BaseMovement : public ScriptBehaviour
    {
    public:
    BaseMovement()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Awake);
    }
   
        virtual void Awake() {}
        virtual void Initialize() {}
        virtual Vector2 Move(float deltaTime) = 0;

    protected:
        float m_moveSpeed = 10.0f;
    };
}