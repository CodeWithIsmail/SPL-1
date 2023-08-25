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
        cout<<"1. Typing Tutorial";
        gotoxy(40,11);
        cout<<"2. Practice";
        gotoxy(40,13);
        cout<<"3. Games";
        gotoxy(40,15);
        cout<<"4. Performance History";
        gotoxy(40,17);
        cout<<"5. User Manual";
        gotoxy(40,19);
        cout<<"6. Exit"<<endl;


        gotoxy(40,22);
        cout<<"Select option: "<<endl;;
        char option=getch();

        switch(option)
        {
        case '1':
           // setColor(11);
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
            //history();
            break;
//            UserManual(0);
            break;
        case '5':
//            userManual();
            break;
        case '6':
            cout<<"Exiting the application...."<<endl;
            exit(0);
        default:
            cout<<"Wrong Choice. Try again.";
        }
    }
    while(1);
}
