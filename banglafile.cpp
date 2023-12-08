#include <fcntl.h>
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT); // Set console to output UTF-16 text
    _setmode(_fileno(stdin), _O_U16TEXT);
    std::wstring inputString = L"আমার নাম"; // Replace this string with your Unicode text

    // Convert each character in the input string to its 4-digit hexadecimal representation
    std::wstringstream ss;
    for (wchar_t character : inputString) {
        ss << std::hex << std::setw(4) << std::setfill(L'0') << static_cast<unsigned int>(character) << L" ";
    }
    std::wstring hexRepresentation = ss.str();

    // Display the hexadecimal representations
    std::wcout << L"The hexadecimal representation of '" << inputString << L"' is: " << hexRepresentation << std::endl;

    return 0;
}
