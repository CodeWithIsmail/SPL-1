#include "AllHeaderFile.h"

char dataset2[10]= {'r','t','y','u','g','h','v','b','n','m'};
void reviewIndexFingerKeys();
void lessonNew2()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\t\t Lesson 2: Focus on the index finger keys";
    cout<<"\n\n\t\t\t\t\t 2.1 -> Review Index Finger keys";
    cout<<"\n\n\t\t\t\t\t 2.2 -> Key Drill";
    cout<<"\n\n\t\t\t\t\t 2.3 -> Word Drill";
    cout<<"\n\n\n\t\t\t\t\t Select lesson: (1-3) or 0 to return home or any key to exit";

    char lesson=getch();
    system("cls");
    if(lesson=='0')
        startMenu();
    else if(lesson=='1')
        reviewIndexFingerKeys();
    else if(lesson=='2')
        keyDrill(dataset2,10,2,2);
    else if(lesson=='3')
        wordDrill(dataset2,10,2,3);
    else
        exit(0);
}

void reviewIndexFingerKeys()
{
    cout<<"\n\n\n\t\t\t In this lesson, you will R T Y U G H V B N M, the index finger keys.";
    cout<<"\n\n\n\t\t\t Press any key to continue.";
    getch();
    system("cls");

    lesson('r');
    lesson('t');
    lesson('y');
    lesson('u');
    lesson('g');
    lesson('h');
    lesson('v');
    lesson('b');
    lesson('n');
    lesson('m');

    cout<<"\n\n\n\t\t\t Now you can start the key drill.";
    cout<<"\n\n\n\t\t\t Press any key to continue.";
    getch();
    system("cls");

    keyDrill(dataset2,10,2,3);
}
