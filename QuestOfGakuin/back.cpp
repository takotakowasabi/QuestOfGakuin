#include "define.h"

void Back_c::SetSpeak(int i)
{
	speak_rand = i;
}

void Back_c::speak()
{
	speak_count++;
	if (speak_count == 10) {
		speak_rand = GetRand(4);
		speak_count = 0;
	}
	Cr = GetColor(255, 255, 255);
	switch (speak_rand) {
	case 0: DrawString(200, 400, "もう帰りたい", Cr); break;
	case 1: DrawString(200, 400, "何なんだここは", Cr); break;
	case 2: DrawString(200, 400, "早くここから出ないと", Cr); break;
	case 3: DrawString(200, 400, "どこから来たんだっけ", Cr); break;
	case 4: DrawString(200, 400, "いったいここはどこなんだ", Cr); break;
	case 5: DrawString(200, 400, "鍵を見つけたから扉を探そう", Cr); break;
	case 6: DrawString(200, 400, "扉を見つけたけど鍵がない！", Cr); break;
	case 7: DrawString(200, 400, "扉で次の階まで来たぞ！", Cr); break;
	}
}

void Back_c::load()
{
	start = LoadGraph("startback.png");
	story = LoadGraph("storyback.png");
	quest_ceil = LoadGraph("ceiling.png");
	quest_floor = LoadGraph("floor.png");
	quest_next = LoadGraph("next.png");
	ui_back = LoadGraph("uiback.png");
	ui_N = LoadGraph("uinorth.png");
	ui_E = LoadGraph("uieast.png");
	ui_S = LoadGraph("uisouth.png");
	ui_W = LoadGraph("uiwest.png");
	ui_face = LoadGraph("uiface.png");
	/*	pause = LoadGraph("pause.png");
		gameover = LoadGraph("over.png");*/
	gameclear = LoadGraph("clear.png");
	d[1] = LoadGraph("d1.png");
    d[2] = LoadGraph("d2.png");
	d[3] = LoadGraph("d3.png");
	d[4] = LoadGraph("d4.png");
	d[5] = LoadGraph("d5.png");
	d[6] = LoadGraph("d6.png");
	d[7] = LoadGraph("d7.png");
	d[0] = LoadGraph("d0.png");
}

void Back_c::Draw_ui()
{
	DrawGraph(0, 0, ui_back, TRUE);
	DrawGraph(0, 0, ui_face, TRUE);
	switch (Player.GetDir()) {
	case 0: DrawGraph(0, 0, ui_N, TRUE); break;
	case 1: DrawGraph(0, 0, ui_W, TRUE); break;
	case 2: DrawGraph(0, 0, ui_S, TRUE); break;
	case 3: DrawGraph(0, 0, ui_E, TRUE); break;
	}
}

void Back_c::Draw_mark(int i)
{
	DrawGraph(0, 0, d[i], TRUE);
}

void Back_c::Draw_start()
{
	DrawGraph(0, 0, start, TRUE);
}

void Back_c::Draw_story()
{
	DrawGraph(0, 0, story, TRUE);
}

void Back_c::Draw_quest()
{
	DrawGraph(0, 0, quest_ceil, TRUE);
	DrawGraph(0, 0, quest_floor, TRUE);
	DrawGraph(0, 0, quest_next, TRUE);
}

void Back_c::Draw_gameoer()
{
}

void Back_c::Draw_gameclear()
{
	DrawGraph(0, 0, gameclear, TRUE);
}
