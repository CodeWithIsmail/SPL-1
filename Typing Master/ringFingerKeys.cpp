#include "AllHeaderFile.h"

char dataset4[10]= {'w','x','o','a','s','d','f','j','k','l'};
void reviewRingFingerKeys();
void lessonNew4()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\t\t Lesson 4: Focus on the Ring finger keys";
    cout<<"\n\n\t\t\t\t\t 4.1 -> Review Ring Finger keys";
    cout<<"\n\n\t\t\t\t\t 4.2 -> Key Drill";
    cout<<"\n\n\t\t\t\t\t 4.3 -> Word Drill";
    cout<<"\n\n\n\t\t\t\t\t Select lesson: (1-3) or 0 to return home or any key to exit";

    char lesson=getch();
    system("cls");
    if(lesson=='0')
        startMenu();
    else if(lesson=='1')
        reviewRingFingerKeys();
    else if(lesson=='2')
        keyDrill(dataset4,10,4,2);
    else if(lesson=='3')
        wordDrill(dataset4,10,4,3);
    else
        exit(0);
}

void reviewRingFingerKeys()
{
    cout<<"\n\n\t\t\t In this lesson, you will learn W X O, the Ring finger keys.";
    cout<<"\n\n\t\t\t Press any key to continue.";
    getch();
    system("cls");

    lesson('w');
    lesson('x');
    lesson('o');

    cout<<"\n\n\t\t\t Now you can start the key drill.";
    cout<<"\n\n\t\t\t Press any key to continue.";
    getch();
    system("cls");

    keyDrill(dataset4,10,4,3);
}
