#pragma once

class Player_c {
private:
	int x;
	int y;
	int dir;
	int rand;
	int Dx, Dy, m;
	double tanx;
	int Gx, Gy;
	int Kx, Ky;
public:
	void start();
	void check();
	int GetX();
	int GetY();
	int GetDir();
	void SetX(int i);
	void SetY(int i);
	void SetDir(int i);
	void Mark();
	void Move();
	void Down();
	void TurnL();
	void TurnR();
};

extern Player_c Player;