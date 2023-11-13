#include "InputManager.h"

#include "Novice.h"

InputManager* InputManager::GetInstance() {
	static InputManager instance;
	return &instance;
}

void InputManager::Update() {
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);
}

bool InputManager::PressKey(int keyCode) {
	if (keys_[keyCode]) {
		return true;
	}
	return false;
}

bool InputManager::TrrigerKey(int keyCode) {
	if (!preKeys_[keyCode] && keys_[keyCode]) {
		return true;
	}
	return false;
}

bool InputManager::ReleaseKey(int keyCode) {
	if (preKeys_[keyCode] && !keys_[keyCode]) {
		return true;
	}
	return false;
}