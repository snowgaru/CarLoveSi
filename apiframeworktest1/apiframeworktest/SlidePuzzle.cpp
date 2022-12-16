#include "SlidePuzzle.h"
#include "Puzzle.h"
#include "pch.h"
#include "Core.h"

#define MAXPUZZLECOUNT 16

vector<Puzzle> v;
void StartPuzzle()
{
	CreatePiece();
}

void CreatePiece()
{
	for (int i = 1; i <= MAXPUZZLECOUNT; i++)
	{
		Puzzle newPuzzle = Puzzle();
		newPuzzle.CreatePuzzle((i + 2) / 4, i % 4);
		v.push_back(newPuzzle);
	}
}

void ShufflePuzzle()
{
	srand((unsigned int)time(NULL));
	Vec2 emptyPlace = { 4,4 };
	for (int i = 0; i < 50; i++)
	{
		if (emptyPlace.x == 4)
		{
			emptyPlace.x -= rand() % 2;
		}
		else if (emptyPlace.x == 1)
		{
			emptyPlace.x += rand() % 2;
		}
	}
}

void SlidePiece()
{

}

bool CheckComplete()
{
	return false;
}

void CompletePuzzle()
{

}

void FailedPuzzle()
{

}