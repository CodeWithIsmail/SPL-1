#include<bits/stdc++.h>
#include<io.h>
#include<fcntl.h>
using namespace std;
int main()
{
    _setmode(_fileno(stdout),_O_U16TEXT);
 //   wprintf(L"Hello world\nআমার নাম ইসমাইল\n");
  //  wprintf(L"বাংলা টাইপিং অনুশীলন");
  wcout<<L"আমার নাম ইসমাইল\n";
  wstring unistr;
  getline(wcin,unistr);
  wcout<<L"আপনি লিখেছেনঃ "<<unistr<<"\n";

}
