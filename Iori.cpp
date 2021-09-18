#include "Iori.h"
#include "Image.h"
#include "KeyManager.h"
#include "Config.h"
void Iori::Init()
{
	img = new Image;
	img->Init("Image/Iori_walk.bmp", 612, 104, 9, 1,  true, RGB(255, 0, 255));
	moveDir = MoveDir::Left;
	frameX = frameY = 0;
	elapsedCount = 0;
	
	isAlive = true;	
	pos.x = WIN_SIZE_X / 2;
	pos.y = WIN_SIZE_Y / 2;
	moveSpeed = 10.0f;

	shape.left = pos.x - img->GetImageInfo()->frameWidth / 2;
	shape.right = pos.x + img->GetImageInfo()->frameWidth / 2;
	shape.bottom = pos.y + img->GetImageInfo()->frameHeight / 2;
	shape.top = pos.y - img->GetImageInfo()->frameHeight / 2;

}

void Iori::Update()
{
	// 앞으로 움직이기
	if (KeyManager::GetSingleton()->IsStayKeyDown(VK_RIGHT))
	{
		elapsedCount++;
		if (elapsedCount >= 10)
		{
			frameX++;
			pos.x += moveSpeed;
			if (frameX >= 9)
			{
				frameX = 0;
			}
			elapsedCount = 0;
		}
	}
	else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_LEFT))
	{
		elapsedCount++;
		if (elapsedCount >= 10)
		{
			frameX--;
			pos.x -= moveSpeed;
			if (frameX < 0)
			{
				frameX = 8;
			}
			elapsedCount = 0;
		}
	}

	AutoMove();

}

void Iori::Render(HDC hdc)
{
	if (img && isAlive)
	{
		img->Render(hdc, pos.x, pos.y, frameX, frameY);
	}
}

void Iori::Release()
{
	if (img)
	{
		delete img;
		img = nullptr;
	}
}

void Iori::AutoMove()
{
	float shapeRight = pos.x + img->GetImageInfo()->frameWidth / 2;
	float shapeLeft = pos.x - img->GetImageInfo()->frameWidth / 2;

	if (shapeLeft <= 0)
	{
		moveDir = MoveDir::Right;
	}
	else if (shapeRight >= WIN_SIZE_X)
	{
		moveDir = MoveDir::Left;
	}

	switch (moveDir)
	{
	case MoveDir::Left:		pos.x -= moveSpeed; break;
	case MoveDir::Right:	pos.x += moveSpeed; break;
	}
	shape.left = pos.x - img->GetImageInfo()->frameWidth / 2;
	shape.right = pos.x + img->GetImageInfo()->frameWidth / 2;
	shape.bottom = pos.y + img->GetImageInfo()->frameHeight / 2;
	shape.top = pos.y - img->GetImageInfo()->frameHeight / 2;
}
