#pragma once
#include "framework.h"
#include "MainWnd.h"

class CMainApp
{ 
	private :	
		CMainWnd m_wndMain ; 
	public :
		HINSTANCE m_hInstance ;
	public :
		CMainApp(HINSTANCE hInstance) ;
		~CMainApp() ;
	public :
		int Run(HINSTANCE hInstance, int nCmdShow) ; 
	public :
		static CMainApp &GetInstance(HINSTANCE hInstance = nullptr) ; 	
		static void Release() ; 
} ;

