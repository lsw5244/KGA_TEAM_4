#pragma once

#include <Windows.h>
class GameObject 
{
protected:
	POINTFLOAT pos;
	RECT shape;
	float moveSpeed;
	int bodySize;

public:
	void Move();

	inline void SetPos(POINTFLOAT pos) { this->pos = pos; }
	inline POINTFLOAT GetPos() { return this->pos; }
	inline void SetMoveSpeed(float speed) { this->moveSpeed = speed; }
	inline int GetBodySize() { return this->bodySize; }

	GameObject();
	~GameObject();
};

