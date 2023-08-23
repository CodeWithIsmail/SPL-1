#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include"set_cursor.h"
#include"StartMenu.h"
#include"commonWords.h"

using namespace std;

void mostCommonWord(int x)
{
    int gross=0,wrong=0;
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

    string out;
    while (getline(inputFile, out))
    {
        system("cls");
        gotoxy(40,10);
        cout << out << endl;

        gotoxy(40,12);
        int index=0;
        while(index<out.length())
        {
            char ch=_getch();
            gross++;
            if(ch==out[index])
            {
                cout<<ch;
                index++;
            }
            else
                wrong++;
        }
    }
    inputFile.close();

     score=gross-wrong;
    int accuracy=(score*100)/gross;
    system("cls");
    gotoxy(40,5);
    cout<<"Total Key Press: "<<gross;
    gotoxy(40,7);
    cout<<"Wrong Key Press: "<<wrong;
    gotoxy(40,9);
    cout<<"Accuracy: "<<accuracy<<"%";
    gotoxy(40,12);
    cout<<"Press 1 to return home or any key exit.";

    char temp;
    temp=getch();
    if(temp=='1')
        startMenu(0);
    else
        exit(0);
}
