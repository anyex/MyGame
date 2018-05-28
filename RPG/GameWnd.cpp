#include "GameWnd.h"


bool GameWnd::CreateWnd(HINSTANCE hInstance,int h,int w)
{
	WNDCLASSEX wnd = { 0 };
	wnd.cbClsExtra = 0;
	WNDCLASSEX			windowsClass = { 0 };	//������
	height = h;
	width = w;

	windowsClass.cbSize = sizeof(WNDCLASSEX);
	windowsClass.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	windowsClass.lpfnWndProc = WndProc;
	windowsClass.cbClsExtra = 0;
	windowsClass.cbWndExtra = 0;
	windowsClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);//Ĭ��ͼ��
	windowsClass.hInstance = hInstance;
	windowsClass.hCursor = LoadCursor(NULL, IDC_ARROW);//Ĭ�����ָ��
	windowsClass.lpszClassName = "MyGame";
	windowsClass.hIconSm = LoadIcon(NULL, IDI_WINLOGO);

	//ע�ᴰ��
	if (!RegisterClassEx(&windowsClass))
	{
		return 0;
	}

	hWnd = CreateWindowEx(NULL, "MyGame", "��Ϸ����", WS_OVERLAPPEDWINDOW | WS_SYSMENU | WS_VISIBLE,
		0, 0,	//x,y����ֵ
		width, height,		//���ڿ�Ⱥ͸߶�
		NULL,			//ָ�򸸴��ڵľ��
		NULL,			//ָ��˵��ľ��
		hInstance,		//Ӧ�ó���ʵ��
		NULL);			//�޸��Ӳ���
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

		glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
		glClearDepth(1.0f);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_SMOOTH);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
		
		break;

	case WM_CLOSE://�رմ���
		wglMakeCurrent(hDC, NULL);//ȡ��ѡ���Ļ��ƻ�����������ɾ��
		wglDeleteContext(hRC);
		PostMessage(hWnd, WM_QUIT, 0, 0);
		//PostQuitMessage(0);//����WM_QUIT��Ϣ����Ϣ����
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
		//���������ߴ�
		glViewport(0, 0, width, height);

		glMatrixMode(GL_PROJECTION);//�趨ͶӰ����
		glLoadIdentity();//��λͶӰ����
						 //���㴰�ڳߴ����

		gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 1.0f, 1000.0f);
		glMatrixMode(GL_MODELVIEW);//�趨ģ����ͼ����
		glLoadIdentity();//��λģ�;�����ͼ

		break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void GameWnd::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);


	
	
	gluLookAt(0, 1.5, 5,
		0 , 1.5 , 1 ,
		0, 1, 0);

	glPushMatrix();

	glTranslatef(0, 0, -5);
	glRotatef(30, 0, 1, 0);
	//	glColor3f(0.0, 1.0, 0.0); 
	//����

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex3i(0, 0, 0);
	glTexCoord2f(0, 1);glVertex3i(0, 1, 0);
	glTexCoord2f(1, 1);glVertex3i(1, 1, 0);
	glTexCoord2f(1, 0);glVertex3i(1, 0, 0);
	glEnd();
	//����

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex3i(0, 0, -1);
	glTexCoord2f(0, 1);glVertex3i(0, 1, -1);
	glTexCoord2f(1, 1);glVertex3i(1, 1, -1);
	glTexCoord2f(1, 0);glVertex3i(1, 0, -1);
	glEnd();

	//����

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex3i(0, 1, 0);
	glTexCoord2f(0, 1);glVertex3i(1, 1, 0);
	glTexCoord2f(1, 1);glVertex3i(1, 1, -1);
	glTexCoord2f(1, 0);glVertex3i(0, 1, -1);
	glEnd();
	//����

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex3i(0, 0, 0);
	glTexCoord2f(0, 1);glVertex3i(1, 0, 0);
	glTexCoord2f(1, 1);glVertex3i(1, 0, -1);
	glTexCoord2f(1, 0);glVertex3i(0, 0, -1);
	glEnd();
	//����

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex3i(0, 0, 0);
	glTexCoord2f(0, 1);glVertex3i(0, 1, 0);
	glTexCoord2f(1, 1);glVertex3i(0, 1, -1);
	glTexCoord2f(1, 0);glVertex3i(0, 0, -1);
	glEnd();

	//����

	glBegin(GL_QUADS);
	glTexCoord2f(0, 0);glVertex3i(1, 0, 0);
	glTexCoord2f(0, 1);glVertex3i(1, 1, 0);
	glTexCoord2f(1, 1);glVertex3i(1, 1, -1);
	glTexCoord2f(1, 0);glVertex3i(1, 0, -1);
	glEnd();
	glPopMatrix();

	glFlush();
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_LIGHTING);

	glPushAttrib(GL_CURRENT_BIT);
	glPushMatrix();

	glTranslatef(0.0, 0.0, 0.0);
	glColor3f(0.0f, 0.0f, 1.0f);
	for (float i = -50;i <= 50;i += 1)
	{
		glBegin(GL_LINES);
		glVertex3f(-50, 0, i);
		glVertex3f(50, 0, i);

		glVertex3f(i, 0, -50);
		glVertex3f(i, 0, 50);
		glEnd();

	}
	glPopAttrib();
	glPopMatrix();
}
void GameWnd::SetupPixelFormat(HDC hdc)
{
	int nPixelFormat;//���ظ�ʽ
	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),//���ݽṹ��С
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

	//ѡ����ƥ������ظ�ʽ����������ֵ
	nPixelFormat = ChoosePixelFormat(hdc, &pfd);
	//�����豸�����ظ�ʽ
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