#pragma once
#include "GameObject.h"
//#include <iostream>

enum MoveDir;
class Image;
class Andy : public GameObject
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

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	inline void SetMoveDir(MoveDir dir) { this->moveDir = dir; }
	inline RECT GetRect() { return this->shape; }
	inline void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }
	inline bool GetIsAlive() { return this->isAlive; }

	void AutoMove();
	void SmallHand();
	//float GetImgWidht() {}
};

