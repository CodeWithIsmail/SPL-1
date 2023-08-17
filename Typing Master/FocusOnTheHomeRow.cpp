#include"set_cursor.h"
#include "dataset.h"
#include"startMenu.h"
#include"FocusOnTheHomeRow.h"
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>

void reviewHomeRow();
void lesson1(int x);
void SpeedBuildingCourseDescription();
using namespace std;
char dataset1[7]= {'a','s','d','f','j','k','l'};
void lessonNew1(int x)
{
    system("cls");
    gotoxy(40,5);
    cout<<"Lesson 1: Focus on the Home row"<<endl;
    cout<<endl;
    gotoxy(40,7);
    cout<<"1.1 -> Speed Building course description"<<endl;
    gotoxy(40,9);
    cout<<"1.2 -> Review the Home Row"<<endl;
    gotoxy(40,11);
    cout<<"1.3 -> Fun phrases with A F J"<<endl;
    gotoxy(40,13);
    cout<<"1.4 -> Fun phrases with D K"<<endl;
    gotoxy(40,15);
    cout<<"1.5 -> Fun phrases with S L"<<endl;
    gotoxy(40,17);
    cout<<"Select lesson: (1-5) or 0 to return home or any key to exit"<<endl;

    char lesson=getch();
    system("cls");
    switch(lesson)
    {
    case '0':
        startMenu(0);
        break;
    case '1':
        SpeedBuildingCourseDescription();
        break;
    case '2':
        reviewHomeRow();
        break;
    case '3':
        keyDrill(dataset1,7);
        break;
    case '4':
        wordDrill(dataset1,7);
        break;
   // case '5':
        //
    //    break;
    default:
        exit(0);
    }
}
void SpeedBuildingCourseDescription()
{
    system("cls");
    cout<<"Speed Building Course"<<endl;
    cout<<endl;
    cout<<"Increasing your typing speed needs regular practice."<<endl;
}
void reviewHomeRow()
{
    gotoxy(10,5);
    cout<<"In this lesson, you will learn the home row.";
    gotoxy(10,6);
    cout<<"A S D F and J K L";
    gotoxy(10,9);
    cout<<"Press any key to continue.";
    char c=getch();
    system("cls");

    gotoxy(10,5);
    cout<<"Starting from the little finger, place your left hand fingers on A, S, D and F.";
    gotoxy(10,8);
    cout<<"Press any key to continue.";
    c=getch();
    system("cls");

    gotoxy(10,5);
    cout<<"Starting from the index finger, place your right hand fingers on J, K, L";
    gotoxy(10,8);
    cout<<"Press any key to continue.";
    c=getch();
    system("cls");

    gotoxy(10,5);
    cout<<"Let your thumbs rest on the space bar.";
    gotoxy(10,8);
    cout<<"Press any key to continue.";
    c=getch();
    system("cls");

    gotoxy(10,5);
    cout<<"Now your hands are in the basic position.";
    gotoxy(10,8);
    cout<<"Press any key to continue.";
    c=getch();
    system("cls");


    lesson('a');
    lesson('s');
    lesson('d');
    lesson('f');
    lesson('j');
    lesson('k');
    lesson('l');

    gotoxy(10,5);
    cout<<"Now you can start the first drill.";
    gotoxy(10,8);
    cout<<"Press any key to continue.";
    c=getch();
    system("cls");

    keyDrill(dataset1,7);
}
