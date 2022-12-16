#include "KeyMgr.h"
#include "Image.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Core.h"
#include "Puzzle.h"

Vec2 currentVec2;
Vec2 vec2;

Puzzle::Puzzle(int x, int y)
{
	vec2 = { x, y };
	currentVec2 = vec2;
}
void Puzzle::Update()
{
	check = CheckComplete();
}
void Puzzle::Move()
{
}
void Puzzle::CreatePuzzle(int x, int y)
{
	//Vec2 vPuzzlePos = GetPos();
	//vPuzzlePos.y -= GetScale().y / 2.f;
	currentVec2 = { x, y };

	Puzzle* pPuzzle = new Puzzle;
	pPuzzle->SetName(L"SlidePuzzle");
	pPuzzle->SetPos(vPuzzlePos);
	pPuzzle->SetScale(Vec2(150.f, 150.f));
	CreateObject(pPuzzle, GROUP_TYPE::SLIDEPUZZLE);
}

bool Puzzle::CheckComplete() { return ((currentVec2.x == vec2.x) && (currentVec2.y == vec2.y)); }
