#pragma once
#include "character.h"

class Andy;
class Image;
class Terry : public Character
{
private:
	Image* countimg;

	Andy* enemy;

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void AutoMove();
	void Attack(AttackType type);
	void Damaged();
};