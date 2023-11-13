#include "IScene.h"

int IScene::sSceneNo_ = TITLE;


IScene::~IScene() {}

int IScene::GetSceneNo() { return sSceneNo_; }
