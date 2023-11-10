#include"AllHeaderFile.h";
void read_from_bangla_file(string filename);
void bangla_tutorial()
{
    string filename="";
    system("cls");

    _setmode(_fileno(stdout),_O_U16TEXT);

    wcout<<L"\t\t\t\t\t\t 1. স্বরবর্ণ লেখার নিয়মঃ \n\n";
    wcout<<L"\t\t\t\t\t\t 2. ব্যাঞ্জনবর্ণ লেখার নিয়মঃ \n\n";
    wcout<<L"\t\t\t\t\t\t  অপশন সিলেক্ট করুনঃ\n\n";

    char type=getch();
    if(type=='1')
    {
        system("cls");
        filename="Avro_Ban_Uni_1.txt";
        wcout<<L"\t\t\t\t\t\t স্বরবর্ণ লেখার নিয়মঃ \n\n";
        wcout<<L"\t\t\t\t\t\t স্বরবরর্ণ  লিখতে নিচের ক্রম অনুসরণ করুন:\n\n";
    }
    else
    {
        system("cls");
        filename="Avro_Ban_Uni.txt";
        wcout<<L"\t\t\t\t\t\t ব্যাঞ্জনবর্ণ লেখার নিয়মঃ \n\n";
        wcout<<L"\t\t\t\t\t\t ব্যঞ্জনবর্ন  লিখতে নিচের ক্রম অনুসরণ করুন:\n\n";
    }
    read_from_bangla_file(filename);

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
