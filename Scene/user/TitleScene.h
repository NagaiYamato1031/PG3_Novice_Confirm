#pragma once

#include "../IScene.h"

class TitleScene : public IScene
{
private:




public:

	~TitleScene() override;

	void Initialize() override;
	void Update() override;
	void Draw() override;

	
};