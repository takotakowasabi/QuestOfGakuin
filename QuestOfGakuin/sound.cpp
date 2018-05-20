#include "define.h"

void Sound_c::load()
{
	quest = LoadSoundMem("quest.mp3");
}

void Sound_c::Play_quest()
{
	SetLoopPosSoundMem(0, quest);
	PlaySoundMem(quest, DX_PLAYTYPE_LOOP);
}

void Sound_c::Stop()
{
	StopSoundMem(quest);
}

