#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include"set_cursor.h"
#include"StartMenu.h"
#include"commonWords.h"

using namespace std;

void mostCommonWord(int x)
{
    gotoxy(20,5);
    cout<<"Accuracy goal 95%";
    gotoxy(20,7);
    cout<<"Objective: Learn to fluently type some of the most common English words";
    gotoxy(20,10);
    cout<<"Press any key to start.";
    char ch;
    ch=getch();
    system("cls");

    int total=50,score=0;

    ifstream inputFile("MostCommonEnglishWord.txt");

    string line;
    while (getline(inputFile, line))
    {
        gotoxy(40,10);
        cout << line << endl;
        gotoxy(40,13);
        string input;
        cin>>input;
        if(input==line)
            score++;
        system("cls");
    }
    inputFile.close();

    int accuracy=(score*100)/total;
    gotoxy(40,7);
    cout<<"Your Score: "<<score;
    gotoxy(40,10);
    cout<<"Your Accuracy: "<<accuracy<<"%";
    gotoxy(40,15);
    cout<<"Press 1 to return home or any key exit.";

    char temp;
    temp=getch();
    if(temp=='1')
        startMenu(0);
    else
        exit(0);

    // return 0;
}
