#pragma once

class Event_c {
private:
	bool key;
	int stage = 0;
public:
	void SetStage(int i);
	int GetStage();
	void Key();
	void Goal();
	void Next();
	void End();
	bool GetKey();
	void ResetKey();
};

extern Event_c Event;
