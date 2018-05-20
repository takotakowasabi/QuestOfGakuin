#pragma once

class Wall_c {
private:
	int dir;
	int x, y;
	int wall[9];
public:
	int GetDir();
	void Draw();
	bool GetWall(int i);
	void SetWall(int i, bool k);
};

extern Wall_c Wall;