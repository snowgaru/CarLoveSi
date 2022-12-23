#include "pch.h"
#include "HeartImage.h"
#include "ResMgr.h"
#include "Image.h"

HeartImage::HeartImage()
{
	m_pImage = ResMgr::GetInst()->ImgLoad(L"Heart", L"Image\\Heart.bmp");
}

HeartImage::~HeartImage()
{
}

void HeartImage::Update()
{
}

void HeartImage::Render(HDC _dc)
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
