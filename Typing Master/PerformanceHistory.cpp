/*#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include "set_cursor.h"
#include "PerformanceHistory.h"*/
#include "AllHeaderFile.h"

using namespace std;
void history()
{
    system("cls");
    gotoxy(5,5);
    ifstream username("UserList.txt");
    string name;
    getline(username,name);
    username.close();

    cout<<"\t User: "<<name<<endl;
    cout<<"\t______________________________________________________________________________________________________________________\n\n";

    cout<<"\t Tutorial Number \t\t Date \t\t Total Key Press \t Wrong Key Press \t Accuracy \t Score\n\n";
    cout<<"\t_______________________________________________________________________________________________________________________\n\n";

    ifstream performance("PerformanceHistory.txt");
    string line;
    while(getline(performance,line))
    {
       cout<<"\t "<<line<<endl;
    }
    performance.close();

    cout<<"\n\n\n\n\t\t Enter 1 to return Main menu or any key to exit";
    char ch=getch();
    if(ch=='1')
        startMenu();
    else exit(0);
}
