#include "AllHeaderFile.h"

void drawKeyboard()
{
    gotoxy(10,20);
    cout <<"Keyboard :\n";
    cout <<
         "\t\t     ,---,---,---,---,---,---,---,---,---,---,---,---,---,-------'\n" <<
         "\t\t     | ~ | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 0 | - | + |   <-  |\n" <<
         "\t\t     |---'---'---'---'---'---'---'---'---'---'---'---'---'-------|\n" <<
         "\t\t     | <-> | Q | W | E | R | T | Y | U | I | O | P | { | } | \\   |\n"<<
         "\t\t     |-----'---'---'---'---'---'---'---'---'---'---'---'---'-----|\n" <<
         "\t\t     | Caps | A | S | D | F | G | H | J | K | L | ; | ' |  Enter |\n" <<
         "\t\t     |------'---'---'---'---'---'---'---'---'---'---'---'--------|\n" <<
         "\t\t     | Shift  | Z | X | C | V | B | N | M | , | . | ? |  Shift   |\n" <<
         "\t\t     |--------'---'---'---'---'---'---'---'---'---'---'----------|\n" <<
         "\t\t     | Ctrl | Win | Alt |                           | Alt | Ctrl |\n" <<
         "\t\t     '------'-----'-----'---------------------------'-----'------'\n";
}

void drawHistogram(char dataset[],int size,int frequency[])
{
    cout<<"\n\t\tYour difficult keys in this lesson:\n\n";

    int maxFreq=INT_MIN;
    for(int i=0; i<size; i++)
    {
        if(frequency[i]>maxFreq)
            maxFreq=frequency[i];
    }

    for(int row=maxFreq; row>0; row--)
    {
        for(int element=0; element<size; element++)
        {
            frequency[element]<row? cout<<"           ":cout<<" ********* ";
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

void drawBorder(int x1,int x2,int y1,int y2,string ch1,string ch2)
{
    for(int i=1; i<x2-x1; i++)
    {
        gotoxy(x1+i,y1);
        cout<<ch1;
        gotoxy(x1+i,y2);
        cout<<ch1;
    }
    for(int i=1; i<y2-y1; i++)
    {
        gotoxy(x1,y1+i);
        cout<<ch2;
        gotoxy(x2,y1+i);
        cout<<ch2;
    }
}

