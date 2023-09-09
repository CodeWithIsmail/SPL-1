#include "AllHeaderFile.h"

char dataset3[10]= {'e','i','c','a','s','d','f','j','k','l'};
void reviewMiddleFingerKeys();

void lessonNew3()
{
    system("cls");
    cout<<"\n\n\n\t\t\t Lesson 3: Focus on the middle finger keys"<<endl;
    cout<<"\n\n\t\t\t 3.1 -> Review Middle Finger keys: E I C"<<endl;
    cout<<"\n\n\t\t\t 3.2 -> Key Drills"<<endl;
    cout<<"\n\n\t\t\t 3.3 -> Word Drills"<<endl;
    cout<<"\n\n\t\t\t Select lesson: (1-3) or 0 to return home or any key to exit"<<endl;

    char lesson=getch();
    system("cls");

    if(lesson=='0')
        startMenu();
    else if(lesson=='1')
        reviewMiddleFingerKeys();
    else if(lesson=='2')
        keyDrill(dataset3,10,3,2);
    else if(lesson=='3')
        wordDrill(dataset3,10,3,3);
    else
        exit(0);
}

void reviewMiddleFingerKeys()
{
    cout<<"\n\n\t\t\t In this lesson, you will learn E C I, the middle finger keys.";
    cout<<"\n\n\t\t\tPress any key to continue.";
    getch();
    system("cls");

    lesson('e');
    lesson('c');
    lesson('i');

    cout<<"\n\n\t\t\t Now you can start the key drill.";
    cout<<"\n\n\t\t\t Press any key to continue.";
    getch();
    system("cls");

    keyDrill(dataset3,10,3,3);
}
