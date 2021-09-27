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

	isHit = false;
	hpimg = new Image;
	hpimg->Init("Image/Terry/Terry_HP_full.bmp", 360, 40, 1, 1, true, NULL);
	pos2.x = (WIN_SIZE_X / 5) * 1;
	pos2.y = (WIN_SIZE_Y / 6);

	koimg = new Image;
	koimg->Init("Image/KO_Andy.bmp", 300, 100, 1, 1, true, RGB(255, 0, 255));
	pos3.x = (WIN_SIZE_X / 2);
	pos3.y = (WIN_SIZE_Y / 2);

	enemy = new Terry;
	enemyPos.x = 0;
	enemyPos.y = 0;
	charX = img->GetImageInfo()->frameWidth - 280; // 80

}

void Andy::Update()
{
	if (isAlive == false)
	{
		return;
	}

	if (enemyCurrAtk && (enemyPos.x - pos.x < 110) && !isHit)
	{
		isHit = true;
	}
	if (isHit == true)
	{
		Damaged();
	}
	else if (!isHit)
	{
		if (currAtk == false)
		{
			// 앞으로 움직이기
			if (KeyManager::GetSingleton()->IsStayKeyDown('D'))
			{
				img->Release();
				img = new Image;
				string imgName = "Image/Andy_walkRight.bmp";
				img->Init(imgName.c_str(), 2000, 400, 5, 1, true, RGB(255, 0, 255));

				elapsedCount++;
				if (elapsedCount >= 8)
				{
					frameX++;

					if (pos.x - (charX / 2) < enemyPos.x + (charX / 2)) 
					{
						pos.x += moveSpeed;
					}

					if (frameX >= 5)
					{
						frameX = 0;
					}
					elapsedCount = 0;
				}
			}
			else if (KeyManager::GetSingleton()->IsStayKeyDown('A'))
			{
				img->Release();
				img = new Image;
				string imgName = "Image/Andy_walkLeft.bmp";
				img->Init(imgName.c_str(), 2000, 400, 5, 1, true, RGB(255, 0, 255));

				elapsedCount++;
				if (elapsedCount >= 8)
				{
					frameX--;

					if (pos.x + (charX / 2) > 0) 
					{
						pos.x -= moveSpeed;
					}

					if (frameX <= -1)
					{
						frameX = 4;
					}
					elapsedCount = 0;
				}
			}
			else
			{
				if (HP && isAlive)
				{
					AutoMove();
				}
			}

			if (KeyManager::GetSingleton()->IsStayKeyDown('T'))
			{
				frameX = 0;
				isAtk[AttackType::SH] = true;
				currAtk = true;
			}
			if (KeyManager::GetSingleton()->IsStayKeyDown('Y'))
			{
				frameX = 0;
				isAtk[AttackType::BH] = true;
				currAtk = true;
			}
			if (KeyManager::GetSingleton()->IsStayKeyDown('G'))
			{
				frameX = 0;
				isAtk[AttackType::SF] = true;
				currAtk = true;
			}
			if (KeyManager::GetSingleton()->IsStayKeyDown('H'))
			{
				frameX = 0;
				isAtk[AttackType::BF] = true;
				currAtk = true;
			}
		}
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
}

void Andy::Render(HDC hdc)
{
	if (img)
	{
		img->Render(hdc, pos.x, pos.y, frameX, frameY/*, 300, 300*/);
	}

	if (hpimg)
	{
		hpimg->Render(hdc, pos2.x, pos2.y);
	}
}

void Andy::Release()
{
	if (img)
	{
		delete img;
		img = nullptr;
	}
	if (hpimg)
	{
		delete hpimg;
		hpimg = nullptr;
	}
}

void Andy::AutoMove()
{
	img->Release();
	img = new Image;
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
void Andy::Attack(AttackType type)
{
	string imgName;
	img->Release();
	img = new Image;
	switch (type)
	{
	case SH:
		imgName = "Image/Andy_smallHand.bmp";
		img->Init(imgName.c_str(), 3600, 400, 9, 1, true, RGB(255, 0, 255));
		elapsedCount++;
		if (elapsedCount >= 4)
		{
			if (frameX == 8)
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
		imgName = "Image/Andy_bigHand.bmp";
		img->Init(imgName.c_str(), 4000, 400, 10, 1, true, RGB(255, 0, 255));
		elapsedCount++;
		if (elapsedCount >= 4)
		{
			if (frameX == 9)
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
		imgName = "Image/Andy_smallFoot.bmp";
		img->Init(imgName.c_str(), 3200, 400, 8, 1, true, RGB(255, 0, 255));

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
	case BF:
		imgName = "Image/Andy_bigFoot.bmp";
		img->Init(imgName.c_str(), 5600, 400, 14, 1, true, RGB(255, 0, 255));

		elapsedCount++;
		if (elapsedCount >= 4)
		{
			if (frameX == 13)
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
void Andy::Damaged()
{
	static bool getDamage = false;

	img->Release();
	img = new Image;
	img->Init("Image/Andy_dead.bmp", 2100, 350, 6, 1, true, RGB(255, 0, 255));
	elapsedCount++;
	if (HP && isAlive && HP > 0)
	{
		if (elapsedCount >= 15)
		{
			frameX++;
			elapsedCount = 0;
			if (frameX >= 2)
			{
				isHit = false;
				frameX = 0;
				getDamage = false;
				return;
			}
			if (getDamage == false)
			{
				getDamage = true;
				HP -= attackValue;
			}
			return;
		}
	}
	else if (HP <= 0)
	{
		if (elapsedCount >= 30)
		{
			frameX++;
			pos.x -= 70;
			elapsedCount = 0;
			if (frameX >= 6)
			{
				isHit = false;
				frameX = 5;
				isAlive = false;
				return;
			}
			return;
		}
	}
}