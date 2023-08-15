#include"dataset.h"
#include"set_cursor.h"
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;


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
    if(input=='h')
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
    if(input=='p')
        return "left ring finger";
}

void lesson(char input)
{
    gotoxy(10,5);
    cout<<"Now try typing '"<<input<<"' with "<<keyMapping[input]<<".";

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
            if(ch==dataset[index])
            {
                score++;
                break;
            }
            else
            {
                wrong++;
                gotoxy(40,9);
                cout<<"Wrong Input. Try again.";
                gotoxy(40,11);
                cout<<"Use your "<<keyMapping[dataset[index]]<<".";
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
    if(accuracy>=94) cout<<"Very Good"<<endl;
    else cout<<"Try to improve"<<endl;

    cout<<endl;
    gotoxy(40,13);
    cout<<"Enter 1 to return Main menu or any key to exit"<<endl;
    char check=getch();
    exit(0);
    //  if(check=='1') StartMenu();
    //  else exit(0);
}
