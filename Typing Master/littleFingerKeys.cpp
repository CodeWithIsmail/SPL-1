#include "AllHeaderFile.h"

char dataset5[10]= {'q','z','p','a','s','d','f','j','k','l'};
void reviewLittleFingerKeys();
void lessonNew5()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\t\t Lesson 5: Focus on the little finger keys";
    cout<<"\n\n\t\t\t\t\t 5.1 -> Review Index Finger keys";
    cout<<"\n\n\t\t\t\t\t 5.2 -> Key Drill";
    cout<<"\n\n\t\t\t\t\t 5.3 -> Word Drill";
    cout<<"\n\n\n\t\t\t\t\t Select lesson: (1-3) or 0 to return home or any key to exit";

    char lesson=getch();
    system("cls");
    if(lesson=='0')
        startMenu();
    else if(lesson=='1')
        reviewLittleFingerKeys();
    else if(lesson=='2')
        keyDrill(dataset5,10,3,2);
    else if(lesson=='3')
        wordDrill(dataset5,10,3,3);
    else
        exit(0);
}

void reviewLittleFingerKeys()
{
    cout<<"\n\n\n\t\t\t In this lesson, you will learn Q P Z, the Little finger keys.";
    cout<<"\n\n\n\t\t\t Press any key to continue.";
    system("cls");

    lesson('q');
    lesson('p');
    lesson('z');

    cout<<"\n\n\n\t\t\t Now you can start the key drill.";
    cout<<"\n\n\n\t\t\t Press any key to continue.";
    getch();
    system("cls");

    keyDrill(dataset5,10,3,2);
}
