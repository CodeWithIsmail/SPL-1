#include"dataset.h"
#include"set_cursor.h"
#include<windows.h>
#include<time.h>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;


string keyMapping(char input)
{
    map<char,string>keyMapping;

    keyMapping['a']="left little finger";
    keyMapping['s']="left ring finger";
    keyMapping['d']="left middle finger";
    keyMapping['f']="left index finger";
    keyMapping['j']="right index finger";
    keyMapping['k']="right middle finger";
    keyMapping['l']="right ring finger";
    keyMapping[';']="right little finger";
    keyMapping['e']="left middle finger";
    keyMapping['i']="right middle finger";
    keyMapping['r']="left index finger";
    keyMapping['u']="right index finger";
    keyMapping['t']="left index finger";
    keyMapping['o']="right ring finger";
    keyMapping['c']="left middle finger";
    keyMapping['e']="left middle finger";
    keyMapping[',']="right middle finger";
    keyMapping['h']="right index finger";
    keyMapping['g']="left index finger";
    keyMapping['n']="right index finger";
    keyMapping['v']="left index finger";
    keyMapping['w']="left ring finger";
    keyMapping['m']="right index finger";
    keyMapping['q']="left little finger";
    keyMapping['p']="right little finger";
    keyMapping['b']="left index finger";
    keyMapping['y']="right index finger";
    keyMapping['z']="left little finger";
    keyMapping['p']="left ring finger";

    return keyMapping[input];
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
