#pragma once
#include "Singleton.h"
#include <Windows.h>
#include <chrono>

namespace GOTOEngine 
{
	class TimeManager : public Singleton<TimeManager>
	{
	public:
		TimeManager() = default;
		~TimeManager() = default;
		
		float GetDeltaTime() const;
		float GetFixedDeltaTime() const { return m_fixedDeltaTime; }
		float GetTime() const;
		float GetFixedTime() const { return m_fixedTime; }
		float GetUnscaledTime() const { return m_unscaledTotalTime; }
		float GetUnscaledDeltaTime() const { return m_unscaledDeltaTime; }
		float GetTimeScale() const { return m_timeScale; }
		float GetMaximumAllowedTimestep() const { return m_maximumAllowedTimestep; }
		std::uint32_t GetFrameCount() const { return m_frameCount; }

		void SetTimeScale(float value) { m_timeScale = value; }
		void SetFixedDeltaTime(float value) { m_fixedDeltaTime = value; }
		void SetMaximumAllowedTimestep(float value) { m_maximumAllowedTimestep = value; }
	private:
		friend class Engine;

		enum class ExcutionContext
		{
			Normal, // 일반 업데이트
			Fixed  // 고정 업데이트
		};
		
		ExcutionContext m_executionContext = ExcutionContext::Normal;

		void SetExecutionContext(ExcutionContext context) {	m_executionContext = context; }

		std::chrono::high_resolution_clock::time_point m_initTime;
		std::chrono::high_resolution_clock::time_point m_prevTime;
		std::chrono::high_resolution_clock::time_point m_currentTime;
		std::chrono::high_resolution_clock::duration m_deltaDuration;
		std::chrono::high_resolution_clock::duration m_totalDuration;

		float m_deltaTime = 0;
		float m_fixedDeltaTime = 0.03125f;
		float m_totalTime = 0;
		float m_fixedTime = 0;
		float m_maximumAllowedTimestep = 0.2f;
		float m_timeScale = 1.0f;
		float m_unscaledDeltaTime = 0;
		float m_unscaledTotalTime = 0;
		std::uint32_t m_frameCount = 0;

		void StartUp();
		void Shutdown();
		void Update();
		void FixedUpdate();
	};

}

#define TIME_GET_DELTATIME GOTOEngine::TimeManager::Get()->GetDeltaTime
#define TIME_GET_TOTALTIME GOTOEngine::TimeManager::Get()->GetTime
#define TIME_GET_FIXED_DELTATIME GOTOEngine::TimeManager::Get()->GetFixedDeltaTime 
#define TIME_GET_UNSCALED_DELTATIME GOTOEngine::TimeManager::Get()->GetUnscaledDeltaTime
#define TIME_GET_UNSCALED_TOTALTIME GOTOEngine::TimeManager::Get()->GetUnscaledTime
#define TIME_GET_TIMESCALE GOTOEngine::TimeManager::Get()->SetTimeScale
#define TIME_SET_TIMESCALE GOTOEngine::TimeManager::Get()->GetTimeScale
#define TIME_GET_FRAMECOUNT GOTOEngine::TimeManager::Get()->GetFrameCount