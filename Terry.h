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
	int HP;
	int attackValue;
	MoveDir moveDir;
	MoveDir frameDir;
	bool isAlive;
	bool isAtk[4] = {};
	bool currAtk;

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void AutoMove();
	void Attack(AttackType type);

	inline void SetMoveDir(MoveDir dir) { this->moveDir = dir; }
	inline void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }
	inline bool GetIsAlive() { return this->isAlive; }
};

