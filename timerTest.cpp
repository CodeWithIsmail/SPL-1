#include <iostream>
#include <thread>
#include <chrono>
#include <conio.h>
#include<bits/stdc++.h>
using namespace std;

int score=0;

void timer()
{
    int sec = 60;
    while (sec>0)
    {
        sec--;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

void typing_task()
{
    while (true)
    {
        char ch='a'+rand()%25;
        cout << ch << "\n";
        char input = _getch();
        if(input==ch) score++;
        system("cls");
    }
}

int main()
{
    thread timerThread(timer);
    thread typingThread(typing_task);

    timerThread.join();
    typingThread.detach();

    cout<<"Your score: "<<score;
    return 0;
}
