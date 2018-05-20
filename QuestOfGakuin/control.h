#pragma once

class Control_c {
private:
	int mode = 0;
	int scene = 0;
	int menu_back;
	int pause_back;
	int prologue;
	int a, b;
	bool waitkey = FALSE;
	int event = 0;
	int waitevent = 0;
public:
	int g_count = 0;//ゲームが始まってからの時間を示す変数(背景の描画や敵の出現や弾幕張るタイミングの制御などに使う)
	int score = 0;
	void All();
	void Clear();
	void SetEvent(int i);
};

typedef enum {
	startmenu,
	game,
	pause,
	gameover,
	gameclear,
}mode;

typedef enum {
	story,
	quest,
}scene;

extern Control_c Control;