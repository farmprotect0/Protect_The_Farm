#include "SoundManager.h"

using namespace GOTOEngine;
SoundManager* SoundManager::instance = nullptr;

void SoundManager::Awake() {
	if (!instance)
	{
		instance = this;
	}
	else
	{
		Destroy(GetGameObject());
	}
	//경로 지정 및 리스트에 추가
	
}

void SoundManager::OnDestroy() {
	if (instance == this)
		instance = nullptr;
}

float SoundManager::GetsfxVolume() {
	return sfxVolume;
}

float SoundManager::GetbgmVolume() {
	return bgmVolume;
}

void SoundManager::SetSFXVolume(float volume) {
	sfxVolume = volume;
}
void SoundManager::SetBGMVolume(float volume) {
	bgmVolume = volume;
}

void SoundManager::PlaySFX(const std::string& key) {
	//sfx볼륨크기로 key에 따라 sfx 재생
};

void SoundManager::PlayBGM(const std::string& key) {
	//bgm볼륨크기로 key에 따라 bgm 재생
};