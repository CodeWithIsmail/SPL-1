#include "AllHeaderFile.h"

char dataset1[7]= {'a','s','d','f','j','k','l'};
void reviewHomeRow();
void lessonNew1()
{
    system("cls");
    cout<<"\n\n\n\t\t\t\t\t Lesson 1: Focus on the Home row";
    cout<<"\n\n\t\t\t\t\t 1.1 -> Review the Home Row";
    cout<<"\n\n\t\t\t\t\t 1.2 -> Key Drill";
    cout<<"\n\n\t\t\t\t\t 1.3 -> Word Drill";
    cout<<"\n\n\n\t\t\t\t\t Select lesson: (1-3) or 0 to return home or any key to exit";

    char lesson=getch();
    system("cls");
    if(lesson=='0')
        startMenu();
    else if(lesson=='1')
        reviewHomeRow();
    else if(lesson=='2')
        keyDrill(dataset1,7,1,2);
    else if(lesson=='3')
        wordDrill(dataset1,7,1,3);
    else
        exit(0);
}

void reviewHomeRow()
{
    cout<<"\n\n\n\t\t\t In this lesson, you will learn the home row.";
    cout<<"\n\t\t\t A S D F and J K L";
    cout<<"\n\n\n\t\t\t Press any key to continue.";
    getch();
    system("cls");

    cout<<"\n\n\n\t\t\t Starting from the little finger, place your left hand fingers on A, S, D and F.";
    cout<<"\n\n\n\t\t\t Press any key to continue.";
    getch();
    system("cls");

    cout<<"\n\n\n\t\t\t Starting from the index finger, place your right hand fingers on J, K, L";
    cout<<"\n\n\n\t\t\t Press any key to continue.";
    getch();
    system("cls");

    cout<<"\n\n\n\t\t\t Let your thumbs rest on the space bar.";
    cout<<"\n\n\n\t\t\t Press any key to continue.";
    getch();
    system("cls");

    cout<<"\n\n\n\t\t\t Now your hands are in the basic position.";
    cout<<"\n\n\n\t\t\t Press any key to continue.";
    getch();
    system("cls");

    lesson('a');
    lesson('s');
    lesson('d');
    lesson('f');
    lesson('j');
    lesson('k');
    lesson('l');

    cout<<"\n\n\n\t\t\t Now you can start the first drill.";
    cout<<"\n\n\n\t\t\t Press any key to continue.";
    getch();
    system("cls");

    keyDrill(dataset1,7,1,3);
}
