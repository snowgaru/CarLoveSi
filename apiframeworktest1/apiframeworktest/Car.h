#pragma once
#include "Object.h"
#include "FaceEnum.h"
class Image;
class Car:
	public Object
{
private:
	Image* defaultImage;
	Image* shyImage;
	Image* angryImage;
	Image* happyImage;
	Image* surpriseImage;
	Image* sadImage;
	Image* currentImage;

public:
	Car();
	~Car();
public:
	CLONE(Car);

public:
	void Update()       override;
	void Render(HDC _dc) override;
	void ChangeImage(FaceEnum face);
};

