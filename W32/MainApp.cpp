#include "Resource.h"
#include "MainApp.h"

static CMainApp *g_pMainApp = nullptr ; 

CMainApp::CMainApp(HINSTANCE hInstance)
{
	m_hInstance = hInstance ; 
}

CMainApp::~CMainApp()
{

}

int CMainApp::Run(HINSTANCE hInstance, int nCmdShow)
{
	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_W32)) ;
    MSG msg ;
	m_wndMain.Init(nCmdShow) ; // Register class, 
    while(::GetMessage(&msg, nullptr, 0, 0))
    {
        if(!::TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            ::TranslateMessage(&msg) ; 
            ::DispatchMessage(&msg) ;
        }
    }
    return (int)msg.wParam ;
}

//		static

CMainApp &CMainApp::GetInstance(HINSTANCE hInstance)
{
	if(g_pMainApp == nullptr)
	{
		g_pMainApp = new CMainApp(hInstance) ; 
	}
	return *g_pMainApp ; 
}

void CMainApp::Release()
{
	if(g_pMainApp != nullptr)
	{
		delete g_pMainApp ; 
		g_pMainApp = nullptr ; 
	}
}
