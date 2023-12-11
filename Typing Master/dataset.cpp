#include "AllHeaderFile.h"

string keyMapping(char input)
{
    if(input=='a')
        return "left little finger";
    if(input=='s')
        return "left ring finger";
    if(input=='d')
        return "left middle finger";
    if(input=='f')
        return "left index finger";
    if(input=='j')
        return "right index finger";
    if(input=='k')
        return "right middle finger";
    if(input=='l')
        return "right ring finger";
    if(input==';')
        return "right little finger";
    if(input=='e')
        return "left middle finger";
    if(input=='i')
        return "right middle finger";
    if(input=='r')
        return "left index finger";
    if(input=='u')
        return "right index finger";
    if(input=='t')
        return "left index finger";
    if(input=='o')
        return "right ring finger";
    if(input=='c')
        return "left middle finger";
    if(input=='e')
        return "left middle finger";
    if(input==',')
        return "right middle finger";
    if(input=='h')
        return "right index finger";
    if(input=='g')
        return "left index finger";
    if(input=='n')
        return "right index finger";
    if(input=='v')
        return"left index finger";
    if(input=='w')
        return "left ring finger";
    if(input=='m')
        return "right index finger";
    if(input=='q')
        return "left little finger";
    if(input=='p')
        return "right little finger";
    if(input=='b')
        return "left index finger";
    if(input=='y')
        return "right index finger";
    if(input=='z')
        return "left little finger";
    if(input=='x')
        return "left ring finger";
}

void lesson(char input)
{
    moveCursor(10,5);
    string temp=keyMapping(input);
    cout<<"Now try typing '"<<input<<"' with "<<temp<<".";

    for(;;)
    {
        char ch=getch();
        if(ch==input)
        {
            system("cls");
            break;
        }
        else
        {
            moveCursor(10,7);
            cout<<"Try again.";
        }
    }
}

void keyDrill(char dataset[],int limit,int lessonNum,int partNum)
{
    system("color F1");

    cout<<"\n\n\n\n\t\t\t Objective: Practice to develop smooth and accurate keystrokes and even rhythm.";
    cout<<"\n\n\t\t\t Accuracy goal: 94%";
    cout<<"\n\n\n\t\t\t Enter any key to start"<<endl;
    getch();

    system("cls");
    drawBorder(40,50,3,7,"-","|");
    drawKeyboard();

    int wrongPressCount[limit]= {0};
    int score=0,total=25,wrong=0;
    srand(time(NULL));

    for(int i=0; i<total; i++)
    {
        int index=rand()%limit;
        moveCursor(45,5);
        cout<<dataset[index]<<endl;

        while(1)
        {
            char ch=getch();
            if(ch==dataset[index])
            {
                score++;
                break;
            }
            else
            {
                wrong++;
                wrongPressCount[index]++;
                moveCursor(40,9);
                cout<<"Wrong Input. Try again.";
                moveCursor(40,11);
                cout<<"Use your "<<keyMapping(dataset[index])<<".";
            }
        }
        moveCursor(45,5);
        cout<<"  "<<endl;
        moveCursor(40,9);
        cout<<"                                  ";
        moveCursor(40,11);
        cout<<"                                   ";
    }
    score-=wrong;
    int accuracy=(score*100)/total;
    system("cls");

    cout<<"\n\n\n\t\t\t\t\t Wrong Press key: "<<wrong<<" times.";
    cout<<"\n\n\t\t\t\t\t Your score: "<<score;
    cout<<"\n\n\t\t\t\t\t Your accuracy: "<<accuracy<<" %"<<endl;

    cout<<"\n\n\t\t\t\t\t";
    accuracy>93? cout<<"Very Good\n": cout<<"Try to improve\n";
    cout<<endl;

    drawHistogram(dataset, limit,wrongPressCount);

    ofstream performance("PerformanceHistory.txt",ios::app);
    string write=to_string(lessonNum)+"."+to_string(partNum)+",,"+DateFind()+","
                 +to_string(total+wrong)+","+to_string(wrong)+","+to_string(accuracy)+","+to_string(score)+"\n";
    performance<<write;
    performance.close();

    cout<<"\n\n\t\t\t Enter 1 to return Main menu or any key to exit";
    char check=getch();
    check=='1'? startMenu(): exit(0);
}

