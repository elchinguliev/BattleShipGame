#pragma once


typedef unsigned short ushort;
enum Simvol { UP = 72, DOWN = 80, RIGHT = 77, LEFT = 75, ENTER = 13, REVERS = 113 };


struct PackageMan {

	int x = 5;
	int y = 0;

} pack;


struct Striked
{
	bool striked = false;
	bool right = false;
	bool right_Access = false;
	bool left = false;
	bool left_Access = false;
	bool up = false;
	bool up_Access = false;
	bool dowm = false;
	bool dowm_Access = false;
	int striked_x = -1;
	int striked_y = -1;

}strike;