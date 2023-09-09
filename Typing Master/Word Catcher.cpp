#include "AllHeaderFile.h"
using namespace std;
char data[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void game2Border();
void game2()
{

    system("cls");
    game2Border();
    int up=7,down=18;
    bool check=false;

     while(down>11)
     {
         string input;
         string temp=RandomWordGen(data,26);
         for(int i=up; i<=down; i++)
         {
             gotoxy(60,i);
             cout<<temp;
             gotoxy(60,24);
             cin>>input;
             Sleep(1000);
             gotoxy(60,i);
             if(i!=down)
                 cout<<"          ";
             if(input==temp)
             {
                 check=true;
                 break;
             }
         }
        if(!check) down--;
     }

}
// game border 3 to 25 (up to down)
// game border 25 to 100 (left to right)
void game2Border()
{
    int i;

    for(i=25; i<=110; i++)
    {
        gotoxy(i,2);
        cout<<"=";
        gotoxy(i,25);
        cout<<"=";
    }
    for(i=3; i<=25; i++)
    {
        gotoxy(25,i);
        cout<<"||";
        gotoxy(110,i);
        cout<<"||";
    }
}


