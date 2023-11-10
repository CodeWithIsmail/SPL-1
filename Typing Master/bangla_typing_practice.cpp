#include"AllHeaderFile.h"



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
        _setmode(_fileno(stdout),_O_U16TEXT);

        int unicode_int_value=stoi(code,0,16);
        wchar_t unicode_char=static_cast<wchar_t>(unicode_int_value);
        wprintf(L"\n\n\n\t\t\t\t\t\t\t লেখুনঃ  %lc\n",unicode_char);

        _setmode(_fileno(stdout),_O_TEXT);
        cout<<"\n\t\t\t\t\t\t\t ";
        string input;
        cin>>input;
        _setmode(_fileno(stdout),_O_U16TEXT);

        if(input==avro_code(code,code_name))
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

void bangla_typing()
{
       system("cls");
    string filename="",code_name="";
    _setmode(_fileno(stdout),_O_U16TEXT);

    wcout<<L"\t\t\t\t\t\t 1. স্বরবর্ণ অনুশীলনঃ \n\n";
    wcout<<L"\t\t\t\t\t\t 2. ব্যাঞ্জনবর্ণ অনুশীলনঃ \n\n";
    wcout<<L"\t\t\t\t\t\t  অপশন সিলেক্ট করুনঃ\n\n";

    char type=getch();
    if(type=='1')
    {
        filename="bangla_1.txt";
        code_name="Avro_Ban_Uni_1.txt";
    }
    else
    {
        filename="bangla.txt";
        code_name="Avro_Ban_Uni.txt";
    }
    system("cls");
    bangla_practice(filename,code_name);

}


