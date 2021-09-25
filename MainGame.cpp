#include "MainGame.h"
#include "Singleton.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "Image.h"
#include "Iori.h"
#include "Terry.h"

void MainGame::Init()
{
	KeyManager::GetSingleton()->Init();
	SceneManager::GetSingleton();

	// Ÿ�̸� ����
	hTimer = (HANDLE)SetTimer(g_hWnd, 0, 10, NULL);

	// �����
	backBuffer = new Image;
	backBuffer->Init(WIN_SIZE_X, WIN_SIZE_Y);

	// ��� �̹���
	string FileIndex;

	for (int i = 0; i < 8; i++)
	{
		FileIndex = "Image/KOF_BgImg/0000" + to_string(i + 1) + ".bmp";
		backGround[i] = new Image;
		backGround[i]->Init(FileIndex.c_str(), 2700, 900);
	}

	andy = new Andy;
	andy->Init();
	// �׸�
	terry = new Terry;
	terry->Init();

	mapFrameTimer = 0;
}

void MainGame::Update()
{
	mapFrameTimer++;

	if (mapFrameTimer % 20 == 0) {
		mapFrame++;
		if (mapFrame == 8) mapFrame = 0;
	}

	if (terry)
	{
		terry->Update();
	}

	if (andy)
	{
		andy->Update();
	}
	

	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render(HDC hdc)
{
	HDC hBackBufferDC = backBuffer->GetMemDC();

	backGround[mapFrame]->Render(hBackBufferDC);

	andy->Render(hBackBufferDC);

	terry->Render(hBackBufferDC);

	backBuffer->Render(hdc);
}

void MainGame::Release()
{
	SAFE_RELEASE(backBuffer);
	andy->Release();
	SAFE_RELEASE(andy);
	SAFE_RELEASE(terry);

	for (int i = 0; i < 8; i++)
	{
		if (backGround[i])
		{
			backGround[i]->Release();
			delete backGround[i];
			backGround[i] = nullptr;
		}
	}
	// Ÿ�̸� ��ü ����
	KillTimer(g_hWnd, 0);
}


LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
