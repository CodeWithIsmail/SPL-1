#include"AllHeaderFile.h"



string avro_code(string unicode)
{
    ifstream bangla("Avro_Ban_Uni.txt");
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

void bangla_typing()
{
       int correct=0,wrong=0;
    system("cls");
    ifstream bangla_uni_file("bangla.txt");
    string code;
    while(getline(bangla_uni_file,code))
    {
        _setmode(_fileno(stdout),_O_U16TEXT);

        int unicode_int_value=stoi(code,0,16);
        wchar_t unicode_char=static_cast<wchar_t>(unicode_int_value);
        wprintf(L"\n\t\t\t\t লেখুনঃ  %lc\n",unicode_char);

        _setmode(_fileno(stdout),_O_TEXT);
        cout<<"\n\t\t\t\t ";
        string input;
        cin>>input;
        _setmode(_fileno(stdout),_O_U16TEXT);

        if(input==avro_code(code))
        {
            correct++;
            wcout<<L"\n\t\t\t\t সঠিক হয়েছে! \n";
        }
        else
        {
            wrong++;
            wcout<<L"\n\t\t\t\t ভুল হয়েছে! \n";
        }
        Sleep(500);
        system("cls");
    }
    _setmode(_fileno(stdout),_O_TEXT);
    bangla_uni_file.close();
    double accuracy=(correct*100)/(correct+wrong);
    cout<<"\n\t\t\t\t Correct Type: "<<correct<<"\n\t\t\t\t  Wrong Type: "<<wrong<<endl;
    cout<<"\n\t\t\t\t Accuracy: "<<accuracy<<endl;


     cout<<"\n\n\n\t\tPress any key to back menu";
    getch();
    startMenu();

    // _setmode(_fileno(stdout),_O_U16TEXT);
    //   wcout<<L"\t\t \x0987\n";
    //     wcout<<L"\t\t\t\t\t\t ব্যাঞ্জনবর্ণ লেখার নিয়মঃ \n\n";
    //    wcout<<L"\t\t\t\t\t\t ক - k \n\n";
    // _setmode(_fileno(stdout),_O_TEXT);
}

