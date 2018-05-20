#include "define.h"

void Room_c::Lorad_order() //Excelファイルから壁のデータを読み取る
{
	int n, num, i, fp;
	char fname[64];
	sprintf_s(fname, "%d.csv", Event.GetStage());
	int input[128];
	char inputc[128];

	fp = FileRead_open(fname);//ファイル読み込み
	if (fp == NULL) {
		printfDx("read error\n");
		return;
	}
	for (i = 0; i < 1; i++)//最初の2行読み飛ばす
		while (FileRead_getc(fp) != '\n');

	n = 0, num = 0;
	while (1) {
		for (i = 0; i<128; i++) {
			inputc[i] = input[i] = FileRead_getc(fp);//1文字取得する
			if (inputc[i] == '/') {//スラッシュがあれば
				while (FileRead_getc(fp) != '\n');//改行までループ
				i = -1;//カウンタを最初に戻して
				continue;
			}
			if (input[i] == ',' || input[i] == '\n') {//カンマか改行なら
				inputc[i] = '\0';//そこまでを文字列とし
				break;
			}
			if (input[i] == EOF) {//ファイルの終わりなら
				goto EXFILE;//終了
			}
		}
		switch (num) {
		case 0: SetNwall(n / 9, n % 9, atoi(inputc)); break;
		case 1: SetEwall(n / 9, n % 9, atoi(inputc)); break;
		case 2: SetSwall(n / 9, n % 9, atoi(inputc)); break;
		case 3: SetWwall(n / 9, n % 9, atoi(inputc)); break;
		}
		num++;
		if (num == 4) {
			num = 0;
			n++;
		}
	}
EXFILE:
	FileRead_close(fp);
}

int Room_c::GetNwall(int i, int j)
{
	return room[i][j].Nwall;
}

int Room_c::GetEwall(int i, int j)
{
	return room[i][j].Ewall;
}

int Room_c::GetSwall(int i, int j)
{
	return room[i][j].Swall;
}

int Room_c::GetWwall(int i, int j)
{
	return room[i][j].Wwall;
}

void Room_c::SetNwall(int i, int j, int k)
{
	room[i][j].Nwall = k;
}

void Room_c::SetEwall(int i, int j, int k)
{
	room[i][j].Ewall = k;
}

void Room_c::SetSwall(int i, int j, int k)
{
	room[i][j].Swall = k;
}

void Room_c::SetWwall(int i, int j, int k)
{
	room[i][j].Wwall = k;
}
