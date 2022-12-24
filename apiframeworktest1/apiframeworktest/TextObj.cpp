#include "pch.h"
#include "TextObj.h"
#include "string"
#include "Core.h"

void TextObj::ChangeText(wstring str, int fav)
{
	if (fav == 999)
	{
		const wchar_t* szName = str.c_str();
		swprintf_s(input, szName, fav);
	}
	else
	{
		const wchar_t* szName = str.c_str();
		swprintf_s(input, szName, fav);
	}
}

TextObj::TextObj(int _x, int _y)
{
	x = _x; y = _y;
	l = x + 3000;
	r = y + 1000;
}

TextObj::~TextObj()
{
}

void TextObj::Update()
{
}

void TextObj::Render(HDC _dc)
{
	RECT rt = { x, y, l, r };
	DrawText(Core::GetInst()->GetMemDC(), input, -1, &rt, DT_LEFT | DT_WORDBREAK);
	
	//TextOut(Core::GetInst()->GetMemDC(), x, y, input, lstrlen(input));
}
