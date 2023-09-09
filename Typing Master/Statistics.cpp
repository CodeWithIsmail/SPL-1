#include "AllHeaderFile.h"
using namespace std;

void history();
void statistics();
void performanceAnalysis();

void statistics()
{
    system("cls");
    gotoxy(40,10);
    cout<<"1. Performance History";
    gotoxy(40,12);
    cout<<"2. Performance Analysis";


    gotoxy(40,17);
    cout<<"Enter your choice:";
    char ch=getch();
    if(ch=='1')
        history();
    else if(ch=='2')
        performanceAnalysis();
    else exit(0);


}
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

void performanceAnalysis()
{

}
