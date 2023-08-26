/*
#include "StartMenu.h"
#include"dataset.h"
#include"set_cursor.h"
#include "getDate.h"
#include"drawing.h"
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<fstream>

#include<bits/stdc++.h>
*/
#include "AllHeaderFile.h"
using namespace std;

string keyMapping(char input);
void lesson(char input);
void keyDrill(char dataset[],int limit);
void wordDrill(char dataset[],int limit);
string RandomWordGen(char dataset[],int limit );

string keyMapping(char input)
{
    if(input=='a')
        return "left little finger";
    if(input=='s')
        return "left ring finger";
    if(input=='d')
        return "left middle finger";
    if(input=='f')
        return "left index finger";
    if(input=='j')
        return "right index finger";
    if(input=='k')
        return "right middle finger";
    if(input=='l')
        return "right ring finger";
    if(input==';')
        return "right little finger";
    if(input=='e')
        return "left middle finger";
    if(input=='i')
        return "right middle finger";
    if(input=='r')
        return "left index finger";
    if(input=='u')
        return "right index finger";
    if(input=='t')
        return "left index finger";
    if(input=='o')
        return "right ring finger";
    if(input=='c')
        return "left middle finger";
    if(input=='e')
        return "left middle finger";
    if(input==',')
        return "right middle finger";
    if(input=='h')
        return "right index finger";
    if(input=='g')
        return "left index finger";
    if(input=='n')
        return "right index finger";
    if(input=='v')
        return"left index finger";
    if(input=='w')
        return "left ring finger";
    if(input=='m')
        return "right index finger";
    if(input=='q')
        return "left little finger";
    if(input=='p')
        return "right little finger";
    if(input=='b')
        return "left index finger";
    if(input=='y')
        return "right index finger";
    if(input=='z')
        return "left little finger";
    if(input=='x')
        return "left ring finger";
}

void lesson(char input)
{
    gotoxy(10,5);
    string temp=keyMapping(input);
    cout<<"Now try typing '"<<input<<"' with "<<temp<<".";

    for(;;)
    {
        char ch=getch();
        if(ch==input)
        {
            system("cls");
            break;
        }
        else
        {
            gotoxy(10,7);
            cout<<"Try again.";
        }
    }
}

void keyDrill(char dataset[],int limit,int lessonNum,int partNum)
{

    int wrongPressCount[limit]= {0};
    int score=0,total=50,wrong=0;

    srand(time(NULL));
    gotoxy(10,5);
    cout<<"Objective: Reinforcement practice to develop smooth and accurate keystrokes and even rhythm"<<endl;
    gotoxy(10,8);
    cout<<"Accuracy goal: 94%"<<endl;
    cout<<endl;
    gotoxy(10,11);
    cout<<"Enter any key to start"<<endl;
    char temp=getch();
    system("cls");

    for(int i=0; i<total; i++)
    {
        system("cls");
        drawBorder(40,50,3,7,"-","|");
        drawKeyboard();

        int index=rand()%limit;
        gotoxy(45,5);
        cout<<dataset[index]<<endl;

        while(1)
        {
            char ch=getch();
            int target,got;
            for(int i=0; i<limit; i++)
            {
                if(dataset[i]==ch)
                    got=i;
                if(dataset[i]==dataset[index])
                    target=i;
            }
            if(ch==dataset[index])
            {
                score++;
                break;
            }
            else
            {
                wrong++;
                wrongPressCount[target]++;
                wrongPressCount[got]++;
                gotoxy(40,9);
                cout<<"Wrong Input. Try again.";
                gotoxy(40,11);
                cout<<"Use your "<<keyMapping(dataset[index])<<".";
            }
        }
    }
    score-=wrong;
    int accuracy=(score*100)/total;
    system("cls");
    gotoxy(40,5);
    cout<<"Wrong Press key: "<<wrong<<" times.";
    gotoxy(40,7);
    cout<<"Your score: "<<score<<endl;
    gotoxy(40,9);
    cout<<"Your accuracy: "<<accuracy<<" %"<<endl;
    gotoxy(40,11);
    if(accuracy>=94)
        cout<<"Very Good"<<endl;
    else
        cout<<"Try to improve"<<endl;

    cout<<"Your wrong press report:"<<endl;
    drawHistogram(dataset, limit,wrongPressCount);
    cout<<endl;

    ofstream performance("PerformanceHistory.txt",ios::app);
    performance<<"Tutorial Number: "<<lessonNum<<"."<<partNum<<endl;
    performance<<"Date: "<<DateFind()<<endl;
    performance<<"Total Key Press: "<<total+wrong<<endl;
    performance<<"Wrong Key Press: "<<wrong<<endl;
    performance<<"Accuracy :"<<accuracy<<"%"<<endl;
    performance<<"Score :"<<score<<endl;
    performance<<endl;
    performance.close();

    cout<<"Enter 1 to return Main menu or any key to exit"<<endl;
    char check=getch();
    //  exit(0);
    if(check=='1') startMenu(0);
    else exit(0);
    //  else exit(0);
}

