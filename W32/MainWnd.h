#pragma once
#include "framework.h"

class CMainWnd
{ 
	public :
		HWND m_hWnd ; 
	public :
		static CMainWnd *g_pWndMain ; 
	public :
		CMainWnd() ; 
		~CMainWnd() ; 
	protected : 
		ATOM Register(HINSTANCE hInstance) ; 
	public :
		BOOL Init(int nCmdShow) ; 
		LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) ; 
	public :
		LRESULT OnCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) ; 
		LRESULT OnPaint(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) ; 
		LRESULT OnDestory(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) ; 
} ;

