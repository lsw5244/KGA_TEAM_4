#include "Andy.h"
#include "Image.h"
#include "KeyManager.h"
#include "Config.h"

void Andy::Init()
{


	img = new Image;
	string imgName = "Image/Andy_stand.bmp";
	img->Init(imgName.c_str(), 1330, 190, 7, 1, true, RGB(255, 0, 255));
	moveDir = MoveDir::Right;
	frameDir = MoveDir::Right;
	elapsedCount = 0;
	frameX = 0;
	frameY = 0;
	HP = 100;
	attackValue = 10;

	isAlive = true;
	pos.x = (WIN_SIZE_X / 5) * 1;
	pos.y = (WIN_SIZE_Y / 6) * 4;
	moveSpeed = 10.0f;

	shape.left = pos.x - img->GetImageInfo()->frameWidth / 2;
	shape.right = pos.x + img->GetImageInfo()->frameWidth / 2;
	shape.bottom = pos.y + img->GetImageInfo()->frameHeight / 2;
	shape.top = pos.y - img->GetImageInfo()->frameHeight / 2;
}

void Andy::Update()
{
	// 앞으로 움직이기
	if (KeyManager::GetSingleton()->IsStayKeyDown('D'))
	{
		string imgName = "Image/Andy_walkRight.bmp";
		img->Init(imgName.c_str(), 2000, 400, 5, 1, true, RGB(255, 0, 255));

		elapsedCount++;
		if (elapsedCount >= 10)
		{
			frameX++;
			pos.x += moveSpeed;
			if (frameX >= 5)
			{
				frameX = 0;
			}
			elapsedCount = 0;
		}
	}
	else if (KeyManager::GetSingleton()->IsStayKeyDown('A'))
	{
		string imgName = "Image/Andy_walkLeft.bmp";
		img->Init(imgName.c_str(), 2000, 400, 5, 1, true, RGB(255, 0, 255));

		elapsedCount++;
		if (elapsedCount >= 10)
		{
			frameX--;
			pos.x -= moveSpeed;
			if (frameX <= -1)
			{
				frameX = 4;
			}
			elapsedCount = 0;
		}
	}
	else if (KeyManager::GetSingleton()->IsStayKeyDown('T'))
	{
		string imgName = "Image/Andy_smallHand.bmp";
		img->Init(imgName.c_str(), 3600, 400, 9, 1, true, RGB(255, 0, 255));

		elapsedCount++;
		if (elapsedCount >= 5)
		{
			frameX++;
			elapsedCount = 0;
			if (frameX >= 9)
			{
				frameX = 0;
			}
		}

	}
	else if (KeyManager::GetSingleton()->IsStayKeyDown('Y'))
	{
		string imgName = "Image/Andy_bigHand.bmp";
		img->Init(imgName.c_str(), 4000, 400, 10, 1, true, RGB(255, 0, 255));

		elapsedCount++;
		if (elapsedCount >= 5)
		{
			frameX++;
			elapsedCount = 0;
			if (frameX >= 10)
			{
				frameX = 0;
			}
		}

	}
	else if (KeyManager::GetSingleton()->IsStayKeyDown('G'))
	{
		string imgName = "Image/Andy_smallFoot.bmp";
		img->Init(imgName.c_str(), 3200, 400, 8, 1, true, RGB(255, 0, 255));

		elapsedCount++;
		if (elapsedCount >= 5)
		{
			frameX++;
			elapsedCount = 0;
			if (frameX >= 8)
			{
				frameX = 0;
			}
		}

	}
	else if (KeyManager::GetSingleton()->IsStayKeyDown('H'))
	{
		string imgName = "Image/Andy_bigFoot.bmp";
		img->Init(imgName.c_str(), 5600, 400, 14, 1, true, RGB(255, 0, 255));

		elapsedCount++;
		if (elapsedCount >= 5)
		{
			frameX++;
			elapsedCount = 0;
			if (frameX >= 10)
			{
				frameX = 0;
			}
		}

	}
	else
	{
		AutoMove();
	}


}

void Andy::Render(HDC hdc)
{
	if (img && isAlive)
	{
		img->Render(hdc, pos.x, pos.y, frameX, frameY/*, 300, 300*/);
	}

}

void Andy::Release()
{
	if (img)
	{
		delete img;
		img = nullptr;
	}
}

void Andy::AutoMove()
{
	string imgName = "Image/Andy_stand.bmp";
	img->Init(imgName.c_str(), 2800, 400, 7, 1, true, RGB(255, 0, 255));
	elapsedCount++;
	if (elapsedCount >= 8)
	{
		if (frameX <= 0)
		{
			frameDir = MoveDir::Right;
		}
		if (frameX >= 6)
		{
			frameDir = MoveDir::Left;
		}
		switch (frameDir)
		{
		case MoveDir::Right:
			frameX++;
			break;
		case MoveDir::Left:
			frameX--;
			break;
		}
		elapsedCount = 0;
	}

}

void Andy::SmallHand()
{
	string imgName = "Image/Andy_smallHand.bmp";
	img->Init(imgName.c_str(), 2250, 250, 9, 1, true, RGB(255, 0, 255));
	elapsedCount++;
	if (elapsedCount >= 8)
	{
		while (frameX < 9)
		{
			frameX++;

			elapsedCount = 0;
		}
	}
}
