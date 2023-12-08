#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT); // Set console to output UTF-16 text
    _setmode(_fileno(stdin), _O_U16TEXT);
    wstring input;
    getline(wcin,input);
    wcout <<  input << endl;

    wstring output = L"আমি";

    wstringstream ss;
    for (wchar_t character : input)
    {
        ss << hex << setw(4) << setfill(L'0') << static_cast<unsigned int>(character) << L" ";
    }
    wstring hexRepresentation = ss.str();


    if (input == output)
        wcout << L"The strings are equal." << endl;
    else
        wcout << L"The strings are not equal." << endl;
    wcout <<hexRepresentation<< endl;
}
