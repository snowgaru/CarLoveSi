#pragma once
#include "Object.h"
class Image;
class HeartImage : public Object
{
private:
	Image* m_pImage;
	CLONE(HeartImage);
public:

	HeartImage();
	~HeartImage();
	void Update()       override;
	void Render(HDC _dc) override;
};

