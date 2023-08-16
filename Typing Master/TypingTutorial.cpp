#include"StartMenu.h"
#include"lesson1.h"
#include"set_cursor.h"
#include<windows.h>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;

void TypingTutorial(int x)
{

    system("cls");

    gotoxy(40,5);
    cout<<"LESSONS:"<<endl;
    gotoxy(40,7);
    cout<<"1. The Home row"<<endl;
    gotoxy(40,9);
    cout<<"2. Keys E and I"<<endl;
    gotoxy(40,11);
    cout<<"3. Keys R and U"<<endl;
    gotoxy(40,13);
    cout<<"4. Keys T and O"<<endl;
    gotoxy(40,15);
    cout<<"5. Capital letters and Period"<<endl;
    gotoxy(40,17);
    cout<<"6. Keys C and Comma"<<endl;
    gotoxy(40,19);
    cout<<"7. Keys G H and Apostrophe"<<endl;
    gotoxy(40,21);
    cout<<"8. Keys V N and Question Mark"<<endl;
    gotoxy(40,23);
    cout<<"9. Keys W and M"<<endl;
    gotoxy(40,25);
    cout<<"10. Keys Q and P"<<endl;
    gotoxy(40,27);
    cout<<"11. Keys B and Y"<<endl;
    gotoxy(40,29);
    cout<<"12. Keys Z and X"<<endl;

    cout<<endl;
    cout<<"Select your lesson or Enter 0 to return Home or any key to exit:"<<endl;
    //  int lesson;
    //  cin>>lesson;
    int ch;
    cin>>ch;
    switch(ch)
    {
    case 0:
        startMenu(0);
        break;
    case 1:
        lesson1(1);
        break;
    case 2:
     //   lesson2();
        break;
    case 3:
        //lesson3();
        break;
    case 4:
      //  lesson4();
        break;
    case 5:
        //  lesson5();
        break;
    case 6:
      //  lesson6();
        break;
    case 7:
       // lesson7();
        break;
    case 8:
      //  lesson8();
        break;
    case 9:
      //  lesson9();
        break;
    case 10:
       // lesson10();
        break;
    case 11:
      //  lesson11();
        break;
    case 12:
      //  lesson12();
        break;
    default :
        exit(0);
    }
}
