#include "AllHeaderFile.h"
// char dataset1[7]= {'a','s','d','f','j','k','l'};
void startMenu()
{
    system("cls");

    cout << "\n\n\n\n\t\t\t\t\t\t --------------------------\n";
    cout << "\t\t\t\t\t\t |     TYPING TUTOR       |\n";
    cout << "\t\t\t\t\t\t --------------------------\n\n\n";

    moveCursor(50, 15);
    cout << "Select Language";
    moveCursor(50, 17);
    cout << "1. Bangla";
    moveCursor(50, 19);
    cout << "2. English";
    moveCursor(50, 23);
    char ln = getche();
    if (ln == '1')
        bangla_homepage();
    else if (ln == '2')
        english_homepage();
    else
    {
        cout << "Wrong Input. Try again!";
        Sleep(500);
        startMenu();
    }
}
void bangla_homepage()
{
    system("cls");
    system("color ED");

    cout << "\n\n\t\t\t\t\t\t --------------------------\n";
    cout << "\t\t\t\t\t\t |     TYPING TUTOR       |\n";
    cout << "\t\t\t\t\t\t --------------------------\n\n\n";

    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"\t\t\t\t\t\t ১। বাংলা টাইপিং টিউটোরিয়াল\n\n";
    wcout << L"\t\t\t\t\t\t ২। বাংলা টাইপিং অনুশীলন\n\n";
    wcout << L"\t\t\t\t\t\t ৩। বাংলা টাইপিং গেইম\n\n";
    _setmode(_fileno(stdout), _O_TEXT);
    cout << "\t\t\t\t\t\t 4. Performance Statsitics \n\n";
    cout << "\t\t\t\t\t\t 5. User Manual \n\n";
    cout << "\t\t\t\t\t\t 6. Exit \n\n";

    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);

    moveCursor(50, 20);

    wstring option;
    wcin >> option;

    // get the 4 digit hex code of input
    wstringstream ss;
    for (wchar_t character : option)
    {
        ss << hex << setw(4) << setfill(L'0') << static_cast<unsigned int>(character) << L"";
    }
    wstring hexRepresentation = ss.str();
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    string normalString = converter.to_bytes(hexRepresentation);

    _setmode(_fileno(stdout), _O_TEXT);
    _setmode(_fileno(stdout), _O_TEXT);

    moveCursor(40, 23);
  //  cout << normalString << " ";
    Sleep(2000);
    if (normalString == "09e7")
    {
             system("color FD");
        bangla_tutorial();
    }
    else if (normalString == "09e8")
    {

        bangla_typing();
    }
    else if (normalString == "09e9")
    {
        bangla_game();
    }
    else if (normalString == "09ea")
    {
        statistics();
    }
    else if (normalString == "09eb")
    {
        UserManual();
    }
    else if (normalString == "09ec")
        exit(0);
    else
    {
        cout << "Wrong Choice. Try again.";
        bangla_homepage();
    }
}
void english_homepage()
{
    system("cls");
    system("color ED");

    cout << "\n\n\t\t\t\t\t\t --------------------------\n";
    cout << "\t\t\t\t\t\t |     TYPING TUTOR       |\n";
    cout << "\t\t\t\t\t\t --------------------------\n\n\n";

    cout << "\t\t\t\t\t\t 1. Typing Tutorial \n\n";
    cout << "\t\t\t\t\t\t 2. Typing Practice \n\n";
    cout << "\t\t\t\t\t\t 3. Typing Games \n\n";
    cout << "\t\t\t\t\t\t 4. Statistics \n\n";

    char option = getche();
    if (option == '1')
    {
        system("color FD");
        TypingTutorial();
    }
    if (option == '2')
    {
        system("cls");
        cout << "\n\n\t\t\t\t Select practice type: ";
        cout << "\n\n\t\t\t\t 1. Key Drill ";
        cout << "\n\n\t\t\t\t 2. Word Drill ";
        cout << "\n\n\t\t\t\t 3. Text Drill ";
        cout << "\n\n\t\t\t\t Select practice type: ";

        int type, sec;
        cin >> type;
        cout << "\n\n\t\t\t\t Enter practice time in seconds: ";
        cin >> sec;
        system("cls");

        if (type == 1)
            time_prac_key(sec);
        else
            time_prac_word(sec);
        system("cls");

        system("cls");
        english_homepage();
    }
    else if (option == '3')
    {
        game1();
    }
    else if (option == '4')
    {
        system("color ED");
        statistics();
    }
    else if (option == '5')
    {
        system("color FD");
        UserManual();
    }
    else if (option == '6')
    {
        exit(0);
    }
    else
    {
        cout << "Wrong Choice. Try again.";
        startMenu();
    }
}
void startMenuI()
{

    system("cls");
    moveCursor(47, 4);

    cout << "  --------------------------\n";
    cout << "\t\t\t\t\t\t |     TYPING TUTOR       |\n";
    cout << "\t\t\t\t\t\t --------------------------\n\n\n";
    cout << "\t\t\t\t\t\t 1. Typing Tutorial \n\n";

    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"\t\t\t\t\t\t ২। বাংলা টাইপিং \n\n";
    _setmode(_fileno(stdout), _O_TEXT);

    cout << "\t\t\t\t\t\t 3. Games \n\n";
    cout << "\t\t\t\t\t\t 4. Statistics \n\n";
    cout << "\t\t\t\t\t\t 5. User Manual \n\n";
    cout << "\t\t\t\t\t\t 6. Practice \n\n";

    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"\t\t\t\t\t\t ৭। বাংলা টাইপিং অনুশীলন \n\n";
    _setmode(_fileno(stdout), _O_TEXT);

    cout << "\t\t\t\t\t\t 8. Exit \n\n\n";
    cout << "\t\t\t\t\t\t Select option: ";
    char option = getch();

    if (option == '1')
    {
        system("color FD");
        TypingTutorial();
    }
    else if (option == '2')
    {
        bangla_tutorial();
    }
    // not fully developed yet

    else if (option == '3')
    {
        system("color F1");
        system("cls");
        moveCursor(50, 15);
        cout << "Select language:";
        moveCursor(50, 17);
        cout << "1. English";
        moveCursor(50, 19);
        cout << "2. Bangla";
        char ln = getche();

        if (ln == '1')
            game1();
        else if (ln == '2')
            bangla_game();
        else
        {
            cout << "Wrong choice. Try again";
            startMenu();
        }
    }
    else if (option == '4')
    {
        system("color ED");
        statistics();
    }
    else if (option == '5')
    {
        system("color FD");
        UserManual();
    }
    else if (option == '6')
    {
        system("cls");
        int sec;
        cout << "\n\n\t\t\t\t Select practice type: ";
        cout << "\n\n\t\t\t\t 1. Key Drill ";
        cout << "\n\n\t\t\t\t 2. Word Drill ";
        cout << "\n\n\t\t\t\t 3. Text Drill ";
        int type;
        cout << "\n\n\t\t\t\t Select practice type: ";
        cin >> type;

        cout << "\n\n\t\t\t\t Enter practice time in seconds: ";
        cin >> sec;
        system("cls");

        if (type == 1)
            time_prac_key(sec);
        else
            time_prac_word(sec);
        system("cls");

        /*  cout<<"\n\t\t\t\t\t\tYour score: "<<score<<endl;
          getch();
          system("cls");
           startMenu(); */
        //  cout<<"Exiting the application...."<<endl;
        // exit(0);
        system("cls");
        startMenu();
    }
    else if (option == '7')
    {
        //    system("color FD");
        system("color FD");
        bangla_typing();
    }
    else if (option == '8')
    {
        exit(0);
    }
    else
    {
        cout << "Wrong Choice. Try again.";
        startMenu();
    }
}
