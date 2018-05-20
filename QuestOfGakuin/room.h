#pragma once

class Room_c {
private:
	struct room_t {
		int Nwall, Ewall, Swall, Wwall;
		int x, y;
	};
	room_t room[ROOM_MAX_X][ROOM_MAX_Y];
public:
	void Lorad_order();
	int GetNwall(int i, int j);
	int GetEwall(int i, int j);
	int GetSwall(int i, int j);
	int GetWwall(int i, int j);
	void SetNwall(int i, int j, int k);
	void SetEwall(int i, int j, int k);
	void SetSwall(int i, int j, int k);
	void SetWwall(int i, int j, int k);
};

extern Room_c Room;
