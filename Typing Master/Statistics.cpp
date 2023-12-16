#include "AllHeaderFile.h"

void statistics()
{
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\t 1. Performance History";
    cout << "\n\n\t\t\t\t\t 2. Performance Analysis";

    cout << "\n\n\n\t\t\t\t\t Enter your choice:";
    char ch = getch();
    if (ch == '1')
        history();
    else if (ch == '2')
        performanceAnalysis();
    else
        exit(0);
}
void history()
{
    system("cls");
    moveCursor(5, 5);
    ifstream username("UserList.txt");
    string name;
    getline(username, name);
    username.close();

    cout << "\t User: " << name << endl;
    cout <<"____________________________________________________________________________________________________________________\n\n";

    cout << "Tutorial Number                   Date     Total Key Press     Wrong Key Press    Accuracy     Score\n\n";
    cout << "____________________________________________________________________________________________________________________\n\n";

    string fname = "PerformanceHistory.txt";
    ifstream performance(fname);
    string line;
    while (getline(performance, line))
    {
        istringstream is(line);
        string temp;
        getline(is, temp, ',');
          cout << temp;
       if(temp[0]=='G' || temp[0]=='C') cout<<" ";
       else cout<<"      ";
        while (getline(is, temp, ','))
            cout << setw(15) << right << temp;
        cout << "\n\n";
    }
    performance.close();

    cout << "\n\n\n\n\t\t Enter 1 to return Main menu or any key to exit";
    char ch = getch();
    if (ch == '1')
        startMenu();
    else
        exit(0);
}

void performanceAnalysis()
{
}
