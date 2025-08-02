#pragma once
#include <AnimationCurve.h>

namespace GOTOEngine
{
	struct RumbleAnimationClip
	{
		AnimationCurve rightMotorCurve;
		AnimationCurve leftMotorCurve;
		float length = 1.0f; 

		RumbleAnimationClip(const AnimationCurve& right, const AnimationCurve& left, float length)
		: rightMotorCurve(right)
		, leftMotorCurve(left)
		, length(length)
		{
		}
	};
}