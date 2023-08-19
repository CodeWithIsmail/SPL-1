#include"StartMenu.h"
#include"TypingTutorial.h"
#include"FastTyperGame.h"
#include "set_cursor.h"

#include<iostream>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<bits/stdc++.h>

/*char dataset1[8]= {'a','s','d','f','j','k','l',';'};
char dataset2[10]= {'a','s','d','f','j','k','l',';','e','i'};
char dataset3[12]= {'a','s','d','f','j','k','l',';','e','i','r','u'};
char dataset4[14]= {'a','s','d','f','j','k','l',';','e','i','r','u','t','o'};
char dataset6[16]= {'a','s','d','f','j','k','l',';','e','i','r','u','t','o','c',','};
char dataset7[18]= {'a','s','d','f','j','k','l',';','e','i','r','u','t','o','c',',','g','h'};
char dataset8[21]= {'a','s','d','f','j','k','l',';','e','i','r','u','t','o','c',',','g','h','v','n','?'};
char dataset9[23]= {'a','s','d','f','j','k','l',';','e','i','r','u','t','o','c',',','g','h','v','n','?','w','m'};
char dataset10[25]= {'a','s','d','f','j','k','l',';','e','i','r','u','t','o','c',',','g','h','v','n','?','w','m','q','p'};
char dataset11[27]= {'a','s','d','f','j','k','l',';','e','i','r','u','t','o','c',',','g','h','v','n','?','w','m','q','p','b','y'};
char dataset12[29]= {'a','s','d','f','j','k','l',';','e','i','r','u','t','o','c',',','g','h','v','n','?','w','m','q','p','b','y','z','x'};
char datasetTotal[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
*/
using namespace std;

void startMenu(int x)
{
    do
    {
        system("cls");
        gotoxy(40,5);
        cout<<"--------------------------";
        gotoxy(40,6);
        cout<<"|     TYPING TUTOR       |";
        gotoxy(40,7);
        cout<<"--------------------------";
        gotoxy(40,9);
        cout<<"1. Typing Tutorial"<<endl;
        gotoxy(40,11);
        cout<<"2. Practice"<<endl;
        gotoxy(40,13);
        cout<<"3. Games"<<endl;
        gotoxy(40,15);
        cout<<"4. User Manual"<<endl;
        gotoxy(40,17);
        cout<<"5. Exit"<<endl;

        gotoxy(40,20);
        cout<<"Select option: "<<endl;;
        char option=getch();

        switch(option)
        {
        case '1':
            TypingTutorial(0);
            break;
        case '2':
           // lessonNew1(0);
         //  keyDrill(dataset1,8);
            //  Practice();
            break;
        case '3':
           // lessonNew2(0);
             game1();
            break;
        case '4':
//            UserManual(0);
            break;
        case '5':
            cout<<"Exiting the application...."<<endl;
            exit(0);
        }
    }
    while(1);
}
