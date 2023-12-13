#include "AllHeaderFile.h"

string DateFind()
{
    time_t tempTime=time(nullptr);
    tm* currentTime=localtime(&tempTime);
    char time[50],date[50];
    strftime(time,sizeof(time),"%I:%M %p",currentTime);
    strftime(date,sizeof(date),"%d-%b-%Y",currentTime);
    string DT=(string)date+"  "+(string)time;
    return DT;
}
