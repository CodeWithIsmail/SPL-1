#include<bits/stdc++.h>
#include<io.h>
#include<fcntl.h>
using namespace std;
map<string,string>UnicodeToAvro;
int correct=0,wrong=0;
void mapping()
{
    UnicodeToAvro["0995"]="k";
    UnicodeToAvro["0996"]="kh";
    UnicodeToAvro["0997"]="g";
    UnicodeToAvro["0998"]="gh";
    UnicodeToAvro["0999"]="Ng";
    UnicodeToAvro["099A"]="c";
    UnicodeToAvro["099B"]="ch";
    UnicodeToAvro["099C"]="j";
    UnicodeToAvro["099D"]="jh";
    UnicodeToAvro["099E"]="NG";

}
int main()
{

    ifstream bangla_uni_file("bangla.txt");
    string code;
    mapping();
    while(getline(bangla_uni_file,code))
    {
        _setmode(_fileno(stdout),_O_U16TEXT);
        // cout<<code<<"\n";
        int unicode_int_value=stoi(code,0,16);
        wchar_t unicode_char=static_cast<wchar_t>(unicode_int_value);
        wprintf(L"লেখুনঃ  %lc\n",unicode_char);

        _setmode(_fileno(stdout),_O_TEXT);
        string input;
        cin>>input;
        if(input==UnicodeToAvro[code]) correct++;
        else wrong++;

    }
    cout<<correct<<" "<<wrong<<endl;

    bangla_uni_file.close();
    //    system("cls");
    // _setmode(_fileno(stdout),_O_U16TEXT);

//   wcout<<L"\t\t \x0987\n";
    //    moveCursor(20,5);
    //     wcout<<L"\t\t\t\t\t\t ব্যাঞ্জনবর্ণ লেখার নিয়মঃ \n\n";
    //    wcout<<L"\t\t\t\t\t\t ক - k \n\n";
    // _setmode(_fileno(stdout),_O_TEXT);
}

