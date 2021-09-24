#include "Image.h"
#include "Config.h"
HRESULT Image::Init(int width, int height)
{
	HDC hdc = GetDC(g_hWnd);

	// 빈 비트맵 생성
	imageInfo = new IMAGE_INFO;
	imageInfo->width = width;
	imageInfo->height = height;
	imageInfo->loadType = ImageLoadType::Empty;
	imageInfo->hBitmap = CreateCompatibleBitmap(hdc, width, height);
	imageInfo->hMemDc = CreateCompatibleDC(hdc);	// 새로 생성된 DC 
											// 기본적으로 Bitmap에 연결되어 있다.
	imageInfo->hOldBit =
		(HBITMAP)SelectObject(imageInfo->hMemDc, imageInfo->hBitmap);

	ReleaseDC(g_hWnd, hdc);

	if (imageInfo->hBitmap == NULL)	// 비트맵 생성에 실패했을 때
	{
		Release();
		return E_FAIL;
	}

	return S_OK;
}

HRESULT Image::Init(const char* fileName, int width, int height,
	bool isTrans/* = false*/, COLORREF transColor/* = NULL*/)
{
	HDC hdc = GetDC(g_hWnd);

	imageInfo = new IMAGE_INFO;
	imageInfo->width = width;
	imageInfo->height = height;
	imageInfo->loadType = ImageLoadType::File;
	imageInfo->hBitmap = (HBITMAP)LoadImage(g_hInstance, fileName, IMAGE_BITMAP, width, height,
		LR_LOADFROMFILE);
	imageInfo->hMemDc = CreateCompatibleDC(hdc);	// 새로 생성된 DC 
											// 기본적으로 Bitmap에 연결되어 있다.
	imageInfo->hOldBit =
		(HBITMAP)SelectObject(imageInfo->hMemDc, imageInfo->hBitmap);

	ReleaseDC(g_hWnd, hdc);

	this->isTransparent = isTrans;
	this->transColor = transColor;

	if (imageInfo->hBitmap == NULL)
	{
		Release();
		return E_FAIL;
	}

	return S_OK;
}

HRESULT Image::Init(const char* fileName, int width, int height, int maxFrameX, int maxFrameY, bool isTrans, COLORREF transColor)
{
	HDC hdc = GetDC(g_hWnd);

	imageInfo = new IMAGE_INFO;
	imageInfo->width = width;
	imageInfo->height = height;
	imageInfo->loadType = ImageLoadType::File;
	imageInfo->hBitmap = (HBITMAP)LoadImage(g_hInstance, fileName, IMAGE_BITMAP, width, height,
		LR_LOADFROMFILE);
	imageInfo->hMemDc = CreateCompatibleDC(hdc);	// 새로 생성된 DC 
											// 기본적으로 Bitmap에 연결되어 있다.
	imageInfo->hOldBit =
		(HBITMAP)SelectObject(imageInfo->hMemDc, imageInfo->hBitmap);

	ReleaseDC(g_hWnd, hdc);

	this->isTransparent = isTrans;
	this->transColor = transColor;

	imageInfo->maxFrameX = maxFrameX;
	imageInfo->maxFrameY = maxFrameY;
	imageInfo->currFrameX = 0;
	imageInfo->currFrameY = 0;
	imageInfo->frameWidth = imageInfo->width / maxFrameX;
	imageInfo->frameHeight = imageInfo->height / maxFrameY;


	if (imageInfo->hBitmap == NULL)
	{
		Release();
		return E_FAIL;
	}

	return S_OK;
}

void Image::Release()
{
	if (imageInfo)
	{
		SelectObject(imageInfo->hMemDc, imageInfo->hOldBit);
		DeleteObject(imageInfo->hBitmap);
		DeleteDC(imageInfo->hMemDc);

		delete imageInfo;
		imageInfo = nullptr;
	}
}

void Image::Render(HDC hdc)
{
	GdiTransparentBlt(
		hdc,
		0,
		0,
		WIN_SIZE_X, WIN_SIZE_Y,

		imageInfo->hMemDc,
		0,
		0,
		imageInfo->width, imageInfo->height,
		RGB(255, 0, 255)
	);
}

