// main.cpp : Defines the entry point for the application.
#include "framework.h"
#include "MainApp.h"
#include "W32.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE /*hPrevInstance*/,
                     _In_ LPWSTR    /*lpCmdLine*/,
                     _In_ int       nCmdShow)
{
    int nResult = 0 ; 
    try
    {
        CMainApp &mainApp = CMainApp::GetInstance(hInstance) ; 
        nResult = mainApp.Run(hInstance, nCmdShow) ; 
        CMainApp::Release() ; 
    }
    catch(...)
    {

    }
    return nResult ; 
}

