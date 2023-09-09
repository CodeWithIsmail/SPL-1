#include "AllHeaderFile.h"

void mostCommonWord()
{
    cout<<"\n\n\t\t\t Accuracy goal 95%";
    cout<<"\n\n\t\t\t Objective: Learn to fluently type some of the most common English words\n\n";
    cout<<"\n\n\t\t\t Press any key to start.\n\n";
    char ch;
    ch=getch();

    system("cls");
    drawBorder(40,65,3,7,"-","|");
    drawKeyboard();

    int gross=0,wrong=0,total=50,score=0;

    ifstream inputFile("MostCommonEnglishWord.txt");
    string out;

    while (getline(inputFile, out))
    {
        moveCursor(53,5);
        cout<<"            "<<endl;
        moveCursor(53,8);
        cout<<"            "<<endl;
        moveCursor(53,5);
        cout<<out<<endl;
        moveCursor(53,8);

        int index=0;
        while(index<out.length())
        {
            char ch=_getch();
            gross++;
            if(ch==out[index])
            {
                cout<<ch;
                index++;
            }
            else
                wrong++;
        }
    }
    inputFile.close();

    score=gross-wrong;
    int accuracy=(score*100)/gross;
    system("cls");
    cout<<"\n\n\n\n\t\t\t\t\t\t Total Key Press: "<<gross;
    cout<<"\n\n\t\t\t\t\t\t Wrong Key Press: "<<wrong;
    cout<<"\n\n\t\t\t\t\t\t Accuracy: "<<accuracy<<"%";

    ofstream performance("PerformanceHistory.txt",ios::app);
    string write="Common Word,,"+DateFind()+","+to_string(gross)+","+to_string(wrong)+","+to_string(accuracy)+"%\n";
    performance<<write;
    performance.close();

    cout<<"\n\n\t\t\t\t\t\t Press 1 to return home or any key exit.";

    char temp=getch();
    if(temp=='1')
        startMenu();
    else
        exit(0);
}
