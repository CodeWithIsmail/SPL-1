#include"StartMenu.h"
#include"set_cursor.h"
#include"TypingTutorial.h"

#include<windows.h>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;

void TypingTutorial(int x)
{
    system("cls");

    gotoxy(40,4);
    cout<<"LESSONS:"<<endl;
    gotoxy(40,7);
    cout<<"1. Focus on the Home Row";
    gotoxy(40,9);
    cout<<"2. Focus on the Index Finger keys";
    gotoxy(40,11);
    cout<<"3. Focus on the Middle Finger keys";
    gotoxy(40,13);
    cout<<"4. Focus on the Ring Finger keys";
    gotoxy(40,15);
    cout<<"5. Focus on the Little Finger keys";
    gotoxy(40,17);
    cout<<"6. Common words";

    gotoxy(40,20);
    cout<<"Select your lesson (1-6) or Enter 0 to return Home or any key to exit:"<<endl;

    char ch;
    ch=getch();
    system("cls");

    switch(ch)
    {
    case '0':
        startMenu(0);
        break;
    case '1':
        lessonNew1(0);
        break;
    case '2':
        lessonNew2(0);
        break;
    case '3':
        lessonNew3(0);
        break;
    case '4':
        lessonNew4(0);
        break;
    case '5':
        lessonNew5(0);
        break;
    case '6':
        mostCommonWord(0);
        break;
    default :
        exit(0);
    }
}
