#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")



int CDECL MessageBoxPrintf(const CHAR * szCaption , const TCHAR *szFormat , ...)
{
	TCHAR szBuffeer[1024] ;
	va_list pArgList ;

	va_start(pArgList , szFormat) ;
	_vsntprintf(szBuffeer , sizeof(szBuffeer) / sizeof(TCHAR) , szFormat , pArgList) ;
	return MessageBox(NULL , szBuffeer , szCaption , 0) ;	
}

LRESULT CALLBACK WndProc(HWND hwnd , UINT message , WPARAM wParam  , LPARAM lParam) 
{
	HDC hdc ;
	PAINTSTRUCT ps ;
	RECT rect ;
	switch(message) {
		// case WM_CREATE:
		// 	PlaySound(TEXT("hellowin.wav") ,  NULL , SND_FILENAME | SND_ASYNC) ;
		// 	return 0 ;
		
		case WM_PAINT :
			hdc = BeginPaint(hwnd , &ps) ;
			GetClientRect(hwnd , &rect) ;
			DrawText(hdc , TEXT("hello jie ") , -1 , &rect , DT_SINGLELINE | DT_CENTER | DT_VCENTER);
			EndPaint(hwnd , &ps) ;
			return 0 ;

		case WM_DESTROY:
			PostQuitMessage(0) ;
			return 0 ;
	}
	return DefWindowProc(hwnd , message , wParam , lParam) ;
}

int WINAPI WinMain(HINSTANCE hInstance , HINSTANCE hPrevInstance , 
					PSTR szCmdLine , int iCmdShow)
{

	//WINUPSERAPI int WINAPI MessageBoxW(HWND hWnd , LPCWSTR lpText ,
	// LPCWSTR lpCaption , UINT uType) ;

	// int sprintf(char *szBuffeer , const char *szFormat , ...) ;
	// 将格式化结果标准输出入szBuffer , 该函式返回该字串的长度
	int cxScreen , cyScreen ;

	static TCHAR szAppName[] = TEXT("hello Win") ;
	HWND hwnd ;
	MSG msg ;
	WNDCLASS wndclass ;

	wndclass.style = CS_HREDRAW | CS_VREDRAW ;
	wndclass.lpfnWndProc = WndProc ;
	wndclass.cbClsExtra = 0 ;
	wndclass.cbWndExtra = 0 ;
	wndclass.hInstance = hInstance ;
	wndclass.hIcon = LoadIcon(NULL , IDI_APPLICATION) ;
	//wndclass.hbrBackground = CreateSolidBrush(RGB(255,0,0)) ;
	wndclass.lpszMenuName = NULL ;
	wndclass.lpszClassName = szAppName ;

	if(!RegisterClass(&wndclass)){
		MessageBox(NULL , TEXT("This program requires Windows NT!") ,
			szAppName , MB_ICONERROR) ;
		return 0 ;
	}
	hwnd = CreateWindow(szAppName , 
				TEXT("the hello program") ,
				WS_OVERLAPPEDWINDOW,
				CW_USEDEFAULT,
				CW_USEDEFAULT ,
				CW_USEDEFAULT,
				CW_USEDEFAULT,
				NULL,
				NULL,
				hInstance , 
				NULL ) ;
	ShowWindow(hwnd ,iCmdShow) ;
	UpdateWindow(hwnd) ;
	while(GetMessage(&msg , NULL , 0 , 0)){
		TranslateMessage(&msg) ;
		DispatchMessage(&msg) ;
	}





	cxScreen = GetSystemMetrics(SM_CXSCREEN) ;
	cyScreen = GetSystemMetrics(SM_CYSCREEN) ;
	MessageBoxPrintf(TEXT("ScrnSize") , TEXT("The screen is %i pixels \
		wide by %i pixels high .") , cxScreen ,cyScreen) ;
	MessageBox(NULL,TEXT("hello world"),TEXT("MessageBox"),0) ;
	char szBuffeer[100] ;
	sprintf(szBuffeer,"The sum of % d and %d is %d \n" , 5 , 3 , 5 + 3) ;
	puts(szBuffeer) ;
	return msg.wParam ;
	return 0 ;
}