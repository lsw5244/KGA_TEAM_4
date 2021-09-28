#pragma once
#include "Character.h"
#include "Terry.h"

class Image;
class Andy : public Character
{
private:
	Terry* enemy;

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	inline void SetTerry(Terry* enemy) { this->enemy = enemy; }

	void AutoMove();
	void Attack(AttackType type);
	void Damaged();
};
