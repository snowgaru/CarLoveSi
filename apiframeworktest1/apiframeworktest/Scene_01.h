#pragma once
#include "Scene.h"
#include "Object.h"
#include "Car.h"
#include<iostream>
#include<string>
#include "Scripts.h"
#include "TextObj.h"
#include "FaceEnum.h"
class Scene_01 :
    public Scene
{
private:
public:
    TextObj* favText;
    
    TextObj* firstText;
    TextObj* oneDecisionText;
    TextObj* twoDecisionText;
    TextObj* answerText;
    TextObj* amountOfChangeText;

public:
    Scripts scripts[6];
    Car* carObj;
    Scene_01();
    virtual ~Scene_01();
    int favorite = 50;
    int cnt = 0;
    bool isSelect;
    bool isOne;
    bool isTwo;
    bool isSuccess;
    bool isFail;
    bool isQuit;
    LPCWSTR strFav = TEXT("호감도 : ");

    int random = 0;
    //LPCWSTR strFav = TEXT(intFav);

    string intFav = to_string(favorite);

    RECT rcStr2 = { -300,300,300,100 }; //left,top,right,bottom 순서
public:
    virtual void Enter() override;
    virtual void Exit() override;
    virtual void Update() override;
    void ReSetting();
    //void ShowText(HDC _dc);
};

