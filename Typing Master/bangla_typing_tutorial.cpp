#include"AllHeaderFile.h";
void bangla_tutorial()
{
    system("cls");
    _setmode(_fileno(stdout),_O_U16TEXT);

    wcout<<L"\t\t\t\t\t\t ব্যাঞ্জনবর্ণ লেখার নিয়মঃ \n\n";
    wcout<<L"\t\t\t\t\t\t ব্যঞ্জনবর্ন  লিখতে নিচের ক্রম অনুসরণ করুন:\n\n";

    ifstream bangla("Avro_Ban_Uni.txt");
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

        cout<<avro_code<<"\n\n";
    }
    bangla.close();
    cout<<"\n\n\t\t\t\t\t\t Enter any key to go back menu:";
    getch();
    system("cls");
    startMenu();
}
