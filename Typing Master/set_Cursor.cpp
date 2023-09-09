#include "AllHeaderFile.h"

HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursorPoint;
void moveCursor(int x,int y)
{
    cursorPoint.X=x;
    cursorPoint.Y=y;
    SetConsoleCursorPosition(console,cursorPoint);
}





