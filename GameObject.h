#pragma once

#include <Windows.h>
class GameObject
{
protected:
	POINTFLOAT pos;
	POINTFLOAT pos2;
	POINTFLOAT pos3;
	POINTFLOAT pos4;
	POINTFLOAT enemyPos;
	bool currAtk;
	bool enemyCurrAtk;
	RECT shape;
	float moveSpeed;
	int bodySize;
	int HP;
	int enemyHP;
	bool isHit;
public:
	void Move();


	inline void SetPos(POINTFLOAT pos) { this->pos = pos; }

	inline POINTFLOAT GetPos() { return this->pos; }
	inline void SetEnemyPos(POINTFLOAT pos) { this->enemyPos = pos; }
	inline bool GetCurrAtk() { return this->currAtk; }
	inline void SetEnemyCurrAtk(bool enemyCurrAtk) { this->enemyCurrAtk = enemyCurrAtk; }
	inline void SetMoveSpeed(float speed) { this->moveSpeed = speed; }
	inline int GetBodySize() { return this->bodySize; }
	inline int GetHP() { return this->HP; }
	inline void SetHP(int HP) { this->HP = HP; }
	inline int GetEnemyHP() { return this->enemyHP; }
	inline void SetEnemyHP(int HP) { this->enemyHP = HP; }

	GameObject();
	~GameObject();
};
