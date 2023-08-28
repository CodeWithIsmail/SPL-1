/*#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include"set_cursor.h"
#include"StartMenu.h"
#include"LoginSystem.h"*/
#include "AllHeaderFile.h"

using namespace std;

void signIn();
void signUp();

void signIn()
{

    system("cls");
    gotoxy(40,5);
    cout<<"--------------------------";
    gotoxy(40,6);
    cout<<"|     TYPING TUTOR       |";
    gotoxy(40,7);
    cout<<"--------------------------";

 //   gotoxy(40,9);
  //  cout<<"--------------------------";

    gotoxy(42,11);
    cout<<"Enter Username: ";
    string name;
    cin>>name;
    gotoxy(42,13);
    cout<<"Enter Password: ";
    string password;
    cin>>password;

    bool checkName=false,checkPassword=false;

    ifstream users("UserList.txt");

    string line;
    while (getline(users, line))
    {
        if(line==name)
            checkName=true;
        if(line==password)
            checkPassword=true;
        if(checkName== true && checkPassword==true)
            break;
    }
    users.close();

    if(checkName==true && checkPassword==true)
    {
        system("cls");
        gotoxy(25,7);
        cout<<"Welcome to Typing Tutor, "<<name;
        gotoxy(25,10);
        cout<<"Press any key for Start Menu";
        char ch;
        ch=getch();
        system("cls");
        startMenu();
    }
    else
    {
        system("cls");
        gotoxy(25,7);
        cout<<"Username or Password mismatch! Press 0 to exit the application or any other key try again.";
        char ch=getch();
        if(ch=='0')
            exit(0);
        else
            signIn();
    }

}
void signUp()
{

}
