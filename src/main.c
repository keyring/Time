
#include <windows.h>
#include <vlc/vlc.h>
#define NK_IMPLEMENTATION
#include "nuklear.h"

//int main()
//{
	//libvlc_instance_t *vlc_instance;
	//libvlc_media_player_t *media_player;
	//libvlc_media_t *media;

	//int wait_time = 1000 * 20;

	//vlc_instance = libvlc_new(0, NULL);
	////media = libvlc_media_new_location(vlc_instance, "rtsp://184.72.239.149/vod/mp4:BigBuckBunny_175k.mov");
	//media = libvlc_media_new_path(vlc_instance, "media\\BigBuckBunny_320x180_Trim.mp4");
	//media_player = libvlc_media_player_new_from_media(media);

	//libvlc_media_release(media);

	//libvlc_media_player_play(media_player);
	//
	//Sleep(wait_time);

	//libvlc_media_player_stop(media_player);

	//libvlc_media_player_release(media_player);

	//libvlc_release(vlc_instance);

	//return 0;

//}

static
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, PWSTR pCmdLine, int nCmdShow)
{
	const wchar_t CLASS_NAME[] = L"Tine Base Window Class";

	WNDCLASS wc = { 0 };

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(
		0,
		CLASS_NAME,
		L"Tine",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hwnd){
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);

	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

