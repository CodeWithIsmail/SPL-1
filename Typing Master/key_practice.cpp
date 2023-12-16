#include"AllHeaderFile.h"

void time_prac_word(int sec)
{
    system("cls");
    system("color F1");

    cout<<"\n\n\n\n\t\t\t Objective: Practice to develop smooth and accurate keystrokes and even rhythm.";
    cout<<"\n\n\t\t\t Accuracy goal: 94%";
    cout<<"\n\n\n\t\t\t Enter any key to start"<<endl;
    getch();

    system("cls");
    srand(time(NULL));
    int elapsed_time=0;
    int score=0,wrong=0,total=0,correct=0;

    drawKeyboard();
    drawBorder(40,55,2,11,"*","*");
    ifstream file("randomword.txt");

    auto startTime = chrono::high_resolution_clock::now();
    while (elapsed_time<sec)
    {
        string word;
        getline(file,word);
        if(word=="") word=RandomWord();
        moveCursor(45,5);
        cout<<word<<endl;

        string input;
        moveCursor(45,8);
        cin>>input;

        auto endTime = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = endTime - startTime;
        elapsed_time=duration.count();

        if(elapsed_time>=sec)
            break;

        total++;
        if(input==word)
        {
            correct++;
        }
        else
        {
            wrong++;
        }

        moveCursor(45,5);
        cout<<"                "<<endl;
        moveCursor(45,8);
        cout<<"                "<<endl;

    }
    file.close();

    system("cls");
    cout<<"\n\n\t\t\t\t\t Times up!!!";
    cout<<"\n\n\t\t\t\t\t Press any key to see result";
    getch();
    system("cls");

    double GrossSpeed = (total  * 60 )/ sec; // speed in WPM
    double NetSpeed = (correct *60) / sec ;
    int accuracy = (correct * 100) / total;

    cout << "\n\n\n\t\t\t\t\t Gross Speed: " << GrossSpeed << " WPM";
    cout << "\n\n\t\t\t\t\t Net Speed: " << NetSpeed << " WPM";
    cout << "\n\n\t\t\t\t\t Total word type: " << total;
    cout << "\n\n\t\t\t\t\t Wrong word type: " << wrong;
    cout << "\n\n\t\t\t\t\t Accuracy: " << accuracy << "%";
    cout << "\n\n\t\t\t\t\t";
    accuracy > 93 ? cout << " Very Good\n" : cout << " Try to improve\n";
    cout << endl;

    cout<<"\n\n\n\n\t\t\t\t Press any key to go back to Menu";
    getch();
    system("cls");
    english_homepage();
}

void time_prac_key(int sec)
{
    system("cls");
    system("color F1");

    cout<<"\n\n\n\n\t\t\t Objective: Practice to develop smooth and accurate keystrokes and even rhythm.";
    cout<<"\n\n\t\t\t Accuracy goal: 94%";
    cout<<"\n\n\n\t\t\t Enter any key to start"<<endl;
    getch();

    system("cls");

    srand(time(NULL));
    int elapsed_time=0;
    int score=0,wrong=0,total=0;

    drawKeyboard();
    drawBorder(40,50,2,8,"*","*");
    auto startTime = chrono::high_resolution_clock::now();
    while (elapsed_time<sec)
    {
        int random_index=rand()%26;
        char key='a'+random_index;
        moveCursor(45,5);
        cout<<key<<endl;
        char ch=getche();

        auto endTime = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = endTime - startTime;
        elapsed_time=duration.count();

        if(elapsed_time>=sec)
            break;
        total++;
        if(ch==key)
        {
            score++;
        }
        else
        {
            wrong++;

        }
        moveCursor(45,5);
        cout<<"     "<<endl;
    }
    system("cls");
    cout<<"\n\n\t\t\t\t\t Times up!!!";
    cout<<"\n\n\t\t\t\t\t Press any key to see result";
    getch();
    system("cls");

    double GrossSpeed = ((total / 5) * 60 )/ sec; // speed in WPM
    double NetSpeed = ((score / 5)*60) / sec ;
    int accuracy = (score * 100) / total;

    cout << "\n\n\n\t\t\t\t\t Gross Speed: " << GrossSpeed << " WPM";
    cout << "\n\n\t\t\t\t\t Net Speed: " << NetSpeed << " WPM";
    cout << "\n\n\t\t\t\t\t Total Key Press: " << total;
    cout << "\n\n\t\t\t\t\t Wrong Key Press: " << wrong;
    cout << "\n\n\t\t\t\t\t Accuracy: " << accuracy << "%";
    cout << "\n\n\t\t\t\t\t";
    accuracy > 93 ? cout << " Very Good\n" : cout << " Try to improve\n";
    cout << endl;

    cout<<"\n\n\n\n\t\t\t\t Press any key to go back to Menu";
    getch();
    system("cls");
    english_homepage();
}



