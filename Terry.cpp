#include "Terry.h"
#include "Image.h"
#include "KeyManager.h"

void Terry::Init()
{
	img = new Image;
	img->Init("Image/Terry/Terry_walk.bmp", 2450, 350, 7, 1, true, RGB(255, 0, 255));
	frameX = frameY = 0;
	elapsedCount = 0;
	pos.x = (WIN_SIZE_X / 5) * 4;
	pos.y = (WIN_SIZE_Y / 6) * 4;
	moveSpeed = 10.0f;
}

void Terry::Update()
{

	// 약발
	if (KeyManager::GetSingleton()->IsStayKeyDown('K'))
	{
		img->Init("Image/Terry/Terry_weakkick.bmp", 2450, 350, 7, 1, true, RGB(255, 0, 255));

		elapsedCount++;
		if (elapsedCount >= 4)
		{
			frameX++;
			if (frameX >= 7)
			{
				frameX = 0;
			}
			elapsedCount = 0;
		}
	}
	// 약손
	if (KeyManager::GetSingleton()->IsStayKeyDown('I'))
	{
		img->Init("Image/Terry/Terry_weakpunch.bmp", 2450, 350, 7, 1, true, RGB(255, 0, 255));
		elapsedCount++;
		if (elapsedCount >= 4)
		{
			frameX++;
			if (frameX >= 7)
			{
				frameX = 0;
			}
			elapsedCount = 0;
		}
	}

	// 강발
	if (KeyManager::GetSingleton()->IsStayKeyDown('L'))
	{
		img->Init("Image/Terry/Terry_strongkick.bmp", 2800, 350, 8, 1, true, RGB(255, 0, 255));

		elapsedCount++;
		if (elapsedCount >= 4)
		{
			frameX++;
			if (frameX >= 8)
			{
				frameX = 0;
			}
			elapsedCount = 0;
		}
	}
	// 강손
	if (KeyManager::GetSingleton()->IsStayKeyDown('O'))
	{
		img->Init("Image/Terry/Terry_strongpunch.bmp", 4200, 350, 12, 1, true, RGB(255, 0, 255));

		elapsedCount++;
		if (elapsedCount >= 4)
		{
			frameX++;
			if (frameX >= 12)
			{
				frameX = 0;
			}
			elapsedCount = 0;
		}
	}
	// 앞으로 움직이기
	if (KeyManager::GetSingleton()->IsStayKeyDown(VK_NUMPAD6))
	{
		img->Init("Image/Terry/Terry_walk.bmp", 2450, 350, 7, 1, true, RGB(255, 0, 255));
		elapsedCount++;
		if (elapsedCount >= 10)
		{
			frameX++;
			pos.x += moveSpeed;
			if (frameX >= 7)
			{
				frameX = 0;
			}
			elapsedCount = 0;
		}
	}
	else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_NUMPAD4))
	{
		img->Init("Image/Terry/Terry_walk.bmp", 2450, 350, 7, 1, true, RGB(255, 0, 255));
		elapsedCount++;
		if (elapsedCount >= 10)
		{
			frameX--;
			pos.x -= moveSpeed;
			if (frameX < 0)
			{
				frameX = 6;
			}
			elapsedCount = 0;
		}
	}
}

void Terry::Render(HDC hdc)
{
	if (img)
	{
		img->Render(hdc, pos.x, pos.y, frameX, frameY);
	}
}

void Terry::Release()
{
	if (img)
	{
		delete img;
		img = nullptr;
	}
}


