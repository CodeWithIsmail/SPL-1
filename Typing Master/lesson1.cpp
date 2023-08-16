#include"set_cursor.h"
#include "dataset.h"
#include"startMenu.h"
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>

using namespace std;
void typingBasics();
void homeRow();
char dataset1[8]= {'a','s','d','f','j','k','l',';'};

void lesson1(int x)
{
    system("cls");
    gotoxy(40,5);
    cout<<"Lesson 1: The Home Row"<<endl;
    cout<<endl;
    gotoxy(40,7);
    cout<<"1.1 -> Touch Typing Basics"<<endl;
    gotoxy(40,9);
    cout<<"1.2 -> New Keys: Home Row"<<endl;
    gotoxy(40,11);
    cout<<"1.3 -> Key Drill"<<endl;
    gotoxy(40,13);
    cout<<"1.4 -> Word Drill"<<endl;
    gotoxy(40,15);
    cout<<"1.5 -> Paragraph Drill"<<endl;
    gotoxy(40,17);
    cout<<"Select lesson: (1-5)"<<endl;

    char lesson=getch();
    system("cls");
    switch(lesson)
    {
    case '0':
        startMenu(0);
        break;
    case '1':
     typingBasics();
        break;
    case '2':
    homeRow();
        break;
    case '3':
        keyDrill(dataset1,8);
        break;
    case '4':
        wordDrill(dataset1,8);
        break;
    case '5':
        break;
    default:
        exit(0);
    }
}

void typingBasics()
{
    system("cls");
    cout<<"What is Touch Typing?"<<endl;
    cout<<endl;
    cout<<"Touch typing is a technique for typing quicker and more accurately with all ten fingers - without ever having to look at keyboard."<<endl;
    cout<<"After completing the Touch Typing Course you will know how to:"<<endl;
    cout<<"    -> Type faster with all ten fingers"<<endl;
    cout<<"    -> Type without errors"<<endl;
    cout<<"    -> Type without looking at the keyboard"<<endl;
    cout<<"This means you will be able to type your documents and emails much faster with fewer errors - saving you lots of time and making typing much more enjoyable"<<endl;

    cout<<"Press any key for next";
    char c=getch();

    system("cls");
    cout<<"Finger Positions:"<<endl;
    cout<<endl;
    cout<<"1. Put your left hand fingers on keys A S D F"<<endl;
    cout<<"2. Put your right hand fingers on keys J K L ;"<<endl;
    cout<<"3. Let the thumbs rest lightly on the space bar"<<endl;
    cout<<"4. Keep your wrists straight and fingers lightly closed"<<endl;

    cout<<"Enter 1 to return to Lesson1 menu , or any key to exit"<<endl;
    c=getch();
    if(c=='1')
        lesson1(1);
    else exit(0);
}
void homeRow()
{
    gotoxy(10,5);
    cout<<"In this lesson, you will learn the home row.";
    gotoxy(10,6);
    cout<<"A S D F and J K L ;";
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
    cout<<"Starting from the index finger, place your right hand fingers on J, K, L and semicolon.";
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
    lesson(';');

    gotoxy(10,5);
    cout<<"Now you can start the first drill.";
    gotoxy(10,8);
    cout<<"Press any key to continue.";
    c=getch();
    system("cls");

    keyDrill(dataset1,8);
}
