/*#include "set_cursor.h"
#include<windows.h>
#include<bits/stdc++.h>
*/
#include "AllHeaderFile.h"
using namespace std;

HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorPoint;

void gotoxy(int x,int y)
{
    cursorPoint.X=x;
    cursorPoint.Y=y;
    SetConsoleCursorPosition(console,cursorPoint);
}

void setColor(int colorNum)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colorNum);
}

void setConsoleBackgroundColor(WORD color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFOEX info;
    info.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
    GetConsoleScreenBufferInfoEx(hConsole, &info);

    // Set the background color for the console
    info.ColorTable[0] = color; // Change the background color to the provided color value
    info.wAttributes = (info.wAttributes & 0xFFF0) | (color & 0x000F);

    SetConsoleScreenBufferInfoEx(hConsole, &info);
}




