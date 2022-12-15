#include "SlidePuzzle.h"
#include "Puzzle.h"
#include "pch.h"
#include "Core.h"

#define MAXPUZZLECOUNT 16

Puzzle puzzlePiece[];
void StartPuzzle()
{
	CreatePiece();
}

void CreatePiece()
{
	for (int i = 0; i < MAXPUZZLECOUNT; i++)
	{
		Puzzle newPuzzle = Puzzle();
	}
}

void ShufflePuzzle()
{

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