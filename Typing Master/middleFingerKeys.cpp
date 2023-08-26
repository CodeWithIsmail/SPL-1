/*#include"set_cursor.h"
#include "dataset.h"
#include"startMenu.h"
#include"middleFingerKeys.h"
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>*/
#include "AllHeaderFile.h"

void reviewMiddleFingerKeys();
void lessonNew3(int x);
using namespace std;
char dataset3[10]= {'e','i','c','a','s','d','f','j','k','l'};

void lessonNew3(int x)
{
    system("cls");
    gotoxy(40,5);
    cout<<"Lesson 3: Focus on the middle finger keys"<<endl;
    gotoxy(40,7);
    cout<<"3.1 -> Review Middle Finger keys: E I C"<<endl;
    gotoxy(40,9);
    cout<<"3.2 -> Key Drills"<<endl;
    gotoxy(40,11);
    cout<<"3.3 -> Word Drills"<<endl;
    gotoxy(40,15);
    cout<<"Select lesson: (1-3) or 0 to return home or any key to exit"<<endl;

    char lesson=getch();
    system("cls");
    switch(lesson)
    {
    case '0':
        startMenu(0);
        break;
    case '1':
        reviewMiddleFingerKeys();
        break;
    case '2':
        keyDrill(dataset3,10,3,2);
        break;
    case '3':
        wordDrill(dataset3,10,3,3);
        break;
    default:
        exit(0);
    }
}

void reviewMiddleFingerKeys()
{
    gotoxy(10,5);
    cout<<"In this lesson, you will learn E C I, the middle finger keys.";
    gotoxy(10,9);
    cout<<"Press any key to continue.";
    char c=getch();
    system("cls");

    lesson('e');
    lesson('c');
    lesson('i');

    gotoxy(10,5);
    cout<<"Now you can start the key drill.";
    gotoxy(10,8);
    cout<<"Press any key to continue.";
    c=getch();
    system("cls");

    keyDrill(dataset3,10,3,3);
}
