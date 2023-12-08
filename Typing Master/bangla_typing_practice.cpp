#include"AllHeaderFile.h"
#include <codecvt>


string avro_code(string unicode,string code_name)
{
    ifstream bangla(code_name);
    string line;
    while(getline(bangla,line))
    {
        bool check=0;
        istringstream comma_separated(line);
        string temp;
        while(getline(comma_separated,temp,','))
        {
            if(check)
            {
                bangla.close();
                return temp;
            }
            if(temp==unicode) check=1;
        }
    }
    return "null";
}

void bangla_practice(string filename,string code_name)
{
    int correct=0,wrong=0;

    ifstream bangla_uni_file(filename);
    string code;
    while(getline(bangla_uni_file,code))
    {

          _setmode(_fileno(stdout), _O_U16TEXT); // Set console to output UTF-16 text
        _setmode(_fileno(stdin), _O_U16TEXT);

        int unicode_int_value=stoi(code,0,16);
        wchar_t unicode_char=static_cast<wchar_t>(unicode_int_value);
        //   wcout<<unicode_char<<endl;
        wprintf(L"\n\n\n\t\t\t\t\t\t\t লেখুনঃ  %lc\n",unicode_char);


        wstring input;
        wcin>>input;
      //  getline(wcin,input);
        wcout <<  input << endl;

       // wstring output = L"আমি";

        wstringstream ss;
        for (wchar_t character : input)
        {
            ss << hex << setw(4) << setfill(L'0') << static_cast<unsigned int>(character) << L"";
        }
        wstring hexRepresentation = ss.str();
        wstring_convert<codecvt_utf8<wchar_t>> converter;
    string normalString = converter.to_bytes(hexRepresentation);


    /*    if (input == output)
            wcout << L"The strings are equal." << endl;
        else
            wcout << L"The strings are not equal." << endl;
            */
      //  wcout <<hexRepresentation<< endl;

        /*    _setmode(_fileno(stdout),_O_TEXT);
            cout<<"\n\t\t\t\t\t\t\t ";
            string input;
            cin>>input;
            _setmode(_fileno(stdout),_O_U16TEXT);
            */

            if(normalString==code)
            {
                correct++;
                wcout<<L"\n\t\t\t\t\t\t\t সঠিক হয়েছে! \n";
            }
            else
            {
                wrong++;
                wcout<<L"\n\t\t\t\t\t\t\t ভুল হয়েছে! \n";
            }

     Sleep(500);
        system("cls");
    }
    _setmode(_fileno(stdout),_O_TEXT);
    bangla_uni_file.close();
    double accuracy=(correct*100)/(correct+wrong);
    cout<<"\n\n\t\t\t\t Correct Type: "<<correct;
    cout<<"\n\n\t\t\t\t  Wrong Type: "<<wrong;
    cout<<"\n\n\t\t\t\t Accuracy: "<<accuracy<<" %";


    cout<<"\n\n\n\t\tPress any key to back menu";
    getch();
    startMenu();
}

void bangla_word_type(string filename)
{
    int correct=0,wrong=0;

    ifstream bangla_uni_file(filename);
    string code;
    while(getline(bangla_uni_file,code))
    {
        drawKeyboard();
        _setmode(_fileno(stdout),_O_U16TEXT);
        moveCursor(50,5);
        wprintf(L"লেখুনঃ  ");

        for(int i=0; i<code.size(); i+=4)
        {
            string token="";
            token+=code[i];
            token+=code[i+1];
            token+=code[i+2];
            token+=code[i+3];
            //    cout<<token<<endl;
            int unicode_int_value=stoi(token,0,16);

            wchar_t unicode_char=static_cast<wchar_t>(unicode_int_value);
            _setmode(_fileno(stdout),_O_U16TEXT);
            wprintf(L"%lc",unicode_char);
        }
        _setmode(_fileno(stdout),_O_TEXT);



        string unicode;
        getline(bangla_uni_file,unicode);

        cout<<"\n\n\n\t\t\t\t\t\t\t\t ";
        string input;
        moveCursor(50,7);
        cin>>input;
        _setmode(_fileno(stdout),_O_U16TEXT);

        moveCursor(50,9);
        if(input==unicode)
        {
            correct++;
            wcout<<L"সঠিক হয়েছে! \n";
        }
        else
        {
            wrong++;
            wcout<<L"ভুল হয়েছে! \n";
        }
        Sleep(500);
        system("cls");
        _setmode(_fileno(stdout),_O_TEXT);
    }
    _setmode(_fileno(stdout),_O_TEXT);
    bangla_uni_file.close();

    double accuracy=(correct*100)/(correct+wrong);
    cout<<"\n\n\t\t\t\t Correct Type: "<<correct;
    cout<<"\n\n\t\t\t\t  Wrong Type: "<<wrong;
    cout<<"\n\n\t\t\t\t Accuracy: "<<accuracy<<" %";

    cout<<"\n\n\n\t\tPress any key to back menu";
    getch();
    startMenu();

}

void bangla_typing()
{
    system("cls");
    string filename="",code_name="";
    _setmode(_fileno(stdout),_O_U16TEXT);

    wcout<<L"\t\t\t\t\t\t 1. স্বরবর্ণ অনুশীলনঃ \n\n";
    wcout<<L"\t\t\t\t\t\t 2. ব্যাঞ্জনবর্ণ অনুশীলনঃ \n\n";
    wcout<<L"\t\t\t\t\t\t 3. শব্দ অনুশীলনঃ \n\n";
    wcout<<L"\t\t\t\t\t\t  অপশন সিলেক্ট করুনঃ\n\n";

    _setmode(_fileno(stdout),_O_TEXT);

    char type=getch();
    if(type=='1')
    {
        filename="bangla_1.txt";
        code_name="bangla_practice_1.txt";
        system("cls");
        bangla_practice(filename,code_name);
    }
    else if(type=='2')
    {
        filename="bangla.txt";
        code_name="bangla_practice_2.txt";
        system("cls");
        bangla_practice(filename,code_name);
    }
    else if(type=='3')
    {
        filename="bangla_word_1.txt";
        system("cls");
        bangla_word_type(filename);

    }


}


