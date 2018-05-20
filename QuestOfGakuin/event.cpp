#include "define.h"

void Event_c::SetStage(int i)
{
	stage = i;
}

int Event_c::GetStage()
{
	return stage;
}

void Event_c::Key()
{
	key = TRUE;
	Control.SetEvent(1);
	Back.SetSpeak(5);
}

void Event_c::Goal()
{
	if (key == FALSE) {
		Back.SetSpeak(6);
	}
	if (key == TRUE) {
		Control.SetEvent(2);
	}
}

void Event_c::Next()
{
	stage++;
	Player.start();
	Back.SetSpeak(7);
}

void Event_c::End()
{
	Control.Clear();
}

bool Event_c::GetKey()
{
	return key;
}

void Event_c::ResetKey()
{
	key = FALSE;
}
