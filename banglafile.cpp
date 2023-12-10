#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>

size_t GetSizeOfFile(const std::wstring& path) {
    return static_cast<size_t>(std::filesystem::file_size(path));
}

std::wstring LoadUtf8FileToString(const std::wstring& filename) {
    std::wstring buffer;  // stores file contents

    std::wifstream wif(filename, std::ios::binary); // Open file in binary mode

    if (!wif.is_open()) {
        std::wcerr << L"Unable to open file" << std::endl;
        return buffer; // Return an empty buffer on failure
    }

    size_t filesize = GetSizeOfFile(filename);

    // Read entire file contents into memory
    if (filesize > 0) {
        buffer.resize(filesize / sizeof(wchar_t)); // Resize to hold wchar_t characters
        wif.read(reinterpret_cast<wchar_t*>(&buffer[0]), filesize); // Read file contents
    }

    return buffer;
}

int main() {
    std::wstring mytext = LoadUtf8FileToString(L"banglafile.txt");
    std::wcout << mytext;
    return 0;
}
