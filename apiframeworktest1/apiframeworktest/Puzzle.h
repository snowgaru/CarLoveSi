#pragma once
#include "Vec2.h"
class Puzzle {
private:
	Vec2 vec;
	bool isComplete = false;
public:
	void SetVector(int x, int y)
	{
		vec.x = x;
		vec.y = y;
	}
	void SetBool(bool value)
	{
		isComplete = false;
	}
	bool ReturnIsComplete() { return isComplete; }
};