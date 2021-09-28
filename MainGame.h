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
	// 타이머
	HANDLE hTimer;

	// 백버퍼
	Image* backBuffer;

	// 배경 이미지
	Image* backGround[8] = {};
	int mapFrameTimer;

	// 이오리
	//	Iori* iori;
	Andy* andy;
	// 테리
	Terry* terry;
public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};