#pragma once
#include <Windows.h>
#include <math.h>
#include <iostream>

using namespace std;

#define WIN_START_POS_X	35
#define WIN_START_POS_Y	10
#define WIN_SIZE_X	900
#define WIN_SIZE_Y	300

#define SAFE_RELEASE(p)	{ if (p) { p->Release(); delete p; p = nullptr; } }

enum MoveDir { Left, Right, Up, Down };
enum AttackType {SH, BH, SF, BF};
extern HWND g_hWnd;
extern HINSTANCE g_hInstance;