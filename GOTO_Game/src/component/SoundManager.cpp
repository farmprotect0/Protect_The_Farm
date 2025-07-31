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
	//��� ���� �� ����Ʈ�� �߰�
	
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
	//sfx����ũ��� key�� ���� sfx ���
};

void SoundManager::PlayBGM(const std::string& key) {
	//bgm����ũ��� key�� ���� bgm ���
};