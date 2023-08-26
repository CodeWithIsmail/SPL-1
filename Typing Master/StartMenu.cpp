/*#include"StartMenu.h"
#include"TypingTutorial.h"
#include"FastTyperGame.h"
#include "set_cursor.h"
#include "PerformanceHistory.h"
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

#include "AllHeaderFile.h"
using namespace std;

void startMenu(int x)
{
    system("cls");
    gotoxy(47,4);

    cout<<"  --------------------------\n";
    cout<<"\t\t\t\t\t\t |     TYPING TUTOR       |\n";
    cout<<"\t\t\t\t\t\t --------------------------\n\n\n";

    cout<<"\t\t\t\t\t\t 1. Typing Tutorial \n\n";
    cout<<"\t\t\t\t\t\t 2. Practice \n\n";
    cout<<"\t\t\t\t\t\t 3. Games \n\n";
    cout<<"\t\t\t\t\t\t 4. Performance History \n\n";
    cout<<"\t\t\t\t\t\t 5. User Manual \n\n";
    cout<<"\t\t\t\t\t\t 6. Exit \n\n\n";

    cout<<"\t\t\t\t\t\t Select option: ";
    char option=getch();

    if(option=='1')
        TypingTutorial(0);
    else if(option=='2');
    else if(option=='3')
        game1();
    else if(option=='4')
        history();
    else if(option=='5');
    //UserManual(0);
    else if(option=='6')
    {
        cout<<"Exiting the application...."<<endl;
        exit(0);
    }
    else
    {
        cout<<"Wrong Choice. Try again.";
        startMenu(0);
    }
}
