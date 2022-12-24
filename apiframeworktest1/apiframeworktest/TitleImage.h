#pragma once
#include "Object.h"

class Image;
class TitleImage : public Object
{
private:
	Image* m_pImage;
	CLONE(TitleImage);
public:
	
	TitleImage(wstring str);
	~TitleImage();
	void Update()       override;
	void Render(HDC _dc) override;
};

