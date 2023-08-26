/*#include"set_cursor.h"
#include "dataset.h"
#include"startMenu.h"
#include"indexFingerKeys.h"
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>*/
#include "AllHeaderFile.h"

void reviewIndexFingerKeys();
void lessonNew2(int x);
using namespace std;
char dataset2[10]= {'r','t','y','u','g','h','v','b','n','m'};

void lessonNew2(int x)
{
    system("cls");
    gotoxy(40,5);
    cout<<"Lesson 2: Focus on the index finger keys"<<endl;
    gotoxy(40,7);
    cout<<"2.1 -> Review Index Finger keys"<<endl;
    gotoxy(40,9);
    cout<<"2.2 -> Key Drills"<<endl;
    gotoxy(40,11);
    cout<<"2.3 -> Word Drills"<<endl;
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
        reviewIndexFingerKeys();
        break;
    case '2':
        keyDrill(dataset2,10,2,2);
        break;
    case '3':
        wordDrill(dataset2,1,2,3);
        break;
    default:
        exit(0);
    }
}

void reviewIndexFingerKeys()
{
    gotoxy(10,5);
    cout<<"In this lesson, you will R T Y U G H V B N M, the index finger keys.";
    gotoxy(10,9);
    cout<<"Press any key to continue.";
    char c=getch();
    system("cls");

    lesson('r');
    lesson('t');
    lesson('y');
    lesson('u');
    lesson('g');
    lesson('h');
    lesson('v');
    lesson('b');
    lesson('n');
    lesson('m');

    gotoxy(10,5);
    cout<<"Now you can start the key drill.";
    gotoxy(10,8);
    cout<<"Press any key to continue.";
    c=getch();
    system("cls");

    keyDrill(dataset2,10,2,3);
}
