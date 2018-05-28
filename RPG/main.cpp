#include "GameWnd.h"
GameWnd * game;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return game->MyWndProc(hWnd, uMsg, wParam, lParam);
}
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	
	game = new GameWnd();
	game->CreateWnd(hInstance, 600, 800);
	game->Run();
	return 0;

}
