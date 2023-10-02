#include<bits/stdc++.h>
#include<conio.h>
#include<dos.h>
#include<windows.h>
#include<time.h>

#define SCREEN_WIDTH 100
#define SCREEN_HEIGHT 30
#define GAME_WIN_WIDTH 80

using namespace std;

HANDLE console=GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursor;
char keys[10];
int keyPos[10][2];
int score=0,life=10,level;

void gotoxy(int x,int y)
{
    cursor.X=x;
    cursor.Y=y;
    SetConsoleCursorPosition(console,cursor);
}
void set_cursor(bool visible,DWORD size)
{
    if(size==0)
        size=20;
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible=visible;
    lpCursor.dwSize=size;
    SetConsoleCursorInfo(console,&lpCursor);
}
void drawBorder()
{
    int i;
    for(i=0; i<SCREEN_WIDTH; i++)
    {
        gotoxy(i,SCREEN_HEIGHT);
        cout<<"+";
    }
    for(i=0; i<SCREEN_HEIGHT; i++)
    {
        gotoxy(0,i);
        cout<<"+";
        gotoxy(GAME_WIN_WIDTH,i);
        cout<<"+";
        gotoxy(SCREEN_WIDTH,i);
        cout<<"+";
    }
}
void gen_alphabet(int index)
{
    keys[index]=65+rand()%25;
    keyPos[index][0]=2+rand()%(GAME_WIN_WIDTH-2);
    keyPos[index][1]=1;
}
void draw_alphabet(int index)
{
    if(keyPos[index][0]!=0)
    {
        gotoxy(keyPos[index][0],keyPos[index][1]);
        cout<<keys[index];
    }
}
void erase_alphabet(int index)
{
    if(keyPos[index][0]!=0)
    {
        gotoxy(keyPos[index][0],keyPos[index][1]);
        cout<<" ";
    }
}
void reset_alphabet(int index)
{
    erase_alphabet(index);
    gen_alphabet(index);
}
void game_over()
{
    system("cls");
    cout<<endl;
    cout<<"\t\t------------------------------------------\n";
    cout<<"\t\t---------------GAME OVER------------------\n";
    cout<<"\t\t------------------------------------------\n\n";
    cout<<"\t\tPress any key to go back\n";
    getch();
}
void update_score()
{
    gotoxy(GAME_WIN_WIDTH+7,8);
    cout<<"Score: "<<score<<"\n";
}
void instructions()
{
    system("cls");
    ifstream instruction("catch_letter_instr.txt");
    string temp;
    while(getline(instruction,temp))
    {
        cout<<temp<<endl;
    }
    getch();
}
void game_play()
{
    score=0;
    int i;
    for(i=0; i<10; i++)
        keyPos[i][0]=keyPos[i][1]=1;

    system("cls");
    drawBorder();
    update_score();

    for(i=0; i<10; i++)
        gen_alphabet(i);

    gotoxy(GAME_WIN_WIDTH+5,4);
    cout<<"TYPING TUTOR";
    gotoxy(GAME_WIN_WIDTH+2,3);
    cout<<"------------------";
    gotoxy(GAME_WIN_WIDTH+2,5);
    cout<<"------------------";

    gotoxy(18,5);
    cout<<"Press any key to start";
    getch();
    gotoxy(18,5);
    cout<<"                       ";

    while(1)
    {
        if(kbhit())
        {
            char ch=getch();
            for(i=0; i<10; i++)
            {
                if(ch==keys[i])
                {
                    reset_alphabet(i);
                    score++;
                    update_score();
                }
            }
        }
        for(i=0; i<10; i++)
            draw_alphabet(i);

        Sleep(level);

        for(i=0; i<10; i++)
        {
            erase_alphabet(i);

            if(keyPos[i][1]>=SCREEN_HEIGHT)
            {
                life--;
            }
            else  keyPos[i][1]++;

        }
        if(!life)
        {
            game_over();
            return;
        }
    }
}

int main()
{
    // drawBorder();
    //  getch();
    // instructions();
    set_cursor(0,0);
    srand(time(NULL));

    while(1)
    {
        system("cls");
        cout<<"\n\n\t\t\t\t\t CATCH THE LETTER";
        cout<<"\n\n\t\t\t\t\t 1. Start Game";
        cout<<"\n\n\t\t\t\t\t 2. Instructions";
        cout<<"\n\n\t\t\t\t\t 3. Quit";
        cout<<"\n\n\t\t\t\t\t Select Option:";
        char option=getche();

        if(option=='1')
        {
            system("cls");
            cout<<"\n\n\t\t\t\t\t Select Level";
            cout<<"\n\n\t\t\t\t\t 1. Easy";
            cout<<"\n\n\t\t\t\t\t 2. Medium";
            cout<<"\n\n\t\t\t\t\t 3. Hard";
            char l=getch();
            if(l=='1') level=500;
            else if(l=='2') level=400;
            else level=300;
            game_play();

        }

        else if(option=='2')
            instructions();
        else exit(0);
    }

}
