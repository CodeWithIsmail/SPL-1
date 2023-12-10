#include<bits/stdc++.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<time.h>
#include<io.h>
using namespace std;

HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursor;

void gotoxy(int x,int y)
{
    cursor.X=x;
    cursor.Y=y;
    SetConsoleCursorPosition(console,cursor);
}

void draw_border()
{
    gotoxy(40,25);
    for(int i=0; i<20; i++)
        cout<<"__";
    for(int i=0; i<=15; i++)
    {
        gotoxy(40,10+i);
        cout<<"|";
        gotoxy(80,10+i);
        cout<<"|";
    }
}

void game()
{
    ifstream file("randomword.txt");
    int bound=24,x=57,y=8;
    while(1)
    {
        string word;
        getline(file,word);
        gotoxy(x,y);
        cout<<word<<"\n";
        // string
        break;
    }
}

int main()
{
    draw_border();
    game();
    int n;
    cin>>n;
}
