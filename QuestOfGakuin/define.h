#pragma once
/*マクロやヘッダーファイルを全てまとめてあるファイルです
(基本的にはこれにヘッダーを追加してこれをインクルードすればいいです)*/

#pragma once
#define _USE_MATH_DEFINES

//画面の大きさ
#define WINDOW_X 640			//ウィンドウサイズ横(pixel)
#define WINDOW_Y 480			//ウィンドウサイズ縦(pixel)
#define WINDOW_COLOR_BIT 32		//画面色深度(bit)

#define ROOM_MAX_X 10			//X方向の部屋の最大数
#define ROOM_MAX_Y 10			//Y方向の部屋の最大数

#include "DxLib.h"
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "control.h"
#include "back.h"
#include "wall.h"
#include "room.h"
#include "player.h"
#include "event.h"
#include "sound.h"