#include "AllHeaderFile.h"
//char dataset1[7]= {'a','s','d','f','j','k','l'};
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
    cout<<"\t\t\t\t\t\t 6. Practice \n\n";

    _setmode(_fileno(stdout),_O_U16TEXT);
    wcout<<L"\t\t\t\t\t\t ৭। বাংলা টাইপিং অনুশীলন \n\n";
    _setmode(_fileno(stdout),_O_TEXT);

    cout<<"\t\t\t\t\t\t 8. Exit \n\n\n";
    cout<<"\t\t\t\t\t\t Select option: ";
    char option=getch();

    if(option=='1')
    {
        system("color FD");
        TypingTutorial();
    }
    else if(option=='2')
    {
        bangla_tutorial();
    }
    // not fully developed yet

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
        system("cls");
        int sec;
        cout<<"\n\n\t\t\t\t Select practice type: ";
        cout<<"\n\n\t\t\t\t 1. Key Drill ";
        cout<<"\n\n\t\t\t\t 2. Word Drill ";
        cout<<"\n\n\t\t\t\t 3. Text Drill ";
        int type;
        cout<<"\n\n\t\t\t\t Select practice type: ";
        cin>>type;

        cout<<"\n\n\t\t\t\t Enter practice time in seconds: ";
        cin>>sec;
        system("cls");

        if(type==1)
            time_prac_key(sec);
        else  time_prac_word( sec);
        system("cls");

        /*  cout<<"\n\t\t\t\t\t\tYour score: "<<score<<endl;
          getch();
          system("cls");
           startMenu(); */
        //  cout<<"Exiting the application...."<<endl;
        //exit(0);
        system("cls");
        startMenu();
    }
    else if(option=='7')
    {
        //    system("color FD");
        system("color FD");
        bangla_typing();
    }
    else if(option=='8')
    {
        exit(0);
    }
    else
    {
        cout<<"Wrong Choice. Try again.";
        startMenu();
    }
}
