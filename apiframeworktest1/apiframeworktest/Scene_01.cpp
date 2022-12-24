#include "pch.h"
#include "Scene_01.h"
#include "Object.h"
#include "Core.h"
#include "Image.h"
#include "PathMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "FaceEnum.h"
#include "HeartImage.h"
#include "Car.h"
#include "TextObj.h"
#include "string.h"
#include "Scripts.h"
#include "TitleImage.h"
Scene_01::Scene_01()
{
	#pragma region scripts0
	Scripts* zero = new Scripts;
	zero->firstStr = L"�ȳ�? ó��������";
	zero->oneDecision = L"��.. �� �����ΰ�?";
	zero->twoDecision = L"�ƴ�? �� �� ���ӿ��� �������� �־�";

	zero->oneAnswer = L"�ʹ� �������̾�....";
	zero->twoAnswer = L"�������� ���..? ������ ����....";

	zero->oneFav = -10;
	zero->twoFav = 15;

	zero->oneFace = FaceEnum::Sad;
	zero->twoFace = FaceEnum::Shy;
	#pragma endregion

	#pragma region scripts1
	Scripts* one = new Scripts;
	one->firstStr = L"������ ����� ���� ������ �־���. �� ù �λ��� ���? \n�� ������ �׷��� �ʾҴ�?";
	one->oneDecision = L"�翬�Ѱ� �ƴϾ�? ��� ������ ���� ���� �־�";
	one->twoDecision = L"�̰� ���� ��ģ�Ҹ���? \n����� ��� ���� ���� �׷� ������ ���";

	one->oneAnswer = L"�̷� �ý��� ����� ���Ѱ� �ƴϾ��µ� ���̾�. �ʹ� �Ǹ��ΰ�";
	one->twoAnswer = L"�� ������ �Ǿ� �� ��������. ���� �ʹ� ������ ���";

	one->oneFav = -20;
	one->twoFav = 20;

	one->oneFace = FaceEnum::Angry;
	one->twoFace = FaceEnum::Shy;
	#pragma endregion

	#pragma region scripts2
	Scripts* two = new Scripts;
	two->firstStr = L"���࿡ ���� ���� �ƴϾ��ٸ� �ʴ� �� ��� ��������? \n���� ���������� �����ϰ� �ִ°� �ƴ���?";
	two->oneDecision = L"���� �ƴϵ� ���� �߿���. �� �ʸ� ������ ��. \n�׷� ������ ���� ��.";
	two->twoDecision = L"�ʴ� ���� �ʿ��ؼ� �� ������.";

	two->oneAnswer = L"���� �׷��� �������ִ±���.. �ʹ� �⻵";
	two->twoAnswer = L"�������. ���� ����� ȥ���߰ڳ�";

	two->oneFav = +25;
	two->twoFav = -20;

	two->oneFace = FaceEnum::Happy;
	two->twoFace = FaceEnum::Angry;
	#pragma endregion

	#pragma region scripts3
	Scripts* three = new Scripts;
	three->firstStr = L"������ ����� �� ���ξ�.";
	three->oneDecision = L"��¼���. ���� ����ϱ⳪ ��";
	three->twoDecision = L"�ֱ׷�. ����ϴ°� ���ݾ�";

	three->oneAnswer = L"�ʹ� �ڷ����ݾ�! �ʹ� ����!!";
	three->twoAnswer = L"�׷��� ���� ���ڿ���..? �Ǹ��̾�";

	three->oneFav = +10;
	three->twoFav = -15;

	three->oneFace = FaceEnum::Shy;
	three->twoFace = FaceEnum::Sad;
	#pragma endregion

	#pragma region scripts4
	Scripts* four = new Scripts;
	four->firstStr = L"�� �? ���� �� �ٲ�ž���?.";
	four->oneDecision = L"�� ���� �����ϳ�. �� û���߾�?";
	four->twoDecision = L"�����߾�? ��¦��¦ ���� ���µ�?";

	four->oneAnswer = L"��� �Ĵٺ��°ž�!! ���δ� ����!!";
	four->twoAnswer = L"���� �˾ƺ��ִ±���? ������";

	four->oneFav = -20;
	four->twoFav = 15;

	four->oneFace = FaceEnum::Shy;
	four->twoFace = FaceEnum::Surprise;
	#pragma endregion

	#pragma region scripts5
	Scripts* five = new Scripts;
	five->firstStr = L"�������̾� ���δ�!! ��𰬴� �̷��� �������� ���°ž�??";
	five->oneDecision = L"�ٸ� �� �� �˾ƺ����� �׎���.";
	five->twoDecision = L"���ϰ� ����. ���� �ٺ�.";

	five->oneAnswer = L"��� �����϶�� ������ �Ϻη� �׷��°ž�? ��ŭ�ϱ� ����";
	five->twoAnswer = L"�����״� ���� �� �ϴ��� �˷��ֱ⵵ �ȴٴ°ž�? ���δ��� �׻� �̷� ���̾�!";

	five->oneFav = 20;
	five->twoFav = -20;

	five->oneFace = FaceEnum::Shy;
	five->twoFace = FaceEnum::Angry;
	#pragma endregion

	scripts[0] = *zero;
	scripts[1] = *one;
	scripts[2] = *two;
	scripts[3] = *three;
	scripts[4] = *four;
	scripts[5] = *five;
}

