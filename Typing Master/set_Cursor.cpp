#include"set_cursor.h"
#include<windows.h>
#include<bits/stdc++.h>
using namespace std;

HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorPoint;

void gotoxy(int x,int y)
{
    cursorPoint.X=x;
    cursorPoint.Y=y;
    SetConsoleCursorPosition(console,cursorPoint);
}
