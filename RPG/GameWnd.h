#ifndef _GAMEWND_H_
#define _GAMEWND_H_
#include <windows.h>
#include <GL.H>
#include <GLU.H>
#include <GLUT.H>
#include <GLAUX.H>
#include <glext.h>
#include <math.h>
#include "Texture.h"
#include "Camera.h"
#include "Terrain.h"
#include "Sprite.h"
#define PI 3.1415926
class Texture;
class Camera;
class Terrain;
class Sprite;

class GameWnd {
public:
	int height, width;
	HDC hDC;
	HWND hWnd;
	HGLRC hRC;
	HINSTANCE m_hInstance;
	GLuint a;
	Texture* BoxTexture;
	Texture* Ground;//µÿ√Ê
	unsigned char* image;
	int t_width, t_height;
	Camera* camera;
	Terrain* terrain;
	Texture* background;
	void DrawBox();
	Sprite* back;
public:
	friend LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
   LRESULT CALLBACK MyWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	bool CreateWnd(HINSTANCE hInstance,int h,int w);
	void SetupPixelFormat(HDC hDC);
	void Render();
	void Run();
	void init();
	int oldMouseX, oldMouseY;
	int mouseX, mouseY;
	bool firstMove;
};

#endif
