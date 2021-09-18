#pragma once
#include "Config.h"
#include	 <Windows.h>

class Image;
class Iori;
class MainGame
{
private:
	// 타이머
	HANDLE hTimer;

	// UI
	char text[128];

	int mousePosX;
	int mousePosY;
	int clickedMousePosX;
	int clickedMousePosY;

	// 백버퍼
	Image* backBuffer;

	// 배경 이미지
	Image* backGround;

	// 이오리
	Iori* iori;

public:
	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
};