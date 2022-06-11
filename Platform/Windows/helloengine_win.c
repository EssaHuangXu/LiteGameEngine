#include <windows.h>
#include <windowsx.h>
#include <tchar.h>

// function prototype
LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

//the entry point for any windows program
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    HWND hWnd;

    WNDCLASSEX wc;

    ZeroMemory(&wc, sizeof(WNDCLASSEX));

    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpszClassName = _T("Window");

    RegisterClassEx(&wc);
    
    hWnd = CreateWindowEx(  0,
                            _T("Window"), 
                            _T("Hello Engine!"),
                            WS_OVERLAPPEDWINDOW,
                            300, 300,
                            500, 400,
                            NULL, NULL,
                            hInstance,
                            NULL
                        );
    ShowWindow(hWnd, nCmdShow);


    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    
    return msg.wParam;
}


LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    // sort through and find what code to run for the message given
    switch(message)
    {

        case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            RECT rect = {20, 20, 60, 80};
            HBRUSH brush = (HBRUSH)GetStockObject(BLACK_BRUSH);

            FillRect(hdc, &rect, brush);
            EndPaint(hWnd, &ps);
        } break;
        // this message is read when the window is closed
        case WM_DESTROY:
            {
                // close the application entirely
                PostQuitMessage(0);
                return 0;
            } break;
    }

    // Handle any messages the switch statement didn't
    return DefWindowProc (hWnd, message, wParam, lParam);
}