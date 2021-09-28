#pragma once
#include "GameObject.h"
#include "Config.h"

class Image;
class Character : public GameObject
{
protected:
	Image* img;
	Image* hpimg;
	Image* hp2img;
	Image* koimg;

	int HP;
	int enemyHP;
	int attackValue;
	int bodySize;
	RECT shape;
	int charX;
	float moveSpeed;

	bool isAtk[4] = {};
	bool currAtk;
	bool enemyCurrAtk;
	bool isHit;
	bool isAlive;
public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();


	inline POINTFLOAT GetPos() { return this->pos; }
	inline void SetPos(POINTFLOAT pos) { this->pos = pos; }

	inline void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }
	inline bool GetIsAlive() { return this->isAlive; }

	inline void SetEnemyPos(POINTFLOAT pos) { this->enemyPos = pos; }

	inline bool GetCurrAtk() { return this->currAtk; }
	inline void SetEnemyCurrAtk(bool enemyCurrAtk) { this->enemyCurrAtk = enemyCurrAtk; }

	inline void SetMoveSpeed(float speed) { this->moveSpeed = speed; }

	inline int GetBodySize() { return this->bodySize; }

	inline int GetHP() { return this->HP; }
	inline void SetHP(int HP) { this->HP = HP; }

	inline int GetEnemyHP() { return this->enemyHP; }
	inline void SetEnemyHP(int HP) { this->enemyHP = HP; }
};
