#pragma once

#include <memory>

#include "../IScene.h"
#include "Object/ObjectList.h"
#include "Command/InputHandler.h"

class TitleScene : public IScene
{
private:

	std::unique_ptr<InputHandler> inputHandler_;
	ICommand* command_ = nullptr;
	std::unique_ptr<Player> player_;


public:

	~TitleScene() override;

	void Initialize() override;
	void Update() override;
	void Draw() override;

	
};