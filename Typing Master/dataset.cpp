#include "StartMenu.h"
#include"dataset.h"
#include"set_cursor.h"
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;

string keyMapping(char input);
void lesson(char input);
void keyDrill(char dataset[],int limit);
void wordDrill(char dataset[],int limit);
void drawHistogram(char dataset[],int size,int frequency[]);

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

void keyDrill(char dataset[],int limit)
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
        gotoxy(40,3);
        cout<<"-----------"<<endl;

        gotoxy(40,4);
        cout<<"|";
        gotoxy(40,5);
        cout<<"|";
        gotoxy(40,6);
        cout<<"|";

        gotoxy(50,4);
        cout<<"|";
        gotoxy(50,5);
        cout<<"|";
        gotoxy(50,6);
        cout<<"|";

        gotoxy(40,7);
        cout<<"-----------"<<endl;

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

    cout<<"Enter 1 to return Main menu or any key to exit"<<endl;
    char check=getch();
    //  exit(0);
    if(check=='1') startMenu(0);
    else exit(0);
    //  else exit(0);
}

void wordDrill(char dataset[],int limit)
{
    int wrongPressCount[limit]= {0};
    int score=0,total=30,wrong=0,gross=0;
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
        gotoxy(40,3);
        cout<<"--------------------------";

        gotoxy(40,4);
        cout<<"|";
        gotoxy(40,5);
        cout<<"|";
        gotoxy(40,6);
        cout<<"|";

        gotoxy(65,4);
        cout<<"|";
        gotoxy(65,5);
        cout<<"|";
        gotoxy(65,6);
        cout<<"|";

        gotoxy(40,7);
        cout<<"--------------------------";

        int size=3+rand()%5;
        string out="";
        srand(time(NULL));
        for(int j=0; j<size; j++)
        {
            int index=rand()%limit;
            out+=dataset[index];
        }

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
        // string in;
        // gotoxy(53,9);
        // cin>>in;
        // if(in==out)
        //    score++;
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
    cout<<"Enter 1 for return home menu or any key to exit";
    ch=getch();
    if(ch=='1')
        startMenu(0);
    else exit(0);
}

void drawHistogram(char dataset[],int size,int frequency[])
{
    cout<<endl;
    cout<<"Your difficult keys in this lesson:"<<endl;
   // setColor(4);
    /*  int sum=0;
      for(int i=0; i<size; i++)
          sum+=frequency[i];
      for(int i=0; i<size; i++)
      {
          frequency[i]=(frequency[i]*100)/sum;
      }
    */

    cout<<endl;
    int maxFreq=INT_MIN;
    for(int i=0; i<size; i++)
    {
        if(frequency[i]>maxFreq)
        {
            maxFreq=frequency[i];
        }
    }

    for(int row=maxFreq; row>0; row--)
    {
        for(int element=0; element<size; element++)
        {
            if(frequency[element]<row)
                cout<<"           ";
            else
                cout<<" ********* ";
        }
        cout<<endl;
    }
    for(int i=0; i<size; i++)
        cout<<"-----------";
    cout<<endl;
    for(int i=0; i<size; i++)
        cout<<"     "<<dataset[i]<<"     ";
    cout<<endl;
}
