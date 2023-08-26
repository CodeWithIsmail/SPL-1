/*
#include"set_cursor.h"
#include"FastTyperGame.h"
#include"drawing.h"
#include"StartMenu.h"
#include"getDate.h"
#include"dataset.h"
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<chrono>
#include<thread>
#include<fstream>
*/
#include "AllHeaderFile.h"
using namespace std;

void game1();
void Border();

char letter[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void game1()
{
    system("cls");

    gotoxy(40,5);
    cout<<"FAST TYPER";
    gotoxy(30,8);
    cout<<"How many 6 letter words can you type in 60 seconds?";
    gotoxy(30,11);
    cout<<"Press any key to start the game!";

    char ch;
    ch=getch();

    int score=0;

    Border();

    auto startTime = chrono::high_resolution_clock::now();

    ifstream file("FastTyperGame.txt");
    string word;

    for(;;)
    {
        auto currentTime = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsedSeconds = currentTime - startTime;
        if (elapsedSeconds.count() >= 60.0)
        {
            break;
        }

        system("cls");

        if(getline(file, word))
            getline(file,word);
        else
            word=RandomWordGen(letter,26);

        Border();


        gotoxy(40,5);
        cout<<"Score :"<<score;

        gotoxy(70,5);
        int remain=60-elapsedSeconds.count();
        cout<<"Remaining time: "<<remain;
        gotoxy(55,15);
        cout<<"Type this:";
        gotoxy(55,17);
        cout<<word;
        gotoxy(55,19);

        string input;
        int index=0,count=0;
        while(index<6)
        {
            auto currentTime = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsedSeconds = currentTime - startTime;
            if (elapsedSeconds.count() >= 60.0)
            {
                break;
            }

            char ch=_getch();
            if(ch==word[index])
            {
                cout<<ch;
                index++;
                count++;
            }
            else
            {
                break;
            }
        }
        if(count==6)
            score++;
    }
    file.close();

    system("cls");

    gotoxy(40,10);
    cout<<"Time's Up!";
    gotoxy(40,12);

    ifstream scoreFile("ScoreList.txt");
    string getScore;
    int highestScore=0;
    while(getline(scoreFile,getScore))
    {
        string temp="New Score: ";
        int index=getScore.find(temp);
        if(index!=-1)
        {
            string sc=getScore.substr(index+temp.size());
            int temp=stoi(sc);
            highestScore=max(highestScore,temp);
        }
    }
    scoreFile.close();
    gotoxy(40,15);

    if(score>highestScore)
    {
        cout<<"Congratulations!! New Highest Score!!";
        gotoxy(40,17);
        cout<<"Your Score is: "<<score;

    }
    else
    {
        cout<<"Highest Score: "<<highestScore;
        gotoxy(40,17);
        cout<<"Your Score is: "<<score;
    }

    ofstream scoreList("ScoreList.txt",ios::app);
    scoreList<<"New Score: "<<score<<endl;
    scoreList << "Date: " << DateFind() << endl;
    scoreList<<endl;
    scoreList.close();

   // ofstream performance("PerformanceHistory.csv",ios::app);
   ofstream performance("PerformanceHistory.txt",ios::app);
    performance<<"Game: Fast Typer  \t";
    performance<<DateFind()<<"\t\t\t\t\t\t\t";
    performance<<score<<"\n";
    performance.close();

    gotoxy(30,20);
    cout<<"Press 1 to play again or 0 to return Home or any key to exit.";
    char choice;
    choice=getch();

    if(choice=='0')
        startMenu(0);
    else if(choice=='1')
        game1();
    else exit(0);
}
void Border()
{
    drawBorder(35,51,3,7,"+","+");
    drawBorder(45,75,13,21,"+","+");
    drawBorder(65,93,3,7,"+","+");
}



