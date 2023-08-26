/*#include"StartMenu.h"
#include"set_cursor.h"
#include"TypingTutorial.h"

#include<windows.h>
#include<conio.h>
#include<bits/stdc++.h>
*/
#include "AllHeaderFile.h"
using namespace std;

void TypingTutorial()
{
    system("cls");

    gotoxy(50,4);
    cout<<"\t LESSONS:\n\n\n";
    cout<<"\t\t\t\t\t\t 1. Focus on the Home Row\n\n";
    cout<<"\t\t\t\t\t\t 2. Focus on the Index Finger keys\n\n";
    cout<<"\t\t\t\t\t\t 3. Focus on the Middle Finger keys\n\n";
    cout<<"\t\t\t\t\t\t 4. Focus on the Ring Finger keys\n\n";
    cout<<"\t\t\t\t\t\t 5. Focus on the Little Finger keys\n\n";
    cout<<"\t\t\t\t\t\t 6. Common words\n\n\n";
    cout<<"\t\t\t\t\t\t Select your lesson (1-6) or Enter 0 to return Home or any key to exit:\n\n";

    char ch=getch();
    system("cls");

    if(ch=='0')
        startMenu();
    else if(ch=='1')
        lessonNew1();
    else if(ch=='2')
        lessonNew2();
    else if(ch=='3')
        lessonNew3();
    else if(ch=='4')
        lessonNew4();
    else if(ch=='5')
        lessonNew5();
    else if(ch=='6')
        mostCommonWord();
    else
        exit(0);
}

