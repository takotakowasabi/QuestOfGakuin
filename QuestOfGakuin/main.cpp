#include "define.h"//�}�N���Ƃ����C�u�����Ƃ��S���܂Ƃ߂Ă���t�@�C�����C���N���[�h���Ă܂�

Control_c Control;
Player_c Player;
Room_c Room;
Wall_c Wall;
Back_c Back;
Event_c Event;
Sound_c Sound;

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(true);//�E�B���h�E���[�h�ŕ`��
	SetGraphMode(WINDOW_X, WINDOW_Y, WINDOW_COLOR_BIT);	// ��ʂ̑傫����ς���(640*480��32bit)
	if (DxLib_Init() == -1) {
		return -1;
	}// DX���C�u����������������,�G���[���N������I��
	SetDrawScreen(DX_SCREEN_BACK);						// ����ʂɕ`�悷�邱�Ƃ�����
	
														//-----�Q�[���̏����������܂�-----//

	while (ScreenFlip() == 0							// ����ʂ�\��ʂɔ��f
		&& ProcessMessage() == 0						// ���b�Z�[�W����
		&& ClearDrawScreen() == 0)					// ��ʂ��N���A����			
	{
		//-----���C�����[�v��������-----//

		Control.All();

		//-----���C�����[�v�����܂�-----//
	}

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}