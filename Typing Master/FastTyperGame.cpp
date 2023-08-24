#include"set_cursor.h"
#include"FastTyperGame.h"
#include"StartMenu.h"
#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<chrono>
#include<thread>

using namespace std;

void game1();
string wordGen();
void drawBorder();

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
            word=wordGen();

        drawBorder();
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

    ifstream scoreList("ScoreList.txt");
    string getScore;
    int highestScore=0;
    while(getline(scoreList,getScore))
    {
        int temp=stoi(getScore);
        highestScore=max(highestScore,temp);
    }
    scoreList.close();
    gotoxy(40,15);
    if(score>highestScore)
    {
        cout<<"Congratulations!! New Highest Score!!";
        gotoxy(40,17);
        cout<<"Your Score is: "<<score;
        ofstream scoreList("ScoreList.txt");
        scoreList<<score;
    }
    else
    {
        cout<<"Highest Score: "<<highestScore;
        gotoxy(40,17);
        cout<<"Your Score is: "<<score;
    }

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

string wordGen()
{
    string randomWord="";
    int length=5;
    srand(time(NULL));
    while(length--)
    {
        int index=rand()%26;
        randomWord+=letter[index];
    }
    return randomWord;
}

void drawBorder()
{
    gotoxy(35,3);
    cout<<"+++++++++++++++++";
    gotoxy(35,7);
    cout<<"+++++++++++++++++";
    for(int i=4; i<7; i++)
    {
        gotoxy(35,i);
        cout<<"+";
        gotoxy(51,i);
        cout<<"+";
    }

    gotoxy(65,3);
    cout<<"+++++++++++++++++++++++++++++";
    gotoxy(65,7);
    cout<<"+++++++++++++++++++++++++++++";
    for(int i=4; i<7; i++)
    {
        gotoxy(65,i);
        cout<<"+";
        gotoxy(93,i);
        cout<<"+";
    }

    gotoxy(45,13);
    cout<<"+++++++++++++++++++++++++++++++";
    gotoxy(45,21);
    cout<<"+++++++++++++++++++++++++++++++";
    for(int i=14; i<21; i++)
    {
        gotoxy(45,i);
        cout<<"+";
        gotoxy(75,i);
        cout<<"+";
    }
}
