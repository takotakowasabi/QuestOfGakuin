#pragma once

class Back_c {
private:
	int ui_back;
	int ui_N;
	int ui_E;
	int ui_S;
	int ui_W;
	int ui_face;
	int start;
	int story;
	int pause;
	int quest_ceil;
	int quest_floor;
	int quest_next;
	int gameover;
	int gameclear;
	int Cr;
	int speak_count = 0;
	int speak_rand = 0;
	int d[8];
public:
	void SetSpeak(int i);
	void speak();
	void load();
	void Draw_ui();
	void Draw_mark(int i);
	void Draw_start();
	void Draw_story();
	void Draw_pause();
	void Draw_quest();
	void Draw_gameoer();
	void Draw_gameclear();
};

extern Back_c Back;