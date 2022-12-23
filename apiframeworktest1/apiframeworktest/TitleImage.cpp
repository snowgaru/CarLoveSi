#include "pch.h"
#include "TitleImage.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Image.h"
TitleImage::TitleImage()
{
	//CreateCollider();
	//GetCollider()->SetScale(Vec2(200.f, 300.f));
	m_pImage = ResMgr::GetInst()->ImgLoad(L"TitleImage", L"Image\\Title.bmp");
}

TitleImage::~TitleImage()
{
}

void TitleImage::Render(HDC _dc)
{
	int Width = (int)m_pImage->GetWidth();
	int Height = (int)m_pImage->GetHeight();
	
	Vec2 vPos = GetPos();
	TransparentBlt(_dc
		, (int)(vPos.x - (float)(Width / 2))
		, (int)(vPos.y - (float)(Height / 2))
		, Width, Height
		, m_pImage->GetDC()
		, 0, 0, Width, Height
		, RGB(0, 0, 255)); Component_Render(_dc);


}

void TitleImage::Update()
{
}
