#include "AllHeaderFile.h"

void TypingTutorial()
{
    system("cls");

    cout<<"\n\n\n\t\t\t\t\t\t\t LESSONS:\n\n\n";
    cout<<"\t\t\t\t\t\t 1. Learn the Home Row\n\n";
    cout<<"\t\t\t\t\t\t 2. Learn the Index Finger keys\n\n";
    cout<<"\t\t\t\t\t\t 3. Learn the Middle Finger keys\n\n";
    cout<<"\t\t\t\t\t\t 4. Learn the Ring Finger keys\n\n";
    cout<<"\t\t\t\t\t\t 5. Learn the Little Finger keys\n\n";
    cout<<"\t\t\t\t\t\t 6. Practice Common words\n\n\n";

    cout<<"\t\t\t\t\t\t Select your lesson (1-6) or Enter 0 to return Home or any key to exit:\n\n";

    char ch=getch();
    system("cls");

    if(ch=='0')
        startMenu();
    else if(ch=='1')
        lessonNew1();
    else if(ch=='2')
        lessonNew2();
    else if(ch=='3')
        lessonNew3();
    else if(ch=='4')
        lessonNew4();
    else if(ch=='5')
        lessonNew5();
    else if(ch=='6')
        mostCommonWord();
    else
        exit(0);
}

