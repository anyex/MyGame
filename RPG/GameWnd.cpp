#include "GameWnd.h"
#include "LoadRes.h"

bool GameWnd::CreateWnd(HINSTANCE hInstance,int h,int w)
{
	WNDCLASSEX wnd = { 0 };
	wnd.cbClsExtra = 0;
	WNDCLASSEX			windowsClass = { 0 };	//窗口类
	height = h;
	width = w;

	windowsClass.cbSize = sizeof(WNDCLASSEX);
	windowsClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	windowsClass.lpfnWndProc = WndProc;
	windowsClass.cbClsExtra = 0;
	windowsClass.cbWndExtra = 0;
	windowsClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//默认图标
	windowsClass.hInstance = hInstance;
	windowsClass.hCursor = LoadCursor(NULL, IDC_ARROW);//默认鼠标指针
	windowsClass.lpszClassName = "MyGame";
	windowsClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);

	//注册窗口
	if (!RegisterClassEx(&windowsClass))
	{
		return 0;
	}

	hWnd = CreateWindowEx(NULL, "MyGame", "游戏窗口", WS_OVERLAPPEDWINDOW | WS_SYSMENU | WS_VISIBLE,
		0, 0,	//x,y坐标值
		width, height,		//窗口宽度和高度
		NULL,			//指向父窗口的句柄
		NULL,			//指向菜单的句柄
		hInstance,		//应用程序实例
		NULL);			//无附加参数
	if (hWnd == NULL)
	{
		return false;
	}
	UpdateWindow(hWnd);
	ShowWindow(hWnd, SW_SHOW);

	return true;

}
LRESULT CALLBACK GameWnd::MyWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:

		hDC = GetDC(hWnd);
		SetupPixelFormat(hDC);
		hRC = wglCreateContext(hDC);
		wglMakeCurrent(hDC, hRC);
		init();
		glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
		glClearDepth(1.0f);
		glEnable(GL_SMOOTH);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
		
		break;

	case WM_CLOSE://关闭窗口
		wglMakeCurrent(hDC, NULL);//取消选定的绘制环境，并将其删除
		wglDeleteContext(hRC);
		PostMessage(hWnd, WM_QUIT, 0, 0);
		//PostQuitMessage(0);//发送WM_QUIT消息到消息队列
		break;
	case WM_TIMER:
	{
		Render();
		SwapBuffers(hDC);
	}
	break;
	case  WM_SIZE:

		height = HIWORD(lParam);
		width = LOWORD(lParam);

		if (height == 0)
		{
			height = 1;
		}
		//重置视区尺寸
		glViewport(0, 0, width, height);

		glMatrixMode(GL_PROJECTION);//设定投影矩阵
		glLoadIdentity();//复位投影矩阵
						 //计算窗口尺寸比例
		gluPerspective(54.0f, (GLfloat)width / (GLfloat)height, 0.1f, 100.0f);
		glMatrixMode(GL_MODELVIEW);//设定模型视图矩阵
		glLoadIdentity();//复位模型矩阵视图
		break;

	case WM_MOUSEMOVE:

		mouseX = LOWORD(lParam);
		mouseY = LOWORD(lParam);
		if (firstMove)
		{
			oldMouseX = mouseX;
			oldMouseY = mouseY;
			firstMove = false;
		}
		
		camera->pitch += (mouseY - oldMouseY)/1000.0;
		camera->yaw += (mouseX - oldMouseX)/1000.0;

		if (camera->pitch>30.0f)
		{
			camera->pitch = 30.0f;
		}
		if (camera->pitch<-30.0f)
		{
			camera->pitch = -30.0f;
		}
		oldMouseX = mouseX;
		oldMouseY = mouseY;
	
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case 'A':
			camera->moveLeft = true;
			break;
		case 'S':
			camera->moveBack = true;
		    break;
		case 'D':
			camera->moveRight = true;
			break;
		case 'W':
			camera->moveForward = true;
		    break;
	
		}
	
	}
	

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void GameWnd::Render()
{
	
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);//开启纹理
	glEnable(GL_DEPTH_TEST);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//camera->SwitchTo3D();
	camera->Update(0.5);
	glPushMatrix();
	

	//glColor3f(0.0, 1.0, 0.0); 
	terrain->Draw();
	//camera->SwitchTo2D();
	//glRasterPos2f(0, 0);
	//back->Draw();
	glFlush();

}
void GameWnd::SetupPixelFormat(HDC hdc)
{
	int nPixelFormat;//象素格式
	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),//数据结构大小
		1,
		PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		32,
		0,0,0,0,0,0,
		0,
		0,
		0,
		0,0,0,0,
		16,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0,0,0
	};

	//选择最匹配的象素格式，返回索引值
	nPixelFormat = ChoosePixelFormat(hdc, &pfd);
	//设置设备的象素格式
	SetPixelFormat(hdc, nPixelFormat, &pfd);
	

}

void GameWnd::Run() {
	static MSG msg;
	static bool done = true;
	while (done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				done = false;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			Render();
			SwapBuffers(hDC);
		}
	}
}

void GameWnd::init()
{
	BoxTexture = new Texture("image.bmp");	 
 	Ground = new Texture("ground4.png");
	background = new Texture("back.jpg");

	camera = new Camera();
	camera->pos = Vector3(MAP_W*MAP_SCALE/2, 2, -MAP_W*MAP_SCALE / 2);
	camera->view = Vector3(0, -1, -100);
	camera->h = 600;
	camera->w = 800;

	firstMove = true;

	terrain = new Terrain();

	terrain->texID = Ground->textureID;
	terrain->InitTerrain(1);

	back = new Sprite(background);

	back->SetRect(-400, -300, 800, 600);

}

void GameWnd::DrawBox()
{
	//正面
	//glBindTexture(GL_TEXTURE_2D, BoxTexture->textureID);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0, 0.0);glVertex3f(0, 0, 0);
	glTexCoord2f(0.0, 1.0);glVertex3f(0, 1, 0);
	glTexCoord2f(1.0, 1.0);glVertex3f(1, 1, 0);
	glTexCoord2f(1.0, 0.0);glVertex3f(1, 0, 0);
	glEnd();
	//后面

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex3f(0, 0, -1);
	glTexCoord2f(0, 1);glVertex3f(0, 1, -1);
	glTexCoord2f(1, 1);glVertex3f(1, 1, -1);
	glTexCoord2f(1, 0);glVertex3f(1, 0, -1);
	glEnd();

	//上面

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex3f(0, 1, 0);
	glTexCoord2f(0, 1);glVertex3f(1, 1, 0);
	glTexCoord2f(1, 1);glVertex3f(1, 1, -1);
	glTexCoord2f(1, 0);glVertex3f(0, 1, -1);
	glEnd();
	//下面


	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1);glVertex3f(1, 0, 0);
	glTexCoord2f(1, 1);glVertex3f(1, 0, -1);
	glTexCoord2f(1, 0);glVertex3f(0, 0, -1);
	glEnd();
	//左面

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1);glVertex3f(0, 1, 0);
	glTexCoord2f(1, 1);glVertex3f(0, 1, -1);
	glTexCoord2f(1, 0);glVertex3f(0, 0, -1);
	glEnd();

	//右面

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex3f(1, 0, 0);
	glTexCoord2f(0, 1);glVertex3f(1, 1, 0);
	glTexCoord2f(1, 1);glVertex3f(1, 1, -1);
	glTexCoord2f(1, 0);glVertex3f(1, 0, -1);
	glEnd();
	glPopMatrix();
}