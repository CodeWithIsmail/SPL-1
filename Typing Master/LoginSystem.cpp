#include "AllHeaderFile.h"

void signIn()
{
    system("cls");
    cout<<"--------------------------";
    moveCursor(40,6);
    cout<<"|     TYPING TUTOR       |";
    moveCursor(40,7);
    cout<<"--------------------------";

    moveCursor(42,11);
    cout<<"Enter Username: ";
    string name;
    cin>>name;
    moveCursor(42,13);
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
        moveCursor(25,7);
        cout<<"Welcome to Typing Tutor, "<<name;
        moveCursor(25,10);
        cout<<"Press any key for Start Menu";
        char ch;
        ch=getch();
        system("cls");
        startMenu();
    }
    else
    {
        system("cls");
        moveCursor(25,7);
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
