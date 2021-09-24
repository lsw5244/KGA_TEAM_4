#pragma once
#include "GameObject.h"

class Image;
class Terry : public GameObject
{
private:
	Image* img;
	int frameX, frameY;
	int elapsedCount;

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();
};

