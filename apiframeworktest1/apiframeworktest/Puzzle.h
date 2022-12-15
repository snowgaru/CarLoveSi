#pragma once
#include "Vec2.h"
class Puzzle {
private:
	Vec2 vec;
	Vec2 curVec;
public:
	Puzzle(int x, int y)
	{
		vec.x = x;
		vec.y = y;
		curVec = vec;
	}
	~Puzzle()
	{
		delete(this);
	}
	void SetVector(int x, int y)
	{
		curVec.x = x;
		curVec.y = y;
	}
	bool CheckComplete()
	{
		if ((curVec.x == vec.x) && (curVec.y == vec.y))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};