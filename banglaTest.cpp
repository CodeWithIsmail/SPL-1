#include<bits/stdc++.h>
#include<io.h>
#include<fcntl.h>
#include<windows.h>
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
    UnicodeToAvro["099F"]="T";
    UnicodeToAvro["09A0"]="Th";
    UnicodeToAvro["09A1"]="D";
    UnicodeToAvro["09A2"]="Dh";
    UnicodeToAvro["09A3"]="N";
    UnicodeToAvro["09A4"]="t";
    UnicodeToAvro["09A5"]="th";
    UnicodeToAvro["09A6"]="d";
    UnicodeToAvro["09A7"]="dh";
    UnicodeToAvro["09A8"]="n";
    UnicodeToAvro["09AA"]="p";
    UnicodeToAvro["09AB"]="ph";
    UnicodeToAvro["09AC"]="b";
    UnicodeToAvro["09AD"]="bh";
    UnicodeToAvro["09AE"]="m";
    UnicodeToAvro["09AF"]="z";
    UnicodeToAvro["09B0"]="r";
    UnicodeToAvro["09B2"]="l";
    UnicodeToAvro["09B6"]="sh";
    UnicodeToAvro["09B7"]="Sh";
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
        wprintf(L"\n\t\t\t\t লেখুনঃ  %lc\n",unicode_char);

        _setmode(_fileno(stdout),_O_TEXT);
        cout<<"\n\t\t\t\t ";
        string input;
        cin>>input;
        _setmode(_fileno(stdout),_O_U16TEXT);
        if(input==UnicodeToAvro[code])
        {
            correct++;
            wcout<<L"\n\t\t\t\t সঠিক হয়েছে! \n";
        }

        else
        {
            wrong++;
            wcout<<L"\n\t\t\t\t ভুল হয়েছে! \n";
        }
        Sleep(650);
        system("cls");

    }
       _setmode(_fileno(stdout),_O_TEXT);
    bangla_uni_file.close();
    double accuracy=(correct*100)/(correct+wrong);
    cout<<"\n\t\t\t\t Correct Type: "<<correct<<"\n\t\t\t\t  Wrong Type: "<<wrong<<endl;
    cout<<"\n\t\t\t\t Accuracy: "<<accuracy<<endl;


    // _setmode(_fileno(stdout),_O_U16TEXT);
    //   wcout<<L"\t\t \x0987\n";
    //     wcout<<L"\t\t\t\t\t\t ব্যাঞ্জনবর্ণ লেখার নিয়মঃ \n\n";
    //    wcout<<L"\t\t\t\t\t\t ক - k \n\n";
    // _setmode(_fileno(stdout),_O_TEXT);
}

