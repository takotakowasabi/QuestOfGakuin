#include"define.h"

void Control_c::All() {
	switch (mode) {
	case startmenu:
		Back.load();
		Back.Draw_start();
		if (CheckHitKey(KEY_INPUT_Z) == 1) {
/*			Player.Initialize();
			Enemy.Initialize();
			Back.Load();
			Enemy.Load();
			Enemy.Load_order(1);//ステージ1を読み込む
			Control.g_count *= 0;
			Player.BarClear();*/
			scene = story;
			mode = game;
		}
		if (CheckHitKey(KEY_INPUT_X) == 1) {
			DxLib_End();
			exit(1);
		}
		break;
	case game:
		switch (scene) {
		case story:
			Back.Draw_story();
			if (CheckHitKey(KEY_INPUT_B) == 1) {
				scene = quest;
				Player.start();
				Sound.load();
				Sound.Play_quest();
			}
			break;
		case quest:

			Back.Draw_quest();
			Back.Draw_ui();
			Player.Mark();
			Wall.Draw();
			Back.speak();
			DrawFormatString(524, 340, GetColor(255, 255, 255), "%d階なう", Event.GetStage()+1);
					
			if (event == 1) {
				int kg;
				kg = LoadGraph("key.png");
				DrawGraph(0, 0, kg, TRUE);
				DrawString(400, 160, "鍵を手に", GetColor(255, 255, 255));
				DrawString(410, 210, "入れた！", GetColor(255, 255, 255));

				if (waitevent == 0) waitevent = 1;
				else {
					while (ProcessMessage() == 0 && CheckHitKeyAll() != 0) {}
					while (ProcessMessage() == 0 && CheckHitKeyAll() == 0) {}

					if (CheckHitKey(KEY_INPUT_Z) != 0) {
						event = 0;
						waitevent = 0;
					}
				}
			}
			else if (event == 2) {
				int gg;
				gg = LoadGraph("goal.png");
				DrawGraph(0, 0, gg, TRUE);
				DrawString(400, 160, "扉が開き", GetColor(255, 255, 255));
				DrawString(410, 210, "階段が現れた！", GetColor(255, 255, 255));

				if (waitevent == 0) waitevent = 1;
				else {
					while (ProcessMessage() == 0 && CheckHitKeyAll() != 0) {}
					while (ProcessMessage() == 0 && CheckHitKeyAll() == 0) {}

					if (CheckHitKey(KEY_INPUT_Z) != 0) {
						event = 0;
						waitevent = 0;
						Event.Next();
					}
				}
			}
			else if (waitkey == TRUE) {
				// キー入力待ち
				while (ProcessMessage() == 0 && CheckHitKeyAll() != 0) {}
				while (ProcessMessage() == 0 && CheckHitKeyAll() == 0) {}

				// キー入力に応じて処理 

				// プレーヤー移動
				if (CheckHitKey(KEY_INPUT_UP) != 0) Player.Move();
				if (CheckHitKey(KEY_INPUT_DOWN) != 0) Player.Down();
				if (CheckHitKey(KEY_INPUT_LEFT) != 0) Player.TurnL();
				if (CheckHitKey(KEY_INPUT_RIGHT) != 0) Player.TurnR();
				if (CheckHitKey(KEY_INPUT_T) != 0) {
					Event.Key();
					Event.Goal();
				}
				if (Control.g_count == 600) {
					mode = gameclear;
				}
				if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
					mode = pause;
				}

				waitkey = FALSE;
			}
			else {
				waitkey = TRUE;
			}

			Player.check();

			/*clsDx();
			printfDx("%d, %d, %d, %d\n",Player.GetX(), Player.GetY(), Player.GetDir(), Wall.GetDir());
			printfDx("%d, %d, %d, %d, %d, %d\n", Wall.GetWall(0), Wall.GetWall(1), Wall.GetWall(2), Wall.GetWall(3), Wall.GetWall(4), Wall.GetWall(5));
			printfDx("%d, %d, %d, %d\n", Room.GetNwall(Player.GetX(), Player.GetY()), Room.GetEwall(Player.GetX(), Player.GetY()), Room.GetSwall(Player.GetX(), Player.GetY()), Room.GetWwall(Player.GetX(), Player.GetY()));
			*/
			break;
		}
		break;
	case pause:
		//		pause_back = LoadGraph("pause.png");
		//		DrawGraph(0, 0, pause_back, TRUE);
		DrawString(250, 200, "press C to back game", GetColor(255, 255, 255));
		DrawString(250, 250, "ゲーム続きから", GetColor(255, 255, 255));
		DrawString(250, 300, "press SPACE to back startmenu", GetColor(255, 255, 255));
		DrawString(250, 350, "ゲームは最初からになります", GetColor(255, 255, 255));
		if (CheckHitKey(KEY_INPUT_SPACE) == 1) {

			mode = startmenu;
		}
		if (CheckHitKey(KEY_INPUT_C) == 1) {
			mode = game;
		}
		break;
	case gameover:
		//		Back.DrawStage();
		//		Back.DrawContinue();
		if (CheckHitKey(KEY_INPUT_V) == 1) {
			Sound.Stop();
			mode = startmenu;
		}
		break;
	case gameclear:
		Back.Draw_gameclear();
		if (CheckHitKey(KEY_INPUT_V) == 1) {
			mode = startmenu;
		}
		break;
	}
}

void Control_c::Clear()
{
	mode = gameclear;
}

void Control_c::SetEvent(int i)
{
	event = i;
}
