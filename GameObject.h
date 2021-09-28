#pragma once
#include <Windows.h>
#include "Config.h"

class GameObject
{
protected:
	POINTFLOAT pos;
	POINTFLOAT pos2;
	POINTFLOAT pos3;

	int frameX, frameY;
	int elapsedCount;

	MoveDir frameDir;

public:
	void Move();

	GameObject();
	~GameObject();
};