#pragma once
#include "Scene.h"
#include "Object.h"
#include "Car.h"
class Scene_01 :
    public Scene
{
private:
public:
    Car* carObj;
    Scene_01();
    virtual ~Scene_01();
    int favorite = 50;
    TCHAR str[50] = L"현재 호감도 : " + favorite;

    RECT rcStr2 = { -300,300,300,100 }; //left,top,right,bottom 순서
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
};

