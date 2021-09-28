#pragma once
#include "Config.h"
#include <Windows.h>
#include <string>
#include "andy.h"
static int mapFrame = 0;

class Image;
class Terry;
class MainGame
{
private:
	// Ÿ�̸�
	HANDLE hTimer;

	// �����
	Image* backBuffer;

	// ��� �̹���
	Image* backGround[8] = {};
	int mapFrameTimer;

	// �̿���
	//	Iori* iori;
	Andy* andy;
	// �׸�
	Terry* terry;
public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};