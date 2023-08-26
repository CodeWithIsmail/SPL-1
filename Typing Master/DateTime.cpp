#include<bits/stdc++.h>
#include<time.h>
#include "DateTime.h"
using namespace std;

string DateTimeGet(int x)
{
    time_t tempTime=time(nullptr);
    tm* currentTime=localtime(&tempTime);
    char time[50],date[50];
    strftime(time,sizeof(time),"%I:%M %p",currentTime);
    strftime(date,sizeof(date),"%d-%b-%Y",currentTime);
    string DT=(string)time+(string)date;
    return DT;
}
