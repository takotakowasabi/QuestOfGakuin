#pragma once
/*�}�N����w�b�_�[�t�@�C����S�Ă܂Ƃ߂Ă���t�@�C���ł�
(��{�I�ɂ͂���Ƀw�b�_�[��ǉ����Ă�����C���N���[�h����΂����ł�)*/

#pragma once
#define _USE_MATH_DEFINES

//��ʂ̑傫��
#define WINDOW_X 640			//�E�B���h�E�T�C�Y��(pixel)
#define WINDOW_Y 480			//�E�B���h�E�T�C�Y�c(pixel)
#define WINDOW_COLOR_BIT 32		//��ʐF�[�x(bit)

#define ROOM_MAX_X 10			//X�����̕����̍ő吔
#define ROOM_MAX_Y 10			//Y�����̕����̍ő吔

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