void Image::Render(HDC hdc, int destX, int destY)
{
	if (isTransparent)
	{
		GdiTransparentBlt(
			hdc,
			destX - (imageInfo->width / 2),
			destY - (imageInfo->height / 2),
			imageInfo->width, imageInfo->height,

			imageInfo->hMemDc,
			0, 0,
			imageInfo->width, imageInfo->height,
			transColor
		);
	}
	else
	{
		BitBlt(hdc,				// 복사 목적지 DC
			destX - (imageInfo->width / 2),				// 복사될 비트맵의 시작 위치 x
			destY - (imageInfo->height / 2),			// 복사될 비트맵의 시작 위치 y
			imageInfo->width,	// 원본 복사할 가로 크기
			imageInfo->height,	// 원본 복사할 세로 크기
			imageInfo->hMemDc,	// 원본 DC
			0,					// 원본 비트맵 복사 시작 위치 x
			0,					// 원본 비트맵 복사 시작 위치 y
			SRCCOPY);			// 복사 옵션
	}

}

void Image::Render(HDC hdc, int destX, int destY, int frameX, int frameY)
{
	if (isTransparent)
	{
		GdiTransparentBlt(
			hdc,																				// 그릴 곳
			destX - (imageInfo->frameWidth / 2),								// 그릴 화면의 시작지점 x
			destY - (imageInfo->frameHeight / 2),								// 그릴 화면의 시작지점 x
			(imageInfo->frameWidth), (imageInfo->frameHeight),			// 화면에 그려질 그림의 크기

			imageInfo->hMemDc,														// 원본 그림의 DC(그림 원본)	
			(imageInfo->frameWidth) * frameX,									// 원본 그림에서 복사를 시작 할 위치							
			(imageInfo->frameHeight) * frameY,
			(imageInfo->frameWidth), (imageInfo->frameHeight),			// 원본 그림에서 복사해 올 크기	
			transColor																		// 제외할 색
		);
	}
	else
	{
		BitBlt(hdc,				// 복사 목적지 DC
			destX - (imageInfo->width / 2),				// 복사될 비트맵의 시작 위치 x
			destY - (imageInfo->height / 2),			// 복사될 비트맵의 시작 위치 y
			imageInfo->width,	// 원본 복사할 가로 크기
			imageInfo->height,	// 원본 복사할 세로 크기
			imageInfo->hMemDc,	// 원본 DC
			0,					// 원본 비트맵 복사 시작 위치 x
			0,					// 원본 비트맵 복사 시작 위치 y
			SRCCOPY);			// 복사 옵션
	}
}


void Image::Render(HDC hdc, int destX, int destY, int frameX, int frameY, int characterSizeX, int characterSizeY)
{
	if (isTransparent)
	{
		GdiTransparentBlt(
			hdc,																				// 그릴 곳
			destX - (imageInfo->frameWidth / 2),								// 그릴 화면의 시작지점 x
			destY - (imageInfo->frameHeight / 2),								// 그릴 화면의 시작지점 x
			characterSizeX, characterSizeY,										// 화면에 그려질 그림의 크기

			imageInfo->hMemDc,														// 원본 그림의 DC(그림 원본)	
			(imageInfo->frameWidth) * frameX,									// 원본 그림에서 복사를 시작 할 위치							
			(imageInfo->frameHeight) * frameY,
			(imageInfo->frameWidth), (imageInfo->frameHeight),			// 원본 그림에서 복사해 올 크기	
			transColor																		// 제외할 색
		);
	}
	else
	{
		BitBlt(hdc,				// 복사 목적지 DC
			destX - (imageInfo->width / 2),				// 복사될 비트맵의 시작 위치 x
			destY - (imageInfo->height / 2),			// 복사될 비트맵의 시작 위치 y
			imageInfo->width,	// 원본 복사할 가로 크기
			imageInfo->height,	// 원본 복사할 세로 크기
			imageInfo->hMemDc,	// 원본 DC
			0,					// 원본 비트맵 복사 시작 위치 x
			0,					// 원본 비트맵 복사 시작 위치 y
			SRCCOPY);			// 복사 옵션
	}
}

