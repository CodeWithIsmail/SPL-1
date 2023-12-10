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

void typing_task_key()
{
      // srand(time(NULL));
    while (true)
    {
        int random_index=rand()%26;
        char key='a'+random_index;

        moveCursor(45,5);
        cout<<key<<endl;
        char ch=getch();
        total++;
        if(ch==key)
        {
            score++;
        }
        else
        {
            wrong++;
            //    wrongPressCount[index]++;
            //  moveCursor(40,9);
            //   cout<<"Wrong Input. Try again.";
            //   moveCursor(40,11);
            //   cout<<"Use your "<<keyMapping(dataset[index])<<".";

        }
        moveCursor(45,5);
        cout<<"     "<<endl;
        /*  moveCursor(40,9);
          cout<<"                                  ";
          moveCursor(40,11);
          cout<<"                                   "; */
    }
}

void typing_task_word()
{
      // srand(time(NULL));
   ifstream file("randomword.txt");
    while (1)
    {
     //   int word_size=rand()%4+3;
        string word;
        getline(file,word);
    /*    for(int i=0; i<word_size; i++)
        {
            int random_index=rand()%26;
            word+='a'+random_index;
        }
*/
        moveCursor(45,5);
        cout<<word<<endl;

        string input;
        moveCursor(45,8);
        cin>>input;

        total++;
        if(input==word)
        {
            score++;
        }
        else
        {
            wrong++;
            //    wrongPressCount[index]++;
            //  moveCursor(40,9);
            //   cout<<"Wrong Input. Try again.";
            //   moveCursor(40,11);
            //   cout<<"Use your "<<keyMapping(dataset[index])<<".";
        }

        moveCursor(45,5);
        cout<<"                "<<endl;
        moveCursor(45,8);
        cout<<"                "<<endl;
    }
    /*    moveCursor(40,9);
        cout<<"                                  ";
        moveCursor(40,11);
        cout<<"                                   "; */
}


void time_prac_word(int sec)
{
    system("cls");
    system("color F1");

    cout<<"\n\n\n\n\t\t\t Objective: Practice to develop smooth and accurate keystrokes and even rhythm.";
    cout<<"\n\n\t\t\t Accuracy goal: 94%";
    cout<<"\n\n\n\t\t\t Enter any key to start"<<endl;
    getch();

    system("cls");
    //  drawBorder(40,50,3,7,"-","|");
    drawKeyboard();
    srand(time(NULL));

    thread timerThread(timer,sec);
    thread typingThread(typing_task_word);

    timerThread.join();
    typingThread.detach();

    system("cls");
    cout<<"\n\n\t\t\t\t\t Times up!!!";
    cout<<"\n\n\t\t\t\t\t Press any key to see result";
    getch();
    system("cls");
    cout<<"\n\n\t\t\t\t\t  Practice time: "<<sec<<" seconds";
    cout<<"\n\n\t\t\t\t\t  Score: "<<score;
    double accuracy=((score-wrong)*100)/score;
    cout<<"\n\n\t\t\t\t\t  Total Key press:  "<<score+wrong;
    cout<<"\n\n\t\t\t\t\t Wrong Key press:  "<<wrong;
    cout<<"\n\n\t\t\t\t\t Accuracy:  "<<accuracy<<" %";
    cout<<"\n\n\n\n\t\t\t\t Press any key to go back to Menu";
    getch();
    system("cls");
    return;
    //startMenu();
}


void time_prac_key(int sec)
{
    system("cls");
    system("color F1");

    cout<<"\n\n\n\n\t\t\t Objective: Practice to develop smooth and accurate keystrokes and even rhythm.";
    cout<<"\n\n\t\t\t Accuracy goal: 94%";
    cout<<"\n\n\n\t\t\t Enter any key to start"<<endl;
    getch();

    system("cls");
    //  drawBorder(40,50,3,7,"-","|");
    drawKeyboard();
    srand(time(NULL));

    thread timerThread(timer,sec);
    thread typingThread(typing_task_key);

    timerThread.join();
    typingThread.detach();


    system("cls");
    cout<<"\n\n\t\t\t\t\t Times up!!!";
    cout<<"\n\n\t\t\t\t\t Press any key to see result";
    getch();
    system("cls");
    cout<<"\n\n\t\t\t\t\t  Practice time: "<<sec<<" seconds";
    cout<<"\n\n\t\t\t\t\t  Score: "<<score;
    double accuracy=((score-wrong)*100)/score;
    cout<<"\n\n\t\t\t\t\t  Total Key press:  "<<score+wrong;
    cout<<"\n\n\t\t\t\t\t Wrong Key press:  "<<wrong;
    cout<<"\n\n\t\t\t\t\t Accuracy:  "<<accuracy<<" %";
    cout<<"\n\n\n\n\t\t\t\t Press any key to go back to Menu";
    getch();
    system("cls");
    return;
}



