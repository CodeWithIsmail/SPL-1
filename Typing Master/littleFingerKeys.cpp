#include"set_cursor.h"
#include "dataset.h"
#include"startMenu.h"
#include"littleFingerKeys.h"
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>

void reviewLittleFingerKeys();
void lessonNew5(int x);
using namespace std;
char dataset5[10]= {'q','z','p','a','s','d','f','j','k','l'};

void lessonNew5(int x)
{
    system("cls");
    gotoxy(40,5);
    cout<<"Lesson 5: Focus on the Ring finger keys"<<endl;
    gotoxy(40,7);
    cout<<"5.1 -> Review Ring Finger keys: W X O"<<endl;
    gotoxy(40,9);
    cout<<"5.2 -> Key Drills"<<endl;
    gotoxy(40,11);
    cout<<"5.3 -> Word Drills"<<endl;
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
        reviewLittleFingerKeys();
        break;
    case '2':
        keyDrill(dataset5,10);
        break;
    case '3':
        wordDrill(dataset5,10);
        break;
    default:
        exit(0);
    }
}

void reviewLittleFingerKeys()
{
    gotoxy(10,5);
    cout<<"In this lesson, you will learn Q P Z, the Little finger keys.";
    gotoxy(10,9);
    cout<<"Press any key to continue.";
    char c=getch();
    system("cls");

    lesson('q');
    lesson('p');
    lesson('z');

    gotoxy(10,5);
    cout<<"Now you can start the key drill.";
    gotoxy(10,8);
    cout<<"Press any key to continue.";
    c=getch();
    system("cls");

    keyDrill(dataset5,10);
}
