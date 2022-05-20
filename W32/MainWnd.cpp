#include "MainApp.h"
#include "Resource.h"
#include "MainWnd.h"

CMainWnd *CMainWnd::g_pWndMain = nullptr ; 

static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
    return CMainWnd::g_pWndMain->WndProc(hWnd, message, wParam, lParam) ;
}

CMainWnd::CMainWnd()
{
    m_hWnd = NULL ; 
    g_pWndMain = this ; 
}

CMainWnd::~CMainWnd()
{

}

ATOM CMainWnd::Register(HINSTANCE hInstance) 
{
    WNDCLASSEXW wcex ;
    wcex.cbSize         = sizeof(WNDCLASSEX) ;
    wcex.style          = CS_HREDRAW | CS_VREDRAW ;
    wcex.lpfnWndProc    = ::WndProc ;
    wcex.cbClsExtra     = 0 ;
    wcex.cbWndExtra     = 0 ;
    wcex.hInstance      = hInstance ;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_W32)) ;
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW) ;
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1) ;
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_W32) ;
    wcex.lpszClassName  = _T("MainWnd") ;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL)) ;
    return ::RegisterClassExW(&wcex) ;
}

BOOL CMainWnd::Init(int nCmdShow) 
{
    HINSTANCE hInstance = CMainApp::GetInstance().m_hInstance ; 
    Register(hInstance) ; 
    m_hWnd = ::CreateWindowW(_T("MainWnd"), _T("Test"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, 
        nullptr, nullptr, hInstance, nullptr) ;
    if(!m_hWnd)
    {
        return FALSE ; 
    }
   ::ShowWindow(m_hWnd, nCmdShow) ;
   ::UpdateWindow(m_hWnd) ;
   return TRUE ;
}

LRESULT CALLBACK CMainWnd::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
	switch(message)
    {
        case WM_COMMAND :
        {
            OnCommand(hWnd, message, wParam, lParam) ; 
            break ;
        }
        case WM_PAINT :
        {
            OnPaint(hWnd, message, wParam, lParam) ; 
            break ; 
        }
        case WM_DESTROY :
        {   
            OnDestory(hWnd, message, wParam, lParam) ; 
            break ;
        }
        default:
        {
            return ::DefWindowProc(hWnd, message, wParam, lParam) ;
        }
    }
    return 0 ;
}

//      message handlers

LRESULT CMainWnd::OnCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
    return 0 ; 
}

LRESULT CMainWnd::OnPaint(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
    PAINTSTRUCT ps ;
    HDC hdc = ::BeginPaint(hWnd, &ps) ;
    // todo 
    EndPaint(hWnd, &ps) ;
    return 0 ; 
}

LRESULT CMainWnd::OnDestory(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) 
{
    ::PostQuitMessage(0) ;
    return 0 ; 
}