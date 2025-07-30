#pragma once
#include <ScriptBehaviour.h>
#include <InputManager.h>
#include <Transform.h>
#include <TimeManager.h>
#include <Camera.h>

namespace GOTOEngine
{
	class CrosshairMove : public ScriptBehaviour
	{
	private:
	public:
    CrosshairMove()
    {
        REGISTER_BEHAVIOUR_MESSAGE(Update);
    }
		float moveSpeed = 340.0f;
		int id = 0;
		Rect clampRect = { 0, 0, 1.0f, 1.0f }; // 화면의 크기에 맞춰 조정

		float timeSpeed = 1.0f;

		void Update()
		{
			float hInput, vInput;

			hInput = 0;
			vInput = 0;
			
			if (id == 0)
			{
				hInput = (INPUT_GET_KEY(KeyCode::RightArrow) ? 1.0f : 0.0f) + (INPUT_GET_KEY(KeyCode::LeftArrow) ? -1.0f : 0.0f);
				vInput = (INPUT_GET_KEY(KeyCode::UpArrow) ? 1.0f : 0.0f) + (INPUT_GET_KEY(KeyCode::DownArrow) ? -1.0f : 0.0f);
			}
			else
			{
				hInput = (INPUT_GET_KEY(KeyCode::D) ? 1.0f : 0.0f) + (INPUT_GET_KEY(KeyCode::A) ? -1.0f : 0.0f);
				vInput = (INPUT_GET_KEY(KeyCode::W) ? 1.0f : 0.0f) + (INPUT_GET_KEY(KeyCode::S) ? -1.0f : 0.0f);
			}

			if (INPUT_GAMEPAD_IS_CONNECTED(id))
			{
				hInput += INPUT_GET_GAMEPAD_AXIS(id, GamepadAxis::LeftStickX);
				vInput += INPUT_GET_GAMEPAD_AXIS(id, GamepadAxis::LeftStickY);
			}

			if (id == 0)
			{
				auto targetTimeSpeed = 1.0f;
				auto targetMoveSpeed = 340.0f;
				if (INPUT_GET_KEY(KeyCode::Space))
				{
					targetTimeSpeed = 0.25f;
					targetMoveSpeed = 340.0f * 4.0f;
				}
				timeSpeed = Mathf::Lerp(timeSpeed, targetTimeSpeed, 6.0f * TIME_GET_DELTATIME());
				moveSpeed = Mathf::Lerp(moveSpeed, targetMoveSpeed, 6.0f * TIME_GET_DELTATIME());

				TimeManager::Get()->SetTimeScale(timeSpeed);
			}

			auto moveInput = Vector2::ClampMagnitude(Vector2{ hInput, vInput }, 1.0f);
			GetTransform()->SetPosition(GetTransform()->GetPosition() + (moveInput.Normalized() * moveInput.Magnitude() * moveSpeed * TIME_GET_DELTATIME()));

			auto posMin = Camera::GetMainCamera()->ViewportToWorldPoint({ 0,0 });
			auto posMax = Camera::GetMainCamera()->ViewportToWorldPoint({ 1.0f, 1.0f });

			auto currentPos = GetTransform()->GetPosition();

			GetTransform()->SetPosition({ Mathf::Clamp(currentPos.x,posMin.x,posMax.x), Mathf::Clamp(currentPos.y,posMin.y,posMax.y) });
		}
	};
}