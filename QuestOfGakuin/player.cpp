#include "define.h"

void Player_c::start()
{
	Room.Lorad_order();
	Event.ResetKey();
	rand = GetRand(3);
	switch (rand) {
	case 0: x = 0;
		y = 0;
		dir = 0;
		Gx = 8;
		Gy = 8;
		Kx = 0;
		Ky = 8;
		Room.SetNwall(8, 8, 2);
		Room.SetWwall(0, 8, 3);
		break;
	case 1: x = 0;
		y = 8;
		dir = 0;
		Gx = 8;
		Gy = 0;
		Kx = 8;
		Ky = 8;
		Room.SetEwall(8, 0, 2);
		Room.SetNwall(8, 8, 3);
		break;
	case 2: x = 8;
		y = 8;
		dir = 0;
		Gx = 0;
		Gy = 0;
		Kx = 8;
		Ky = 0;
		Room.SetSwall(0, 0, 2);
		Room.SetEwall(8, 0, 3);
		break;
	case 3: x = 8;
		y = 0;
		dir = 0;
		Gx = 0;
		Gy = 8;
		Kx = 0;
		Ky = 0;
		Room.SetWwall(0, 8, 2);
		Room.SetSwall(0, 0, 3);
		break;
	}
}

void Player_c::check()
{
	if (x == Gx && y == Gy && Event.GetStage() < 4) {
		Event.Goal();
	}
	else if (x == Gx && y == Gy) {
		Event.End();
	}
	if (x == Kx && y == Ky && Event.GetKey() == 0){
		Event.Key();
	}
}

int Player_c::GetX()
{
	return x;
}

int Player_c::GetY()
{
	return y;
}

int Player_c::GetDir()
{
	return dir;
}

void Player_c::SetX(int i)
{
	x = i;
}

void Player_c::SetY(int i)
{
	y = i;
}

void Player_c::SetDir(int i)
{
	dir = i;
}

void Player_c::Mark()
{
	if (Dx != 0) tanx = (double)(Gy - y) / (Gx - x) ;
	else tanx = 2;

	if (tanx > sqrt(3.0) || tanx < -sqrt(3.0)) {
		if (Dx > 0) m = 0;
		else m = 4;
	}
	if (tanx > 1 / sqrt(3.0) && tanx < sqrt(3.0)) {
		if (Dx > 0) m = 1;
		else m = 5;
	}
	if (tanx > -1 / sqrt(3.0) && tanx < 1 / sqrt(3.0)) {
		if (Dy > 0) m = 2;
		else m = 6;
	}
	if (tanx > -sqrt(3.0) && tanx < -1 / sqrt(3.0)) {
		if (Dy > 0) m = 3;
		else m = 7;
	}

	m = (m + (8 - 2 * dir)) % 8;
	Back.Draw_mark(m);
}

void Player_c::Move()
{
	if (Wall.GetWall(2) == FALSE) {
		switch (dir) {
		case 0: y = y + 1; break;
		case 1: x = x + 1; break;
		case 2: y = y - 1; break;
		case 3: x = x - 1; break;
		}
	}
}

void Player_c::Down()
{
	switch (dir) {
	case 0: if (Room.GetSwall(x, y) == 0) {
		y--;
	}
			break;
	case 1: if (Room.GetWwall(x, y) == 0) {
		x--;
	}
			break;
	case 2: if (Room.GetNwall(x, y) == 0) {
		y++;
	}
			break;
	case 3: if (Room.GetEwall(x, y) == 0) {
		x++;
	}
			break;
	}
}

void Player_c::TurnL()
{
	dir = (dir + 3) % 4;
}

void Player_c::TurnR()
{
	dir = (dir + 1) % 4;
}
