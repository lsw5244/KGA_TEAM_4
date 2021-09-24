#include "MainGame.h"
#include "Singleton.h"
#include "KeyManager.h"
#include "SceneManager.h"
#include "Image.h"
#include "Iori.h"

void MainGame::Init()
{
	KeyManager::GetSingleton()->Init();
	SceneManager::GetSingleton();

	// 타이머 셋팅
	hTimer = (HANDLE)SetTimer(g_hWnd, 0, 10, NULL);

	mousePosX = 0;
	mousePosY = 0;
	clickedMousePosY = 0;

	// 백버퍼
	backBuffer = new Image;
	backBuffer->Init(WIN_SIZE_X, WIN_SIZE_Y);

	// 배경 이미지
	string FileIndex;

	for (int i = 0; i < 8; i++)
	{
		FileIndex = "Image/KOF_BgImg/0000" + to_string(i + 1) + ".bmp";
		backGround[i] = new Image;
		backGround[i]->Init(FileIndex.c_str(), 2700, 900);
	}

	andy = new Andy;

	andy->Init();

	mapFrameTimer = 0;
}

void MainGame::Update()
{
	mapFrameTimer++;

	if (mapFrameTimer % 20 == 0) {
		mapFrame++;
		if (mapFrame == 8) mapFrame = 0;
	}

	andy->Update();

	InvalidateRect(g_hWnd, NULL, false);
}

void MainGame::Render(HDC hdc)
{
	HDC hBackBufferDC = backBuffer->GetMemDC();

	backGround[mapFrame]->Render(hBackBufferDC);

	andy->Render(hBackBufferDC);

	backBuffer->Render(hdc);
}

void MainGame::Release()
{
	SAFE_RELEASE(backBuffer);
	andy->Release();
	SAFE_RELEASE(andy);
	for (int i = 0; i < 8; i++)
	{
		if (backGround[i])
		{
			backGround[i]->Release();
			delete backGround[i];
			backGround[i] = nullptr;
		}
	}
	// 타이머 객체 삭제
	KillTimer(g_hWnd, 0);
}


LRESULT MainGame::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	switch (iMessage)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_SPACE:
			break;
		case VK_UP:
			break;
		case VK_DOWN:
			break;
		case VK_LEFT:
			break;
		case VK_RIGHT:
			break;
		}
		break;

	case WM_LBUTTONDOWN:

		break;
	case WM_LBUTTONUP:
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_MOUSEMOVE:

		break;
	}
	return DefWindowProc(hWnd, iMessage, wParam, lParam);
}
