#include <Windows.h>

// 윈도우 프로시저 함수 : 윈도우로 부터 받은 이벤트를 처리하는 함수 (내가 처리한다)

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)

{
	/*
		윈도우로부터 오는 메세지(명령) 처리
	*/
	switch (msg)
	
	{

	case WM_LBUTTONDOWN:
		
		MessageBox(0, "Hello World", "Hello", MB_OK);
		return 0;

	case WM_KEYDOWN:
		if (VK_ESCAPE == wParam)
		{
			DestroyWindow(hWnd); //파괴하길 허락해주세요~~ 윈도우에게 요청
		}
		break;
	
	//윈도우에서 파괴하는거 허락해 줄게 메세지 날라옴
	case WM_DESTROY:
		PostQuitMessage(0); //파괴해주세요~~ 윈도우에게 요청  (두번에 걸쳐 진행됨)
		break;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);

}

//-----WinMain 함수--------

int WINAPI WinMain(

	HINSTANCE hInstance,	// 현재 응용 프로그램의 메인 핸들

	HINSTANCE hPrevInstance,	// 안쓰임

	PSTR pCmdLine,	// 실행하는데 쓰이는 명령줄 또는 인수

	int nCmdShow	
)


{

	// 윈도우 스타일을 만들고

	WNDCLASS wc;

	wc.style = CS_HREDRAW | CS_VREDRAW;

	wc.lpfnWndProc = WndProc;	// 윈도우 프로시저 함수 등록

	wc.cbClsExtra = 0;

	wc.cbWndExtra = 0;

	wc.hInstance = hInstance;

	wc.hIcon = LoadIcon(0, IDI_APPLICATION);

	wc.hCursor = LoadCursor(0, IDC_ARROW);

	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	wc.lpszMenuName = 0;

	wc.lpszClassName = "2DTileFrameWnd";			// 이 윈도우 스타일의 이름



													// 만든 윈도우 스타일 등록

	if (FALSE == RegisterClass(&wc))

	{

		return 0;

	}



	// 창 핸들(아이디)를 먼저 발급을 받자

	HWND hWnd = CreateWindow(

		"2DTileFrameWnd",	// 사용할 윈도우 스타일 이름. OS에 등록 되어있음.

		"2D Tile Frmae",

		WS_OVERLAPPEDWINDOW,	// 윈도우 스타일

		CW_USEDEFAULT, CW_USEDEFAULT,	// 시작위치 :  x, y

		1024, 768,		// 해상도. 너비/높이

		0,		// 부모 창의 핸들. 사용 안함

		0,		// 메뉴 핸들. 사용 안함

		hInstance,	// OS와 윈도우 연결. OS에서 윈도우를 관리할 수 있다.

		0

	);

	if (NULL == hWnd)
	{
		return 0;

	}



	// hWnd : 하나의 윈도우를 가리키는 핸들(아이디)

	ShowWindow(hWnd, nCmdShow);

	UpdateWindow(hWnd);



	// 이 윈도우가 꺼지지 않고 유지되도록 처리

	//MSG msg;

	//while (-1 != GetMessage(&msg, 0, 0, 0))	// 발생된 메시지가 있으면
	//{

	//	TranslateMessage(&msg);		// 키보드 변환 수행

	//	DispatchMessage(&msg);	// 메시지 창에 배분을 요청한다.

	//}

	MSG msg = { 0 };
	float frameInterval = 1.0 / 60.0f;
	float startTime = timeGetTime() * 0.001f;
	float endTime, frameTime;
	while (WM_QUIT != msg.message)	//application이 종료되기 전까지 계속 실행
	{
		endTime = timeGetTime() * 0.001f;
		frameTime = endTime - startTime;
		//메세지가 있는지 없는지 검사하고 나옴 (Ture, False)
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);		// 키보드 변환 수행
			DispatchMessage(&msg);	// 메시지 창에 배분을 요청한다.
		}
		else
		{
			//todo gameUPdate. 
			if (frameInterval <= frameTime)
			{
				//todo gameUPdate. 60fps
				startTime = timeGetTime() * 0.001f;
				frameTime = 0.0f;
			}
		}

	}


	return 0;

}