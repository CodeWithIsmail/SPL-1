#include "AllHeaderFile.h"

void statistics()
{
    system("cls");
    cout<<"\n\n\n\n\t\t\t\t\t 1. Performance History";
    cout<<"\n\n\t\t\t\t\t 2. Performance Analysis";

    cout<<"\n\n\n\t\t\t\t\t Enter your choice:";
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
    moveCursor(5,5);
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
        istringstream is(line);
        string temp;
        while(getline(is,temp,','))
             cout<<setw(10)<<right<<temp;
        cout<<"\n\n";
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
