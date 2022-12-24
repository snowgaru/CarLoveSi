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
	zero->firstStr = L"안녕? 처음만나네";
	zero->oneDecision = L"너.. 내 취향인걸?";
	zero->twoDecision = L"아니? 넌 내 상상속에서 만난적이 있어";

	zero->oneAnswer = L"너무 직설적이야....";
	zero->twoAnswer = L"망상적인 사람..? 오히려 좋아....";

	zero->oneFav = -10;
	zero->twoFav = 15;

	zero->oneFace = FaceEnum::Sad;
	zero->twoFace = FaceEnum::Shy;
	#pragma endregion

	#pragma region scripts1
	Scripts* one = new Scripts;
	one->firstStr = L"너한테 물어보고 싶은 질문이 있었어. 내 첫 인상은 어땠어? \n막 설레고 그렇지 않았니?";
	one->oneDecision = L"당연한거 아니야? 어떻게 반하지 않을 수가 있어";
	one->twoDecision = L"이게 무슨 미친소리야? \n사람이 어떻게 차를 보고 그런 생각이 들어";

	one->oneAnswer = L"이런 시시한 대답을 원한게 아니었는데 말이야. 너무 실망인걸";
	one->twoAnswer = L"이 정도는 되야 내 주인이지. 역시 너무 마음에 들어";

	one->oneFav = -20;
	one->twoFav = 20;

	one->oneFace = FaceEnum::Angry;
	one->twoFace = FaceEnum::Shy;
	#pragma endregion

	#pragma region scripts2
	Scripts* two = new Scripts;
	two->firstStr = L"만약에 내가 차가 아니었다면 너는 날 어떻게 대했을까? \n설마 도구쯤으로 생각하고 있는건 아니지?";
	two->oneDecision = L"차든 아니든 뭐가 중요해. 난 너만 있으면 돼. \n그런 생각은 하지 마.";
	two->twoDecision = L"너는 내가 필요해서 산 도구야.";

	two->oneAnswer = L"역시 그렇게 생각해주는구나.. 너무 기뻐";
	two->twoAnswer = L"도구라니. 오늘 제대로 혼나야겠네";

	two->oneFav = +25;
	two->twoFav = -20;

	two->oneFace = FaceEnum::Happy;
	two->twoFace = FaceEnum::Angry;
	#pragma endregion

	#pragma region scripts3
	Scripts* three = new Scripts;
	three->firstStr = L"오늘은 기분이 좀 별로야.";
	three->oneDecision = L"어쩌라고. 빨리 출발하기나 해";
	three->twoDecision = L"왜그래. 사랑하는거 알잖아";

	three->oneAnswer = L"너무 박력있잖아! 너무 좋아!!";
	three->twoAnswer = L"그렇게 쉬운 남자였어..? 실망이야";

	three->oneFav = +10;
	three->twoFav = -15;

	three->oneFace = FaceEnum::Shy;
	three->twoFace = FaceEnum::Sad;
	#pragma endregion

	#pragma region scripts4
	Scripts* four = new Scripts;
	four->firstStr = L"나 어때? 오늘 뭐 바뀐거없어?.";
	four->oneDecision = L"차 안이 깨끗하네. 차 청소했어?";
	four->twoDecision = L"세차했어? 반짝반짝 빛이 나는데?";

	four->oneAnswer = L"어딜 쳐다보는거야!! 주인님 변태!!";
	four->twoAnswer = L"역시 알아봐주는구나? ㅎㅎㅎ";

	four->oneFav = -20;
	four->twoFav = 15;

	four->oneFace = FaceEnum::Shy;
	four->twoFace = FaceEnum::Surprise;
	#pragma endregion

	#pragma region scripts5
	Scripts* five = new Scripts;
	five->firstStr = L"오랜만이야 주인님!! 어디갔다 이렇게 오랜만에 오는거야??";
	five->oneDecision = L"다른 차 좀 알아보느라 그럤어.";
	five->twoDecision = L"일하고 왔지. 요즘 바빠.";

	five->oneAnswer = L"어머 질투하라고 나한테 일부러 그러는거야? 앙큼하긴 ㅎㅎ";
	five->twoAnswer = L"나한테는 무슨 일 하는지 알려주기도 싫다는거야? 주인님은 항상 이런 식이야!";

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
	favText->ChangeText(L"현재호감도 : %d", favorite);


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
		favText->ChangeText(L"현재호감도 : %d", --favorite);
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

		//기획오면 수정
		if (isFail)
		{
			firstText->ChangeText(L"결국 마음을 얻는데 실패했네.. \n이 방법 밖에 없는건가.\n\n(부ㅜㅜㅇ)\n(콰ㅏㅏㅇ)\n\n가지지 못하면 부숴버려야지..", 999);
			isQuit = true;
		}
		else if (isSuccess)
		{
			firstText->ChangeText(L"드디어 이쪽을 봐주는구나. \n우리 같이 드라이브나 갈까? 내가 좋은 장소를 알고있어. \n넌 이제부터 영원히 내꺼야.", 999);
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
					amountOfChangeText->ChangeText(L"호감도 변화량 : %d", scripts[random].oneFav);
					favText->ChangeText(L"현재호감도 : %d", favorite);
					carObj->ChangeImage(scripts[random].oneFace);
				}
				if (isTwo)
				{
					answerText->ChangeText(scripts[random].twoAnswer, 999);
					favorite += scripts[random].twoFav;
					amountOfChangeText->ChangeText(L"호감도 변화량 : %d", scripts[random].twoFav);
					favText->ChangeText(L"현재호감도 : %d", favorite);
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
				//랜덤으로 기획 바꾸기 ㄱ
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

