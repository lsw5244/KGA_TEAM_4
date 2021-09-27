#pragma once
#include "GameObject.h"
#include "Config.h"

class Andy;
class Image;
class Terry : public GameObject
{
private:
	Image* img;
	Image* hpimg;
	Image* hp2img;
	Image* koimg;
	Image* countimg;
	int frameX, frameY;
	int elapsedCount;
	int attackValue;

	MoveDir frameDir;

	Andy* enemy;
	int charX;

	bool isAlive;
	bool isAtk[4] = {};


public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void AutoMove();
	void Attack(AttackType type);
	void Damaged();
	inline void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }
	inline bool GetIsAlive() { return this->isAlive; }
};
