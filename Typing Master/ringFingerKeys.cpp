#include"set_cursor.h"
#include "dataset.h"
#include"startMenu.h"
#include"ringFingerKeys.h"
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>

void reviewRingFingerKeys();
void lessonNew4(int x);
using namespace std;
char dataset4[10]= {'w','x','o','a','s','d','f','j','k','l'};

void lessonNew4(int x)
{
    system("cls");
    gotoxy(40,5);
    cout<<"Lesson 4: Focus on the Ring finger keys"<<endl;
    gotoxy(40,7);
    cout<<"4.1 -> Review Ring Finger keys: W X O"<<endl;
    gotoxy(40,9);
    cout<<"4.2 -> Key Drills"<<endl;
    gotoxy(40,11);
    cout<<"4.3 -> Word Drills"<<endl;
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
        reviewRingFingerKeys();
        break;
    case '2':
        keyDrill(dataset4,10);
        break;
    case '3':
        wordDrill(dataset4,10);
        break;
    default:
        exit(0);
    }
}

void reviewRingFingerKeys()
{
    gotoxy(10,5);
    cout<<"In this lesson, you will learn W X O, the Ring finger keys.";
    gotoxy(10,9);
    cout<<"Press any key to continue.";
    char c=getch();
    system("cls");

    lesson('w');
    lesson('x');
    lesson('o');

    gotoxy(10,5);
    cout<<"Now you can start the key drill.";
    gotoxy(10,8);
    cout<<"Press any key to continue.";
    c=getch();
    system("cls");

    keyDrill(dataset4,10);
}
