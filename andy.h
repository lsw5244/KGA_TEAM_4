#pragma once
#include "GameObject.h"
#include "Config.h"
#include "Terry.h"

enum MoveDir;
class Image;

class Andy : public GameObject
{
private:
	Image* img;
	Image* hpimg;
	Image* koimg;
	int frameX, frameY;
	int elapsedCount;
	int attackValue;
	MoveDir moveDir;
	MoveDir frameDir;
	bool isAlive;

	Terry* enemy;
	int charX;

	bool isAtk[4] = {};

	Terry* enemyTerry;
public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	inline RECT GetRect() { return this->shape; }
	inline void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }
	inline bool GetIsAlive() { return this->isAlive; }
	inline bool GetCurrAtk() { return this->currAtk; }
	inline void SetTerry(Terry* enemy) { this->enemyTerry = enemy; }

	void AutoMove();

	void Attack(AttackType type);
	void Damaged();
};
