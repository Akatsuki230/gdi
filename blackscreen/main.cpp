#include <Windows.h>
#pragma comment(lib, "gdiplus.lib")

// makes screen black when program is run

int main() {
    auto window = GetConsoleWindow();
    ShowWindow(window, SW_HIDE); // hide console window

    for (int i = 0; i < 10; ++i) { // this fixes everything dont ask
        int w = GetSystemMetrics(SM_CXSCREEN);
        int h = GetSystemMetrics(SM_CYSCREEN);
        HDC screenDC = GetDC(nullptr);
        HDC memDC = CreateCompatibleDC(screenDC);
        HBITMAP memBM = CreateCompatibleBitmap(screenDC, w, h);
        HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
        SelectObject(memDC, memBM);
        SelectObject(memDC, blackBrush);
        Rectangle(memDC, 0, 0, w, h);
        BitBlt(screenDC, 0, 0, w, h, memDC, 0, 0, SRCCOPY);
        DeleteObject(blackBrush);
        DeleteObject(memBM);
        DeleteDC(memDC);
        ReleaseDC(nullptr, screenDC);
    }
    return 0;
}
