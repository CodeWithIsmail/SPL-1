#include"AllHeaderFile.h";
void read_from_bangla_file(string filename);
void new_read_method(string filename);
void bangla_tutorial()
{
    string filename="";
    system("cls");

    _setmode(_fileno(stdout),_O_U16TEXT);

    wcout<<L"\t\t\t\t\t\t 1. স্বরবর্ণ লেখার নিয়মঃ \n\n";
    wcout<<L"\t\t\t\t\t\t 2. ব্যাঞ্জনবর্ণ লেখার নিয়মঃ \n\n";
    wcout<<L"\t\t\t\t\t\t 3. ব্যঞ্জনবর্ণের সংক্ষিপ্ত রুপ (ফলা) ও অন্যান্য লেখার নিয়মঃ \n\n";
    wcout<<L"\t\t\t\t\t\t 4. যুক্তাক্ষর লেখার নিয়মঃ \n\n";
    wcout<<L"\t\t\t\t\t\t  অপশন সিলেক্ট করুনঃ\n\n";

    char type=getch();
    system("cls");

    if(type=='1')
    {
        filename="bangla_tutorial_1.txt";
    }
    else if(type=='2')
    {
        filename="bangla_tutorial_2.txt";
    }
else if(type=='3')
    {
        filename="bangla_tutorial_3.txt";
    }
    else
    {
        system("cls");
        filename="Avro_Ban_Uni.txt";
        wcout<<L"\t\t\t\t\t\t ব্যাঞ্জনবর্ণ লেখার নিয়মঃ \n\n";
        wcout<<L"\t\t\t\t\t\t ব্যঞ্জনবর্ন  লিখতে নিচের ক্রম অনুসরণ করুন:\n\n";
    }
    new_read_method(filename);

    cout<<"\n\n\t\t\t\t\t\t Enter any key to go back menu:";
    getch();
    system("cls");
    startMenu();
}

void read_from_bangla_file(string filename)
{
    ifstream bangla(filename);
    string line;
    while(getline(bangla,line))
    {
        int index;
        for(int i=0; i<line.size(); i++)
        {
            if(line[i]==',')
                index=i;
        }

        string code=line.substr(0,index);
        string avro_code=line.substr(index+1);

        _setmode(_fileno(stdout),_O_U16TEXT);

        int unicode_int_value=stoi(code,0,16);
        wchar_t unicode_char=static_cast<wchar_t>(unicode_int_value);
        wprintf(L"\n\n\t\t\t\t\t\t   %lc : ",unicode_char);

        _setmode(_fileno(stdout),_O_TEXT);

        cout<<avro_code<<"\n";
    }
    bangla.close();
}

void new_read_method(string filename)
{
    ifstream bangla_uni_file(filename);
    string code;
    _setmode(_fileno(stdout),_O_U16TEXT);
    while(getline(bangla_uni_file,code))
    {
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
    }
}
