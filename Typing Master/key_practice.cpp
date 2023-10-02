#include"AllHeaderFile.h"

int score=0,wrong=0,total=0;

void timer(int sec)
{
//    int sec = 60;
    while (sec>0)
    {
        sec--;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void typing_task(char dataset[],int limit)
{


    while (true)
    {
        int index=rand()%limit;
        moveCursor(45,5);
        cout<<dataset[index]<<endl;

        while(1)
        {
            char ch=getch();
            total++;
            if(ch==dataset[index])
            {
                score++;
                break;
            }
            else
            {
                wrong++;
                //    wrongPressCount[index]++;
                moveCursor(40,9);
                cout<<"Wrong Input. Try again.";
                moveCursor(40,11);
                cout<<"Use your "<<keyMapping(dataset[index])<<".";
            }
        }
        moveCursor(45,5);
        cout<<"  "<<endl;
        moveCursor(40,9);
        cout<<"                                  ";
        moveCursor(40,11);
        cout<<"                                   ";
    }


}

void time_prac(char dataset[],int limit,int sec)
{
    system("cls");
    system("color F1");

    cout<<"\n\n\n\n\t\t\t Objective: Practice to develop smooth and accurate keystrokes and even rhythm.";
    cout<<"\n\n\t\t\t Accuracy goal: 94%";
    cout<<"\n\n\n\t\t\t Enter any key to start"<<endl;
    getch();

    system("cls");
    drawBorder(40,50,3,7,"-","|");
    drawKeyboard();
    srand(time(NULL));


    thread timerThread(timer,sec);
    thread typingThread(typing_task,dataset,limit);;

    timerThread.join();
    typingThread.detach();


}
//  check=='1'? startMenu(): exit(0);
//  return score;
//  system("cls");
//   cout<<"Your score: "<<score;
//getch();
//  system("cls");

//    return 0;



