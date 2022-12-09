#include "pch.h"
#include "TitleImage.h"
#include "ResMgr.h"
#include "Collider.h"

TitleImage::TitleImage()
{
	CreateCollider();
	GetCollider()->SetScale(Vec2(200.f, 300.f));
	Image* pImg = ResMgr::GetInst()->ImgLoad(L"TitleImage", L"Image\\Title.bmp");
}

TitleImage::~TitleImage()
{
}

void TitleImage::Render(HDC _dc)
{
	Component_Render(_dc);
}
