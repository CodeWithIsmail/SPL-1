#include "AllHeaderFile.h"
char dataset1[7]={'a','s','d','f','j','k','l'};
void startMenu()
{

    system("cls");
    moveCursor(47,4);

    cout<<"  --------------------------\n";
    cout<<"\t\t\t\t\t\t |     TYPING TUTOR       |\n";
    cout<<"\t\t\t\t\t\t --------------------------\n\n\n";
    cout<<"\t\t\t\t\t\t 1. Typing Tutorial \n\n";
    _setmode(_fileno(stdout),_O_U16TEXT);
    wcout<<L"\t\t\t\t\t\t ২। বাংলা টাইপিং \n\n";
    _setmode(_fileno(stdout),_O_TEXT);
    cout<<"\t\t\t\t\t\t 3. Games \n\n";
    cout<<"\t\t\t\t\t\t 4. Statistics \n\n";
    cout<<"\t\t\t\t\t\t 5. User Manual \n\n";
    cout<<"\t\t\t\t\t\t 6. Key Practice \n\n\n";
    cout<<"\t\t\t\t\t\t Select option: ";
    char option=getch();

    if(option=='1')
    {
        system("color FD");
        TypingTutorial();
    }
    else if(option=='2')
        bangla_tutorial();
    // not developed yet

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
       time_prac(dataset1,7,60);
        system("cls");

      /*  cout<<"\n\t\t\t\t\t\tYour score: "<<score<<endl;
        getch();
        system("cls");
         startMenu(); */
      //  cout<<"Exiting the application...."<<endl;
        //exit(0);
    }
    else
    {
        cout<<"Wrong Choice. Try again.";
        startMenu();
    }
}
