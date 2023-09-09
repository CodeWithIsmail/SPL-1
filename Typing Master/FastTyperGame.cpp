#include "AllHeaderFile.h"

char letter[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

void game1()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\t\t FAST TYPER";
    cout<<"\n\n\n\t\t\t\t\t How many 6 letter words can you type in 60 seconds?";
    cout<<"\n\n\n\t\t\t\t\t Press any key to start the game!";
    getch();

    system("cls");
    Border();

    ifstream file("FastTyperGame.txt");
    string word;
    int score=0;

    auto startTime = chrono::high_resolution_clock::now();
    for(;;)
    {
        auto currentTime = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = currentTime - startTime;
        if (duration.count() >= 60.0)
        {
            break;
        }
        clearScreen();

        if(getline(file, word))
            getline(file,word);
        else
            word=RandomWordGen(letter,26);

        gotoxy(40,5);
        cout<<"Score :"<<score;
        gotoxy(70,5);
        int remain=60-duration.count();
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
    cout<<"\n\n\n\t\t\t\t\t Time's Up!";

    int highestScore=0;
    string highest,temp;
    ifstream scorefile("scoreList.txt");
    getline(scorefile,temp);
    istringstream str(temp);
    getline(str,highest,',');
    highestScore=stoi(highest);

    if(score>highestScore)
    {
        cout<<"\n\n\t\t\t\t\t Congratulations!! New Highest Score!!";
        ofstream scoreList("ScoreList.txt");
        string sc=to_string(score)+","+DateFind()+"\n";
        scoreList<<sc;
        scoreList.close();
    }
    else
    {
        cout<<"\n\n\t\t\t\t\t Highest Score: "<<highestScore;
    }
    cout<<"\n\n\t\t\t\t\t Your Score is: "<<score;

    ofstream performance("PerformanceHistory.txt",ios::app);
    string write="Game: Fast Typer,"+DateFind()+","+to_string(score)+"\n";
    performance<<write;
    performance.close();

    cout<<"\n\n\t\t\t\t Press 1 to play again or 0 to return Home or 2 to exit.\n\n";
    while(1)
    {
        char ch=getch();
        if(ch=='0')
            startMenu();
        else if(ch=='1')
            game1();
        else if(ch=='2')
            exit(0);
        else
            cout<<"t\t\t\t Wrong Input. Try again.\n";
    }
}
void Border()
{
    drawBorder(35,51,3,7,"+","+");
    drawBorder(45,75,13,21,"+","+");
    drawBorder(65,93,3,7,"+","+");
}
void clearScreen()
{
    gotoxy(48,5);
    cout<<"   ";
    gotoxy(86,5);
    cout<<"   ";
    gotoxy(55,17);
    cout<<"       ";
    gotoxy(55,19);
    cout<<"       ";
}


