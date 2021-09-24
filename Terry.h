#pragma once
#include "GameObject.h"
#include "Config.h"

class Image;
class Terry : public GameObject
{
private:
	Image* img;
	int frameX, frameY;
	int elapsedCount;

	bool isAtk[4] = {};
	bool currAtk;
public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void Attack(AttackType type);
};

