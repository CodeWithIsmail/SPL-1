#include "AllHeaderFile.h";
using namespace std;
void read_from_bangla_file(string filename);
void new_read_method(string filename);
void bangla_tutorial()
{
    string filename = "";
    system("cls");
    cout << "\n\n\n\n";

    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    wcout << L"\t\t\t\t\t\t 1. স্বরবর্ণ লেখার নিয়মঃ \n\n";
    wcout << L"\t\t\t\t\t\t 2. ব্যাঞ্জনবর্ণ লেখার নিয়মঃ \n\n";
    wcout << L"\t\t\t\t\t\t 3. ব্যঞ্জনবর্ণের সংক্ষিপ্ত রুপ (ফলা) ও অন্যান্য লেখার নিয়মঃ \n\n";
    wcout << L"\t\t\t\t\t\t  অপশন সিলেক্ট করুনঃ\n\n";

    wstring option;
    wcin >> option;
    string type = bangla_tounicode(option);

    system("cls");

    if (type == "09e7")
    {
        filename = "bangla_tutorial_1.txt";
    }
    else if (type == "09e8")
    {
        filename = "bangla_tutorial_2.txt";
    }
    else if (type == "09e9")
    {
        filename = "bangla_tutorial_3.txt";
    }
    else
    {
        wcout << L"\t\t\t\t\t\t  ভুল ইনপুট। আবার চেষ্টা করুনঃ\n\n";
        bangla_tutorial();
    }
    new_read_method(filename);

    cout << "\n\n\t\t\t\t\t\t Enter any key to go back menu:";
    getch();
    system("cls");
    startMenu();
}

void read_from_bangla_file(string filename)
{
    ifstream bangla(filename);
    string line;
    while (getline(bangla, line))
    {
        int index;
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == ',')
                index = i;
        }

        string code = line.substr(0, index);
        string avro_code = line.substr(index + 1);

        _setmode(_fileno(stdout), _O_U16TEXT);

        int unicode_int_value = stoi(code, 0, 16);
        wchar_t unicode_char = static_cast<wchar_t>(unicode_int_value);
        wprintf(L"\n\n\t\t\t\t\t\t   %lc : ", unicode_char);

        _setmode(_fileno(stdout), _O_TEXT);

        cout << avro_code << "\n";
    }
    bangla.close();
}

void new_read_method(string filename)
{
    _setmode(_fileno(stdout), _O_U16TEXT); // set the console output to Bangla
    ifstream bangla_uni_file(filename);
    string code;
    while (getline(bangla_uni_file, code)) // read the hexadecimal unicode form file
    {
        for (int i = 0; i < code.size(); i += 4)
        {
            string token = "";
            token = code.substr(i, 4); // take 4 digit hexadecimal unicode
            int unicode_int_value = stoi(token, 0, 16); // convert the hexadecimal unicode into integer
            wchar_t unicode_char = static_cast<wchar_t>(unicode_int_value);
            // converting unicode code to wide character
            wprintf(L"%lc", unicode_char); // print the wide character
        }
    }
    _setmode(_fileno(stdout), _O_TEXT);
}
string bangla_tounicode(wstring key)
{
    // get the 4 digit hex code of input
    wstringstream ss;
    for (wchar_t character : key)
    {
        ss << hex << setw(4) << setfill(L'0') << static_cast<unsigned int>(character) << L"";
    }
    wstring hexRepresentation = ss.str();
    wstring_convert<codecvt_utf8<wchar_t>> converter;
    string normalString = converter.to_bytes(hexRepresentation);

    return normalString;
}
