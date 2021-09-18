#pragma once
#include "GameObject.h"
enum MoveDir;
class Image;
class Iori : public GameObject
{
private:
	Image* img;
	int frameX, frameY;
	int elapsedCount;
	MoveDir moveDir;
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
	//float GetImgWidht() {}
};

