#pragma once
#include "Object.h"
#include "pch.h"

class Puzzle : public Object
{
private:
	CLONE(Puzzle);
public:
	Puzzle();
	Puzzle(int x, int y);
	~Puzzle();
	bool check;
	// Object��(��) ���� ��ӵ�
	virtual void Update() override;
	void CreatePuzzle(int x, int y);  
	void Move();
	bool CheckComplete();
};