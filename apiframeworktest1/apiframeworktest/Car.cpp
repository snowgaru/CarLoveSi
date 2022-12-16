#include "pch.h"
#include "Car.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "Image.h"
#include "PathMgr.h"
#include "ResMgr.h"
#include "FaceEnum.h"
Car::Car()
{
	defaultImage = ResMgr::GetInst()->ImgLoad(L"default", L"Image\\Car1_Default.bmp");
	shyImage = ResMgr::GetInst()->ImgLoad(L"shy", L"Image\\Car1_Shy.bmp");
	angryImage = ResMgr::GetInst()->ImgLoad(L"angry", L"Image\\Car1_Angry.bmp");
	happyImage = ResMgr::GetInst()->ImgLoad(L"happy", L"Image\\Car1_Happy.bmp");
	surpriseImage = ResMgr::GetInst()->ImgLoad(L"surprise", L"Image\\Car1_Surprise.bmp");
	sadImage = ResMgr::GetInst()->ImgLoad(L"sad", L"Image\\Car1_Sad.bmp");
	currentImage = defaultImage;
}

Car::~Car()
{
}

void Car::Update()
{
}

void Car::Render(HDC _dc)
{
	int Width = (int)currentImage->GetWidth();
	int Height = (int)currentImage->GetHeight();

	Vec2 vPos = GetPos();
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width, Height
		, currentImage->GetDC()
		, 0, 0, Width, Height
		, RGB(0, 0, 255)); Component_Render(_dc);

}

void Car::ChangeImage(FaceEnum face)
{
	switch (face)
	{
	case 0:
		currentImage = defaultImage;
		break;

	case 1:
		currentImage = shyImage;
		break;

	case 2:
		currentImage = angryImage;
		break;

	case 3:
		currentImage = happyImage;
		break;

	case 4:
		currentImage = surpriseImage;
		break;

	case 5:
		currentImage = sadImage;
		break;

	default:
		break;
	}

}
