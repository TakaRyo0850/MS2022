/*==================================================================================================
    DirectX11
    [window.h]
    ・ウィンドウ生成
----------------------------------------------------------------------------------------------------
    2021.09.27 @Author WATARU FUKUOKA
====================================================================================================
    History
        210927 作成

/*================================================================================================*/
#pragma once
#include <windows.h>

#define CLASS_NAME      "MS2022AppClass"
#define WINDOW_NAME     "MS2022"
#define SCREEN_WIDTH    (1920)      // ウインドウの幅
#define SCREEN_HEIGHT   (1080)      // ウインドウの高さ


HWND GetWindow();
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);