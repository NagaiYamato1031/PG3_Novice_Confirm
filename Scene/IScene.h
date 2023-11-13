#pragma once

#include "./InputManager/InputManager.h"
#include <Novice.h>

enum SCENE 
{
	TITLE,
	STAGE,
	CLEAR,
};

class IScene {
protected:
	static int sSceneNo_;

	InputManager* input_ = nullptr;

	public:
		virtual ~IScene();

		virtual void Initialize() = 0;
	    virtual void Update() = 0;
	    virtual void Draw() = 0;


		int GetSceneNo();
};