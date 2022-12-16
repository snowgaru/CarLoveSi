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
Scene_01::Scene_01()
{
}

Scene_01::~Scene_01()
{
}

void Scene_01::Enter()
{;
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


}

void Scene_01::Exit()
{
}

void Scene_01::Update()
{
	Scene::Update();
	if (KEY_TAP(KEY::S))
	{
		carObj->ChangeImage(FaceEnum::Sad);
	}
	if (KEY_TAP(KEY::H))
	{
		carObj->ChangeImage(FaceEnum::Happy);
	}
	if (KEY_TAP(KEY::D))
	{
		carObj->ChangeImage(FaceEnum::Default);
	}
}
