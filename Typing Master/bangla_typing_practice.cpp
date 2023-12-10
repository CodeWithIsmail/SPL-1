#include"AllHeaderFile.h"

void bangla_practice_key(string filename)
{
    int correct=0,wrong=0;
    ifstream bangla_uni_file(filename); // file contain the unicode of the char which will be given to user
    string code;
    system("cls");
    while(getline(bangla_uni_file,code))
    {
        drawKeyboard();
        _setmode(_fileno(stdout), _O_U16TEXT); // Set console to output UTF-16 text
        _setmode(_fileno(stdin), _O_U16TEXT); // // Set console to input UTF-16 text

        // read 4 digit hex code and then convert it to bangla char
        int unicode_int_value=stoi(code,0,16);
        wchar_t unicode_char=static_cast<wchar_t>(unicode_int_value);

        moveCursor(50,5);
        wprintf(L" লেখুনঃ  %lc\n",unicode_char);
        moveCursor(59,7);
        wstring input;
        wcin>>input;
        moveCursor(59,9);
        wcout << input << endl;

        // get the 4 digit hex code of input
        wstringstream ss;
        for (wchar_t character : input)
        {
            ss << hex << setw(4) << setfill(L'0') << static_cast<unsigned int>(character) << L"";
        }
        wstring hexRepresentation = ss.str();
        wstring_convert<codecvt_utf8<wchar_t>> converter;
        string normalString = converter.to_bytes(hexRepresentation);

        moveCursor(59,13);
        if(normalString==code)
        {
            correct++;
            wcout<<L"সঠিক হয়েছে! \n";
        }
        else
        {
            wrong++;
            wcout<<L"ভুল হয়েছে! \n";
        }

        Sleep(800);
        system("cls");
        _setmode(_fileno(stdout),_O_TEXT);
    }
    _setmode(_fileno(stdout),_O_TEXT);
    bangla_uni_file.close();

    double accuracy=(correct*100)/(correct+wrong);
    moveCursor(50,10);
    cout<<"Correct Type: "<<correct;
    moveCursor(50,12);
    cout<<"Wrong Type: "<<wrong;
    moveCursor(50,14);
    cout<<"Accuracy: "<<accuracy<<" %";
    moveCursor(50,17);
    cout<<"Press any key to back menu";
    getch();
    startMenu();
}

void bangla_word_type(string filename)
{
    int correct=0,wrong=0;
    system("cls");
    ifstream bangla_uni_file(filename);
    string code;
    while(getline(bangla_uni_file,code))
    {
        drawKeyboard();
        _setmode(_fileno(stdout),_O_U16TEXT);
        _setmode(_fileno(stdin),_O_U16TEXT);

        moveCursor(50,5);
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
        moveCursor(58,7);
        wcin>>input;
        moveCursor(58,9);
        wcout   << input << endl;

        wstringstream ss;
        for (wchar_t character : input)
        {
            ss << hex << setw(4) << setfill(L'0') << static_cast<unsigned int>(character) << L"";
        }
        wstring hexRepresentation = ss.str();
        wstring_convert<codecvt_utf8<wchar_t>> converter;
        string normalString = converter.to_bytes(hexRepresentation);

        moveCursor(55,13);
        if(normalString==code)
        {
            correct++;
            wcout<<L"সঠিক হয়েছে! \n";
        }
        else
        {
            wrong++;
            wcout<<L"ভুল হয়েছে! \n";
        }
        Sleep(800);
        system("cls");
        _setmode(_fileno(stdout),_O_TEXT);
    }
    _setmode(_fileno(stdout),_O_TEXT);
    bangla_uni_file.close();

    double accuracy=(correct*100)/(correct+wrong);
    moveCursor(50,10);
    cout<<"Correct Type: "<<correct;
    moveCursor(50,12);
    cout<<"Wrong Type: "<<wrong;
    moveCursor(50,14);
    cout<<"Accuracy: "<<accuracy<<" %";
    moveCursor(50,17);
    cout<<"Press any key to back menu";
    getch();
    startMenu();
}

void bangla_typing()
{
    system("cls");
    moveCursor(47,4);
    cout<<"  --------------------------\n";
    cout<<"\t\t\t\t\t\t |     TYPING TUTOR       |\n";
    cout<<"\t\t\t\t\t\t --------------------------\n\n\n";

    _setmode(_fileno(stdout),_O_U16TEXT);
    moveCursor(50,10);
    wcout<<L"1. স্বরবর্ণ অনুশীলনঃ \n\n";
    moveCursor(50,12);
    wcout<<L"2. ব্যাঞ্জনবর্ণ অনুশীলনঃ \n\n";
    moveCursor(50,14);
    wcout<<L"3. শব্দ অনুশীলনঃ \n\n";
    moveCursor(50,16);
    wcout<<L"অপশন সিলেক্ট করুনঃ\n\n";

    _setmode(_fileno(stdout),_O_TEXT);
    string filename="";
    char type=getch();
    if(type=='1')
    {
        filename="bangla_soro.txt";
        bangla_practice_key(filename);
    }
    else if(type=='2')
    {
        filename="bangla_benjon.txt";
        bangla_practice_key(filename);
    }
    else if(type=='3')
    {
        filename="bangla_word_1.txt";
        bangla_word_type(filename);
    }
    else
    {
            moveCursor(50,20);
            cout<<"Wrong Key Press.";
            bangla_typing();
    }
}


