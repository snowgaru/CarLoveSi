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
	
}

TextObj::~TextObj()
{
}

void TextObj::Update()
{
}

void TextObj::Render(HDC _dc)
{
	TextOut(Core::GetInst()->GetMemDC(), x, y, input, lstrlen(input));
	//TextOut(Core::GetInst()->GetMainDC(), 400, 200, input, lstrlen(input));
	//DrawText(_dc, text, -1, &rt, DT_CENTER);
	
}
