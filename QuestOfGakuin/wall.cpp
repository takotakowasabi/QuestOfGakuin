#include "define.h"

int Wall_c::GetDir()
{
	return dir;
}

void Wall_c::Draw()
{
	dir = Player.GetDir();
	x = Player.GetX();
	y = Player.GetY();

	wall[0] = 0;
	wall[1] = 0;
	wall[2] = 0;
	wall[3] = 0;
	wall[4] = 0;
	wall[5] = 0;

	//•Ç‚Ì—L–³‚ðŽæ“¾
	for (int i = 0 ; i <= 8; i++) {
		for (int j = 0; j <= 8; j++) {
			if (x == i && y == j) {
				switch (dir) {
				case 0: wall[0] = Room.GetWwall(i, j);
						wall[1] = Room.GetEwall(i, j);
						wall[2] = Room.GetNwall(i, j);
						wall[3] = Room.GetWwall(i, j + 1);
						wall[4] = Room.GetEwall(i, j + 1);
						wall[5] = Room.GetNwall(i, j + 1);
						if (i - 1 >= 0) {
							wall[6] = Room.GetNwall(i - 1, j);
							wall[8] = Room.GetNwall(i - 1, j + 1);
						}
						if (i + 1 <= 8) {
							wall[7] = Room.GetNwall(i + 1, j);
							wall[9] = Room.GetNwall(i + 1, j + 1);
						}
						break;

			    case 1: wall[0] = Room.GetNwall(i, j);
						wall[1] = Room.GetSwall(i, j);
						wall[2] = Room.GetEwall(i, j);
						wall[3] = Room.GetNwall(i + 1, j);
						wall[4] = Room.GetSwall(i + 1, j);
						wall[5] = Room.GetEwall(i + 1, j);
						if (j + 1 <= 8) {
							wall[6] = Room.GetEwall(i, j + 1);
							wall[8] = Room.GetEwall(i + 1, j + 1);
						}
						if (j - 1 >= 0) {
							wall[7] = Room.GetEwall(i , j - 1);
							wall[9] = Room.GetEwall(i + 1, j - 1);
						}
						break;

				case 2: wall[0] = Room.GetEwall(i, j);
						wall[1] = Room.GetWwall(i, j);
						wall[2] = Room.GetSwall(i, j);
						wall[3] = Room.GetEwall(i, j - 1);
						wall[4] = Room.GetWwall(i, j - 1);
						wall[5] = Room.GetSwall(i, j - 1);
						if (i + 1 <= 8) {
							wall[6] = Room.GetSwall(i + 1, j);
							wall[8] = Room.GetSwall(i + 1, j - 1);
						}
						if (i - 1 >= 0) {
							wall[7] = Room.GetSwall(i - 1, j);
							wall[9] = Room.GetSwall(i - 1, j - 1);
						}
					   break;

				case 3: wall[0] = Room.GetSwall(i, j);
						wall[1] = Room.GetNwall(i, j);
						wall[2] = Room.GetWwall(i, j);
						wall[3] = Room.GetSwall(i - 1, j);
						wall[4] = Room.GetNwall(i - 1, j);
						wall[5] = Room.GetWwall(i - 1, j);
						if (j - 1 >= 0) {
							wall[6] = Room.GetWwall(i, j - 1);
							wall[8] = Room.GetWwall(i - 1, j - 1);
						}
						if (j + 1 <= 8) {
							wall[7] = Room.GetWwall(i, j + 1);
							wall[9] = Room.GetWwall(i - 1, j + 1);
						}
					   break;
				}
			}
		}
	}
	
	if (wall[5] == 1) {
		int wall5;
		wall5 = LoadGraph("wall5.png");
		DrawGraph(0, 0, wall5, TRUE);
	} else if (wall[5] == 2) {
		int wall5;
		wall5 = LoadGraph("wall5-2.png");
		DrawGraph(0, 0, wall5, TRUE);
	}
	else if (wall[5] == 3) {
		int wall5;
		wall5 = LoadGraph("wall5-3.png");
		DrawGraph(0, 0, wall5, TRUE);
	}

	if (wall[8] == 1) {
		int wall8;
		wall8 = LoadGraph("wall8.png");
		DrawGraph(0, 0, wall8, TRUE);
	} else if (wall[8] == 2) {
		int wall8;
		wall8 = LoadGraph("wall8-2.png");
		DrawGraph(0, 0, wall8, TRUE);
	} else if (wall[8] == 3) {
		int wall8;
		wall8 = LoadGraph("wall8-3.png");
		DrawGraph(0, 0, wall8, TRUE);
	}

	if (wall[9] == 1) {
		int wall9;
		wall9 = LoadGraph("wall9.png");
		DrawGraph(0, 0, wall9, TRUE);
	} else if (wall[9] == 2) {
		int wall9;
		wall9 = LoadGraph("wall9-2.png");
		DrawGraph(0, 0, wall9, TRUE);
	} else if (wall[9] == 3) {
		int wall9;
		wall9 = LoadGraph("wall9-3.png");
		DrawGraph(0, 0, wall9, TRUE);
	}

	if (wall[3] == 1) {
		int wall3;
		wall3 = LoadGraph("wall3.png");
		DrawGraph(0, 0, wall3, TRUE);
	} else if (wall[3] == 2) {
		int wall3;
		wall3 = LoadGraph("wall3-2.png");
		DrawGraph(0, 0, wall3, TRUE);
	} else if (wall[3] == 3) {
		int wall3;
		wall3 = LoadGraph("wall3-3.png");
		DrawGraph(0, 0, wall3, TRUE);
	}

	if (wall[4] == 1) {
		int wall4;
		wall4 = LoadGraph("wall4.png");
		DrawGraph(0, 0, wall4, TRUE);
	} else if (wall[4] == 2) {
		int wall4;
		wall4 = LoadGraph("wall4-2.png");
		DrawGraph(0, 0, wall4, TRUE);
	} else if (wall[4] == 3) {
		int wall4;
		wall4 = LoadGraph("wall4-3.png");
		DrawGraph(0, 0, wall4, TRUE);
	}

	if (wall[2] == 1) {
		int wall2;
		wall2 = LoadGraph("wall2.png");
		DrawGraph(0, 0, wall2, TRUE);
	} else if (wall[2] == 2) {
		int wall2;
		wall2 = LoadGraph("wall2-2.png");
		DrawGraph(0, 0, wall2, TRUE);
	} else if (wall[2] == 3) {
		int wall2;
		wall2 = LoadGraph("wall2-3.png");
		DrawGraph(0, 0, wall2, TRUE);
	}

	if (wall[6] == 1) {
		int wall6;
		wall6 = LoadGraph("wall6.png");
		DrawGraph(0, 0, wall6, TRUE);
	}

	if (wall[7] == 1) {
		int wall7;
		wall7 = LoadGraph("wall7.png");
		DrawGraph(0, 0, wall7, TRUE);
	}

	if (wall[0] == 1) {
		int wall0;
		wall0 = LoadGraph("wall0.png");
		DrawGraph(0, 0, wall0, TRUE);
	} else if (wall[0] == 2) {
		int wall0;
		wall0 = LoadGraph("wall0-2.png");
		DrawGraph(0, 0, wall0, TRUE);
	} else if (wall[0] == 3) {
		int wall0;
		wall0 = LoadGraph("wall0-3.png");
		DrawGraph(0, 0, wall0, TRUE);
	}

	if (wall[1] == 1) {
		int wall1;
		wall1 = LoadGraph("wall1.png");
		DrawGraph(0, 0, wall1, TRUE);
	} else if (wall[1] == 2) {
		int wall1;
		wall1 = LoadGraph("wall1-2.png");
		DrawGraph(0, 0, wall1, TRUE);
	} else if (wall[1] == 3) {
		int wall1;
		wall1 = LoadGraph("wall1-3.png");
		DrawGraph(0, 0, wall1, TRUE);
	}
}

bool Wall_c::GetWall(int i)
{
	return wall[i];
}

void Wall_c::SetWall(int i, bool k)
{
	wall[i] = k;
}
