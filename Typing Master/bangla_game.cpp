#include "AllHeaderFile.h"

void bangla_game()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\t\t FAST TYPER";
    cout<<"\n\n\n\t\t\t\t\t Press any key to start the game!";
    getch();

    system("cls");
    string filename="bangla_word_1.txt";
    ifstream file(filename);

    int score=0;

    auto startTime = chrono::high_resolution_clock::now();
    for(;;)
    {
        auto currentTime = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = currentTime - startTime;
        if (duration.count() >= 60.0)
        {
            break;
        }
        system("cls");
        Border();
        drawKeyboard();


        moveCursor(40,5);
        cout<<"Score :"<<score;
        moveCursor(70,5);
        int remain=60-duration.count();
        cout<<"Remaining time: "<<remain;


        string code;
        getline(file,code);


        _setmode(_fileno(stdout),_O_U16TEXT);
        _setmode(_fileno(stdin),_O_U16TEXT);

        moveCursor(55,15);
        wprintf(L"লেখুনঃ  ");
        for(int i=0; i<code.size(); i+=4)
        {
            string token=""; // 4 digit represent each char
            token+=code[i];
            token+=code[i+1];
            token+=code[i+2];
            token+=code[i+3];
            int unicode_int_value=stoi(token,0,16);
            wchar_t unicode_char=static_cast<wchar_t>(unicode_int_value);
            wprintf(L"%lc",unicode_char);
        }

        wstring input;
        moveCursor(58,17);
        wcin>>input;
        moveCursor(58,19);
        wcout   << input << endl;

        wstringstream ss;
        for (wchar_t character : input)
        {
            ss << hex << setw(4) << setfill(L'0') << static_cast<unsigned int>(character) << L"";
        }
        wstring hexRepresentation = ss.str();
        wstring_convert<codecvt_utf8<wchar_t>> converter;
        string normalString = converter.to_bytes(hexRepresentation);

        //    moveCursor(55,21);
        if(normalString==code)
        {
            //    wcout<<L"সঠিক হয়েছে! \n";
            score+=(code.size()/4)*5;
        }
        else
        {
            //   wcout<<L"ভুল হয়েছে! \n";
            score-=(edit_distance(normalString,code)/4)*5;
        }
        _setmode(_fileno(stdout),_O_TEXT);

        Sleep(500);

    }
    _setmode(_fileno(stdout),_O_TEXT);
    file.close();

    system("cls");
    cout<<"\n\n\n\t\t\t\t\t Time's Up!";

    int highestScore=0;
    string highest,temp;
    ifstream scorefile("BanglaScoreList.txt");
    if(getline(scorefile,temp))
    {
        istringstream str(temp);
        getline(str,highest,',');
        highestScore=stoi(highest);
    }

    if(score>highestScore)
    {
        cout<<"\n\n\t\t\t\t\t Congratulations!! New Highest Score!!";
        ofstream scoreList("BanglaScoreList.txt");
        string sc=to_string(score)+",,"+DateFind()+"\n";
        scoreList<<sc;
        scoreList.close();
    }
    else
    {
        cout<<"\n\n\t\t\t\t\t Highest Score: "<<highestScore;
    }
    cout<<"\n\n\t\t\t\t\t Your Score is: "<<score;

    ofstream performance("PerformanceHistory.txt",ios::app);
    string write="Game: Fast Typer Bangla,,"+DateFind()+","+to_string(score)+"\n";
    performance<<write;
    performance.close();

    cout<<"\n\n\t\t\t\t Press 1 to play again or 0 to return Home or 2 to exit.\n\n";
    while(1)
    {
        char ch=getch();
        if(ch=='0')
            startMenu();
        else if(ch=='1')
            bangla_game();
        else if(ch=='2')
            exit(0);
        else
            cout<<"t\t\t\t Wrong Input. Try again.\n";
    }
}
/*
void Border()
{
    drawBorder(35,51,3,7,"+","+");
    drawBorder(45,75,13,21,"+","+");
    drawBorder(65,93,3,7,"+","+");
}
void clearScreen()
{
    moveCursor(48,5);
    cout<<"   ";
    moveCursor(86,5);
    cout<<"   ";
    moveCursor(55,17);
    cout<<"       ";
    moveCursor(55,19);
    cout<<"       ";
}

*/
