#include"StartMenu.h"
#include"lesson1.h"
#include"set_cursor.h"

#include"FocusOnTheHomeRow.h"
#include"indexFingerKeys.h"
#include"middleFingerKeys.h"
#include"ringFingerKeys.h"
#include"littleFingerKeys.h"
#include"commonWords.h"

#include<windows.h>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;

void TypingTutorial(int x)
{

    system("cls");

    gotoxy(40,4);
    cout<<"LESSONS:"<<endl;
    gotoxy(40,7);
    cout<<"1. Focus on the Home Row";
    //cout<<"1. The Home row"<<endl;
    gotoxy(40,9);
    cout<<"2. Focus on the Index Finger keys";
    //cout<<"2. Keys E and I"<<endl;
    gotoxy(40,11);
    cout<<"3. Focus on the Middle Finger keys";
    // cout<<"3. Keys R and U"<<endl;
    gotoxy(40,13);
    cout<<"4. Focus on the Ring Finger keys";
    // cout<<"4. Keys T and O"<<endl;
    gotoxy(40,15);
    cout<<"5. Focus on the Little Finger keys";
    // cout<<"5. Capital letters and Period"<<endl;
    gotoxy(40,17);
    cout<<"6. Common words";

    //cout<<"6. Keys C and Comma"<<endl;
//   gotoxy(40,19);
    //  cout<<"7. Keys G H and Apostrophe"<<endl;
    //  gotoxy(40,21);
    //  cout<<"8. Keys V N and Question Mark"<<endl;
    //  gotoxy(40,23);
    //  cout<<"9. Keys W and M"<<endl;
    //  gotoxy(40,25);
    // cout<<"10. Keys Q and P"<<endl;
    // gotoxy(40,27);
    // cout<<"11. Keys B and Y"<<endl;
    // gotoxy(40,29);
    //  cout<<"12. Keys Z and X"<<endl;
//
    //  cout<<endl;
    gotoxy(40,20);
    cout<<"Select your lesson (1-6) or Enter 0 to return Home or any key to exit:"<<endl;
    //  int lesson;
    //  cin>>lesson;
    char ch;
    ch=getch();
    system("cls");
    switch(ch)
    {
    case '0':
        startMenu(0);
        break;
    case '1':
        lessonNew1(0);
        break;
    case '2':
        lessonNew2(0);
        //   lesson2();
        break;
    case '3':
        lessonNew3(0);
        //lesson3();
        break;
    case '4':
        lessonNew4(0);
        //  lesson4();
        break;
    case '5':
        lessonNew5(0);
        //  lesson5();
        break;
    case '6':
        mostCommonWord(0);
        //  lesson6();
        break;
    default :
        exit(0);
    }
}
