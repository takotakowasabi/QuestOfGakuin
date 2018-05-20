#include "define.h"//マクロとかライブラリとか全部まとめてあるファイルをインクルードしてます

Control_c Control;
Player_c Player;
Room_c Room;
Wall_c Wall;
Back_c Back;
Event_c Event;
Sound_c Sound;

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);//ウィンドウモードで描画
	SetGraphMode(WINDOW_X, WINDOW_Y, WINDOW_COLOR_BIT);	// 画面の大きさを変える(640*480の32bit)
	if (DxLib_Init() == -1) {
		return -1;
	}// DXライブラリを初期化処理,エラーが起きたら終了
	SetDrawScreen(DX_SCREEN_BACK);						// 裏画面に描画することを決定
	
														//-----ゲームの初期化ここまで-----//

	while (ScreenFlip() == 0							// 裏画面を表画面に反映
		&& ProcessMessage() == 0						// メッセージ処理
		&& ClearDrawScreen() == 0)					// 画面をクリアする			
	{
		//-----メインループここから-----//

		Control.All();

		//-----メインループここまで-----//
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}