void wordDrill(char dataset[],int limit,int lessonNum,int partNum)
{
    int wrongPressCount[limit]= {0};
    int score=0,total=15,wrong=0,gross=0;
    gotoxy(10,5);
    cout<<"Objective: Integrate new keys with keys already learned and add flow to your typing."<<endl;
    gotoxy(10,8);
    cout<<"Accuracy Goal: 94 %"<<endl;
    gotoxy(10,10);
    cout<<"Enter any key to start"<<endl;
    srand(time(NULL));
    char ch=getch();
    system("cls");


    for(int i=0; i<total; i++)
    {
        system("cls");
        drawBorder(40,65,3,7,"-","|");
        drawKeyboard();

        string out=RandomWordGen(dataset,limit);
        gotoxy(53,5);
        cout<<out<<endl;
        gotoxy(53,8);
        int index=0;
        while(index<out.length())
        {
            char ch=_getch();
            gross++;
            int target=0,got=0;
            for(int j=0; j<limit; j++)
            {
                if(dataset[j]==ch)
                    got=j;
                if(dataset[j]==out[index])
                    target=j;
            }
            if(ch==out[index])
            {
                cout<<ch;
                index++;
            }
            else
            {
                wrong++;
                wrongPressCount[target]++;
                wrongPressCount[got]++;
            }
        }
    }
    score=gross-wrong;
    int accuracy=(score*100)/gross;
    system("cls");

    gotoxy(40,5);
    cout<<"Total Key Press: "<<gross;
    gotoxy(40,7);
    cout<<"Wrong Key Press: "<<wrong;
    gotoxy(40,9);
    cout<<"Accuracy: "<<accuracy<<"%";
    gotoxy(40,11);
    if(accuracy>=94)
        cout<<"Very good";
    else
        cout<<"Try more";
    cout<<endl;


    drawHistogram(dataset, limit,wrongPressCount);
    cout<<endl;

    ofstream performance("PerformanceHistory.txt",ios::app);
    performance<<"     "<<lessonNum<<"."<<partNum<<"\t\t";
    performance<<DateFind()<<"     \t";
    performance<<gross<<"\t\t\t";
    performance<<wrong<<"\t\t   ";
    performance<<accuracy<<"%"<<"\t\t  ";
    performance<<score<<"\n";
    performance.close();

    cout<<"\tEnter 1 for return home menu or any key to exit";
    ch=getch();
    if(ch=='1')
        startMenu(0);
    else exit(0);
}

string RandomWordGen(char dataset[],int limit)
{
    srand(time(NULL));
    int size=3+rand()%5;
    string out="";

    for(int j=0; j<size; j++)
    {
        int index=rand()%limit;
        out+=dataset[index];
    }
    return out;
}






