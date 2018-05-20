#pragma once

class Sound_c {
private:
	int quest;
public:
	void load();
	void Play_quest();
	void Stop();
};

extern Sound_c Sound;