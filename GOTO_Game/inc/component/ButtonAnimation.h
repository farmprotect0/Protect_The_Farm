#pragma once
#include <ScriptBehaviour.h>
#include <TimeManager.h>
#include <Delegate.h>
#include <Transform.h>

namespace GOTOEngine
{
	class ButtonAnimation : public ScriptBehaviour
	{
	private:
		float m_angularVelocity = 0.0f;   // ��: ���ӵ�
		float m_angle = 0.0f;

		float m_scale = 1.0f;            // ���� �� (��: ������)
		float m_scaleVelocity = 0.0f;         // ���� �ӵ�
	public:
    ButtonAnimation()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }
		float torqueStrength = 200.0f;    // ������ ����
		float damping = 3.0f;           // ����
		float inertia = 0.16f;            // ���� (���� ����)

		float target = 1.0f;     // ��ǥ �� (���� ũ��)
		float strength = 500.0f;  // ������ ���� (k)
		float scaleDamping = 8.0f;    // ���� ��� (d)

		void ApplyTorque(float torque)
		{
			m_angularVelocity += torque / inertia;
		}

		void PlayRotateAnimation()
		{
			ApplyTorque(20.0f);
		}

		void PlayScaleAnimaiton()
		{
			ApplyScaleForce(2.0f);
		}

		void ApplyScaleForce(float force)
		{
			m_scaleVelocity += force;
		}

		void Update()
		{
			float dt = TIME_GET_DELTATIME();

			// ������ �� ��� (��ũ ��Ģ)
			float torque = -torqueStrength * m_angle - damping * m_angularVelocity;

			// ���ӵ��� ���� ������Ʈ
			m_angularVelocity += torque / inertia * dt;
			m_angle += m_angularVelocity * dt;

			// ������ ź�� ������Ʈ
			float force = -strength * (m_scale - target) - scaleDamping * m_scaleVelocity;
			float accel = force; // ���� m = 1 ����
			m_scaleVelocity += accel * dt;
			m_scale += m_scaleVelocity * dt;

			// ���� ȸ���� ����
			GetTransform()->SetLocalRotation(m_angle);
			GetTransform()->SetLocalScale(Vector2(m_scale, m_scale));
		}
	};
}