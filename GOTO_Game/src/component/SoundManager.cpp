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
	
	
}

void SoundManager::OnDestroy() {
	if (instance == this)
		instance = nullptr;
}

void SoundManager::SetSFXVolume(float volume) {
	sfxVolume = volume;
}
void SoundManager::SetBGMVolume(float volume) {
	bgmVolume = volume;
}