#include <Novice.h>

#include "./Scene/SceneManager.h"

const char kWindowTitle[] = "LE2A_15_ナガイ_ヤマト";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	SceneManager* sceneManager_ = new SceneManager;

	sceneManager_->Run();

	delete sceneManager_;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
