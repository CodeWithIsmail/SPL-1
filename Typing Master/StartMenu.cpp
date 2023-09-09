#include "AllHeaderFile.h"

void startMenu()
{
    system("cls");
    moveCursor(47,4);

    cout<<"  --------------------------\n";
    cout<<"\t\t\t\t\t\t |     TYPING TUTOR       |\n";
    cout<<"\t\t\t\t\t\t --------------------------\n\n\n";
    cout<<"\t\t\t\t\t\t 1. Typing Tutorial \n\n";
    cout<<"\t\t\t\t\t\t 2. Practice \n\n";
    cout<<"\t\t\t\t\t\t 3. Games \n\n";
    cout<<"\t\t\t\t\t\t 4. Statistics \n\n";
    cout<<"\t\t\t\t\t\t 5. User Manual \n\n";
    cout<<"\t\t\t\t\t\t 6. Exit \n\n\n";
    cout<<"\t\t\t\t\t\t Select option: ";
    char option=getch();

    if(option=='1')
    {
        system("color FD");
        TypingTutorial();
    }
    else if(option=='2');
    else if(option=='3')
    {
        system("color F1");
        game1();
    }
    else if(option=='4')
    {
        system("color ED");
        statistics();
    }
    else if(option=='5')
    {
        system("color FD");
        UserManual();
    }
    else if(option=='6')
    {
        cout<<"Exiting the application...."<<endl;
        exit(0);
    }
    else
    {
        cout<<"Wrong Choice. Try again.";
        startMenu();
    }
}
