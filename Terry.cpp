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
	if (currAtk == false)
	{
		if (KeyManager::GetSingleton()->IsStayKeyDown(VK_NUMPAD6))
		{
			img->ReleaseImageInfo();
			img->Init("Image/Terry/Terry_walk.bmp", 2450, 350, 7, 1, true, RGB(255, 0, 255));
			elapsedCount++;
			if (elapsedCount >= 4)
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
			img->ReleaseImageInfo();
			img->Init("Image/Terry/Terry_walk.bmp", 2450, 350, 7, 1, true, RGB(255, 0, 255));
			elapsedCount++;
			if (elapsedCount >= 4)
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

		// 약발
		if (KeyManager::GetSingleton()->IsOnceKeyDown('K'))
		{
			frameX = 0;
			isAtk[AttackType::SF] = true;
			currAtk = true;
		}
		// 약손
		if (KeyManager::GetSingleton()->IsOnceKeyDown('I'))
		{
			frameX = 0;
			isAtk[AttackType::SH] = true;
			currAtk = true;

		}
		// 강발
		if (KeyManager::GetSingleton()->IsOnceKeyDown('L'))
		{
			frameX = 0;
			isAtk[AttackType::BF] = true;
			currAtk = true;

		}
		// 강손
		if (KeyManager::GetSingleton()->IsOnceKeyDown('O'))
		{
			frameX = 0;
			isAtk[AttackType::BH] = true;
			currAtk = true;
		}
	}
	// 앞으로 움직이기
	else
	{
		if (isAtk[AttackType::SH])
		{
			Attack(SH);
		}
		else if (isAtk[AttackType::SF])
		{
			Attack(SF);
		}
		else if (isAtk[AttackType::BH])
		{
			Attack(BH);
		}
		else if (isAtk[AttackType::BF])
		{
			Attack(BF);
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

void Terry::Attack(AttackType type)
{
	string imgName;
	switch (type)
	{
	case SH:
		img->ReleaseImageInfo();
		img->Init("Image/Terry/Terry_weakpunch.bmp", 2450, 350, 7, 1, true, RGB(255, 0, 255));
		elapsedCount++;
		if (elapsedCount >= 4)
		{
			if (frameX == 6)
			{
				for (int i = 0; i < 4; i++)
				{
					if (isAtk[i])
						isAtk[i] = false;
				}
				currAtk = false;
				frameX = 0;
			}
			frameX++;

			elapsedCount = 0;
		}
		break;
	case BH:
		img->ReleaseImageInfo();
		img->Init("Image/Terry/Terry_strongpunch.bmp", 4200, 350, 12, 1, true, RGB(255, 0, 255));

		elapsedCount++;
		if (elapsedCount >= 4)
		{
			if (frameX == 11)
			{
				for (int i = 0; i < 4; i++)
				{
					if (isAtk[i])
						isAtk[i] = false;
				}
				currAtk = false;
				frameX = 0;
			}
			frameX++;

			elapsedCount = 0;
		}
		break;
	case SF:
		img->ReleaseImageInfo();
		img->Init("Image/Terry/Terry_weakkick.bmp", 2450, 350, 7, 1, true, RGB(255, 0, 255));

		elapsedCount++;
		if (elapsedCount >= 4)
		{
			if (frameX == 6)
			{
				for (int i = 0; i < 4; i++)
				{
					if (isAtk[i])
						isAtk[i] = false;
				}
				currAtk = false;
				frameX = 0;
			}
			frameX++;

			elapsedCount = 0;
		}
		break;
	case BF:
		img->ReleaseImageInfo();
		img->Init("Image/Terry/Terry_strongkick.bmp", 2800, 350, 8, 1, true, RGB(255, 0, 255));

		elapsedCount++;
		if (elapsedCount >= 4)
		{
			if (frameX == 7)
			{
				for (int i = 0; i < 4; i++)
				{
					if (isAtk[i])
						isAtk[i] = false;
				}
				currAtk = false;
				frameX = 0;
			}
			frameX++;

			elapsedCount = 0;
		}
		break;
	default:
		break;
	}
}


