#include "pch.h"
#include "Scene_01.h"
#include "Object.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "SoundMgr.h"
#include "FaceEnum.h"
#include "HeartImage.h"
#include "Car.h"
#include "TextObj.h"
#include "string.h"
#include "Scripts.h"
Scene_01::Scene_01()
{
	Scripts* one = new Scripts;
	one->firstStr = L"�ȳ�? ó��������";
	one->oneDecision = L"��.. �� �����ΰ�?";
	one->twoDecision = L"�ƴ�? �� �� ���ӿ��� �������� �־�";
	
	one->oneAnswer = L"�ʹ� �������̾�....";
	one->twoAnswer = L"�������� ���..? ������ ����....";

	one->oneFav = -1;
	one->twoFav = 1;

	

	scripts[0] = *one;
}

Scene_01::~Scene_01()
{
}

void Scene_01::Enter()
{
	HFONT hFontOriginal, hFont1;
	hFont1 = CreateFont(36, 0, 0, 0, 0, false, false, false,
		JOHAB_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, FF_DONTCARE, NULL);
	SelectObject(Core::GetInst()->GetMainDC(), hFont1);

	carObj = new Car;
	carObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f - 350,
		Core::GetInst()->GetResolution().y / 2.f + 200));
	carObj->SetScale(Vec2(800.f, 800.f));
	AddObject(carObj, GROUP_TYPE::Car);

	Object* titleImageObj = new HeartImage;
	titleImageObj->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f + -550,
		Core::GetInst()->GetResolution().y / 2.f - 300));
	titleImageObj->SetScale(Vec2(256.f, 256.f));
	AddObject(titleImageObj, GROUP_TYPE::Titleimage);

	favText = new TextObj(200, 70);
	favText->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f,
		Core::GetInst()->GetResolution().y / 2.f));
	favText->SetScale(Vec2(800.f, 800.f));
	AddObject(favText, GROUP_TYPE::Text);
	favText->ChangeText(L"����ȣ���� : %d", favorite);


	firstText = new TextObj(600, 50);
	firstText->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f,
		Core::GetInst()->GetResolution().y / 2.f));
	firstText->SetScale(Vec2(800.f, 800.f));
	AddObject(firstText, GROUP_TYPE::Text);
	firstText->ChangeText(L"", 999);


	oneDecisionText = new TextObj(900, 200);
	oneDecisionText->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f,
		Core::GetInst()->GetResolution().y / 2.f));
	oneDecisionText->SetScale(Vec2(800.f, 800.f));
	AddObject(oneDecisionText, GROUP_TYPE::Text);
	oneDecisionText->ChangeText(L"", 999);


	twoDecisionText = new TextObj(900, 350);
	twoDecisionText->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f,
		Core::GetInst()->GetResolution().y / 2.f));
	twoDecisionText->SetScale(Vec2(800.f, 800.f));
	AddObject(twoDecisionText, GROUP_TYPE::Text);
	twoDecisionText->ChangeText(L"", 999);

	answerText = new TextObj(600, 500);
	answerText->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f,
		Core::GetInst()->GetResolution().y / 2.f));
	answerText->SetScale(Vec2(800.f, 800.f));
	AddObject(answerText, GROUP_TYPE::Text);
	answerText->ChangeText(L"", 999);

}

void Scene_01::Exit()
{
}

void Scene_01::Update()
{
	Scene::Update();

	//if (KEY_TAP(KEY::D))
	//{
	//	carObj->ChangeImage(FaceEnum::Default);
	//}
	if (KEY_TAP(KEY::A))
	{
		favText->ChangeText(L"����ȣ���� : %d", --favorite);
	}

	if (KEY_TAP(KEY::Z) && isSelect)
	{
		isSelect = false;
		isOne = true;
	}
	if (KEY_TAP(KEY::X) && isSelect)
	{
		isSelect = false;
		isTwo = true;
	}

	if (KEY_TAP(KEY::SPACE) || KEY_TAP(KEY::Z) || KEY_TAP(KEY::X))
	{
		if (isSelect)
		{
			return;
		}

		switch (cnt++)
		{
		case 0:
			firstText->ChangeText(scripts[0].firstStr, 999);
			break;

		case 1:
			oneDecisionText->ChangeText(scripts[0].oneDecision, 999);
			twoDecisionText->ChangeText(scripts[0].twoDecision, 999);
			isSelect = true;

		case 2:
			if (isOne)
			{
				answerText->ChangeText(scripts[0].oneAnswer, 999);
			}
			if (isTwo)
			{
				answerText->ChangeText(scripts[0].twoAnswer, 999);
			}
			isOne = false;
			isTwo = false;
			break;

		case 3:
			cnt = 0;
			firstText->ChangeText(L"", 999);
			oneDecisionText->ChangeText(L"", 999);
			twoDecisionText->ChangeText(L"", 999);
			answerText->ChangeText(L"", 999);
			//�������� ��ȹ �ٲٱ� ��

		default:
			break;
		}
	}


}

