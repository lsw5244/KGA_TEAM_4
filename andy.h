#pragma once
#include "GameObject.h"
#include "Config.h"
//#include <iostream>

enum MoveDir;
class Image;
class Terry;

class Andy : public GameObject
{
private:
	Image* img;
	Image* hpimg;
	int frameX, frameY;
	int elapsedCount;
	int HP;
	int attackValue;
	MoveDir moveDir;
	MoveDir frameDir;
	bool isAlive;

	Terry* enemy;
	POINTFLOAT enemyPos;
	int charX;

	bool isAtk[4] = {};
	bool currAtk;
public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	template <typename T>
	void SetEnemy(T* _enemy) { this->enemy = _enemy; }

	inline RECT GetRect() { return this->shape; }
	inline void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }
	inline bool GetIsAlive() { return this->isAlive; }

	void AutoMove();

	void Attack(AttackType type);
	//float GetImgWidht() {}
};