void wordDrill(char dataset[],int limit,int lessonNum,int partNum)
{
    system("color F1");

    cout<<"\n\n\n\n\t\t\t Objective: Practice to develop smooth and accurate keystrokes and even rhythm.";
    cout<<"\n\n\t\t\t Accuracy goal: 94%";
    cout<<"\n\n\n\t\t\t Enter any key to start"<<endl;
    getch();
    system("cls");

    srand(time(NULL));
    int wrongPressCount[limit]= {0};
    int score=0,total=20,wrong=0,gross=0,totalKey=0;
    drawBorder(40,65,3,7,"-","|");
    drawKeyboard();

    auto startTime=chrono::high_resolution_clock::now();
    for(int i=0; i<total; i++)
    {
        string out=RandomWordGen(dataset,limit);
        totalKey+=out.length();
        moveCursor(53,5);
        cout<<out<<endl;
        moveCursor(53,8);
        int index=0;
        while(index<out.length())
        {
            char ch=_getch();
            gross++;
            int target=0;
            for(int j=0; j<limit; j++)
            {
                if(dataset[j]==out[index])
                    target=j;
            }
            if(ch==out[index])
            {
                cout<<ch;
                index++;
            }
            else
            {
                wrong++;
                wrongPressCount[target]++;
            }
        }
        moveCursor(53,5);
        cout<<"          "<<endl;
        moveCursor(53,8);
        cout<<"          "<<endl;
    }
    auto endTime=chrono::high_resolution_clock::now();
    chrono::duration<double> duration=endTime-startTime;

    score=gross-wrong;
    int GrossSpeed=(gross/5)/(duration.count()/60);
    int NetSpeed=(totalKey/5)/(duration.count()/60);
    int accuracy=(score*100)/gross;

    system("cls");
//   cout<<duration.count()/60;
    cout<<"\n\n\n\t\t\t\t\t Gross Speed: "<<GrossSpeed<<" WPM";
    cout<<"\n\n\t\t\t\t\t Net Speed: "<<NetSpeed<<" WPM";
    cout<<"\n\n\t\t\t\t\t Total Key Press: "<<gross;
    cout<<"\n\n\t\t\t\t\t Wrong Key Press: "<<wrong;
    cout<<"\n\n\t\t\t\t\t Accuracy: "<<accuracy<<"%";
    cout<<"\n\n\t\t\t\t\t";
    accuracy>93? cout<<" Very Good\n": cout<<" Try to improve\n";
    cout<<endl;

    drawHistogram(dataset, limit,wrongPressCount);

    ofstream performance("PerformanceHistory.txt",ios::app);
    string write=to_string(lessonNum)+"."+to_string(partNum)+",,"+DateFind()+","
                 +to_string(totalKey)+","+to_string(wrong)+","+to_string(accuracy)+","+to_string(score)+"\n";

    performance<<write;
    performance.close();

    cout<<"\n\n\t\t\t Enter 1 to return Main menu or any key to exit";
    char check=getch();
    check=='1'? startMenu(): exit(0);
}

string RandomWordGen(char dataset[],int limit)
{
    srand(time(NULL));
    int size=3+rand()%5;
    string out="";

    for(int j=0; j<size; j++)
    {
        int index=rand()%limit;
        out+=dataset[index];
    }
    return out;
}
int edit_distance(string a,string b)
{
    int n = a.size(), m = b.size();
    int dp[n + 1][m + 1];
    int i,j;
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else if (a[i - 1] != b[j - 1])
            {
                int mn = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                dp[i][j] = mn;
            }
        }
    }
    return dp[n][m];
}



