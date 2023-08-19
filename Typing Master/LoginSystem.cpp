#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include"set_cursor.h"
#include"StartMenu.h"
#include"LoginSystem.h"

using namespace std;

void signIn();
void signUp();

void signIn()
{
    gotoxy(25,5);
    cout<<"Enter username: ";
    string name;
    gotoxy(25,7);
    cin>>name;
    gotoxy(25,9);
    cout<<"Enter Password";
    string password;
    gotoxy(25,11);
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
        startMenu(0);
    }
    else
    {
        system("cls");
        gotoxy(25,7);
        cout<<"Username or Password mismatch.";
    }

}
