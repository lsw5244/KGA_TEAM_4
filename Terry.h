#pragma once
#include "GameObject.h"
#include "Config.h"

class Image;
class Andy;
class Terry : public GameObject
{
private:
	Image* img;
	Image* hpimg;
	Image* countimg;
	int frameX, frameY;
	int elapsedCount;
	int HP;
	int attackValue;

	POINTFLOAT enemyPos;

	// 캐릭터의 한 프레임
	int charX;

	MoveDir frameDir;
	Andy* enemy;


	bool isAlive;
	bool isAtk[4] = {};
	bool currAtk;

public:

	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	template <typename T>
	void SetEnemy(T* _enemy) { this->enemy = _enemy; }

	void AutoMove();
	void Attack(AttackType type);


	inline void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }
	inline bool GetIsAlive() { return this->isAlive; }
};

