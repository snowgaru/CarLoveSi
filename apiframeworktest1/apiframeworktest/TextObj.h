#pragma once
#include "Object.h"
class Image;
class TextObj : public Object
{
private :
	CLONE(TextObj);
public:
	TCHAR input[512];
	int x, y;

public:
	void ChangeText(wstring strint, int fav);

	TextObj(int _x, int _y);
	~TextObj();
	void Update()       override;
	void Render(HDC _dc) override;
};

