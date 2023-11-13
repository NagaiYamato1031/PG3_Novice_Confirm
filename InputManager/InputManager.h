#pragma once

class InputManager final {
private:
	char keys_[256];
	char preKeys_[256];

public:
	static InputManager* GetInstance();

public:

	void Update();

	bool PressKey(int keyCode);
	bool TrrigerKey(int keyCode);
	bool ReleaseKey(int keyCode);

private:

	InputManager() = default;
	~InputManager() = default;
	InputManager(const InputManager& obj) = delete;
	const InputManager& operator=(const InputManager& obj) = delete;

};