Scene_01::~Scene_01()
{
}

void Scene_01::Enter()
{
	SoundMgr::GetInst()->LoadSound(L"BGM", true, L"Sound\\BGM.wav");
	SoundMgr::GetInst()->Play(L"BGM");

	HFONT hFontOriginal, hFont1;
	hFont1 = CreateFont(36, 36, 36, 36, 36, false, false, false,
		JOHAB_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY, FF_DONTCARE, NULL);
	SelectObject(Core::GetInst()->GetMainDC(), hFont1);

	Object* titleImageObjs = new TitleImage(L"Image\\background.bmp");
	titleImageObjs->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f,
		Core::GetInst()->GetResolution().y / 2.f));
	titleImageObjs->SetScale(Vec2(1920.f, 1080.f));
	AddObject(titleImageObjs, GROUP_TYPE::Titleimage);

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

	amountOfChangeText = new TextObj(200, 120);
	amountOfChangeText->SetPos(Vec2(Core::GetInst()->GetResolution().x / 2.f,
		Core::GetInst()->GetResolution().y / 2.f));
	amountOfChangeText->SetScale(Vec2(800.f, 800.f));
	AddObject(amountOfChangeText, GROUP_TYPE::Text);
	amountOfChangeText->ChangeText(L"", 999);
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

		if (isQuit)
		{
			DestroyWindow(Core::GetInst()->GetWndHandle());
		}

		//��ȹ���� ����
		if (isFail)
		{
			firstText->ChangeText(L"�ᱹ ������ ��µ� �����߳�.. \n�� ��� �ۿ� ���°ǰ�.\n\n(�Τ̤̤�)\n(�⤿����)\n\n������ ���ϸ� �ν���������..", 999);
			isQuit = true;
		}
		else if (isSuccess)
		{
			firstText->ChangeText(L"���� ������ ���ִ±���. \n�츮 ���� ����̺곪 ����? ���� ���� ��Ҹ� �˰��־�. \n�� �������� ������ ������.", 999);
			isQuit = true;
		}
		else if(!isFail && !isSuccess)
		{
			switch (cnt++)
			{

			case 0:
				firstText->ChangeText(scripts[random].firstStr, 999);
				break;

			case 1:
				oneDecisionText->ChangeText(scripts[random].oneDecision, 999);
				twoDecisionText->ChangeText(scripts[random].twoDecision, 999);
				isSelect = true;

			case 2:
				if (isOne)
				{
					answerText->ChangeText(scripts[random].oneAnswer, 999);
					favorite += scripts[random].oneFav;
					amountOfChangeText->ChangeText(L"ȣ���� ��ȭ�� : %d", scripts[random].oneFav);
					favText->ChangeText(L"����ȣ���� : %d", favorite);
					carObj->ChangeImage(scripts[random].oneFace);
				}
				if (isTwo)
				{
					answerText->ChangeText(scripts[random].twoAnswer, 999);
					favorite += scripts[random].twoFav;
					amountOfChangeText->ChangeText(L"ȣ���� ��ȭ�� : %d", scripts[random].twoFav);
					favText->ChangeText(L"����ȣ���� : %d", favorite);
					carObj->ChangeImage(scripts[random].twoFace);
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
				amountOfChangeText->ChangeText(L"", 999);
				carObj->ChangeImage(FaceEnum::Default);
				//�������� ��ȹ �ٲٱ� ��
				ReSetting();

				if (favorite >= 100)
				{
					isSuccess = true;
				}
				if (favorite <= 0)
				{
					isFail = true;
				}

			default:
				break;
			}
		}
		
	}


}

void Scene_01::ReSetting()
{
	unsigned int nSeed = (unsigned)time(NULL);

	srand(nSeed);
	random = rand() % 4;
	random += 1;
}

