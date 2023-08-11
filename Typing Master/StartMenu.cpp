#include"set_cursor.h"
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    do
    {
        system("cls");
        gotoxy(40,5);
        cout<<"--------------------------";
        gotoxy(40,6);
        cout<<"|     TYPING TUTOR       |";
        gotoxy(40,7);
        cout<<"--------------------------";
        gotoxy(40,9);
        cout<<"1. Typing Tutorial"<<endl;
        gotoxy(40,11);
        cout<<"2. Practice"<<endl;
        gotoxy(40,13);
        cout<<"3. Games"<<endl;
        gotoxy(40,15);
        cout<<"4. User Manual"<<endl;
        gotoxy(40,17);
        cout<<"5. Exit"<<endl;

        gotoxy(40,20);
        cout<<"Select option: "<<endl;;
        char option=getch();

        switch(option)
        {
        case '1':
            //TypingTutorial();
            break;
        case '2':
            //  Practice();
            break;
        case '3':
            // Games();
            break;
        case '4':
            //UserManual();
            break;
        case '5':
            cout<<"Exiting the application...."<<endl;
            exit(0);
        }
    }
    while(1);
}
