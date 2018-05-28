#ifndef _GAMEWND_H_
#define _GAMEWND_H_
#include <windows.h>
#include <atlimage.h>
#include <gl.h>				 
#include <glu.h>
#include <glaux.h>
#include <glut.h>
#include <atlimage.h>
#include <math.h>

class GameWnd {
public:
	int height, width;
	HDC hDC;
	HWND hWnd;
	HGLRC hRC;
	HINSTANCE m_hInstance;
public:
	friend LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
   LRESULT CALLBACK MyWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	bool CreateWnd(HINSTANCE hInstance,int h,int w);
	void SetupPixelFormat(HDC hDC);
	void Render();
	void Run();
};

#endif
