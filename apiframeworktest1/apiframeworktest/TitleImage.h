#pragma once
#include "Object.h"

class Image;
class TitleImage : public Object
{

public:
	Image* m_pImage;
	TitleImage();
	~TitleImage();
	void Render(HDC _dc);
};

