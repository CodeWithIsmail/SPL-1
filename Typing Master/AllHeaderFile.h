//#ifndef ALLHEADERFILE_H_INCLUDED
//#define ALLHEADERFILE_H_INCLUDED
#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<time.h>
#include<chrono>
#include<iomanip>

using namespace std;

string keyMapping(char input);
void lesson(char input);
void keyDrill(char dataset[],int limit,int lessonNum,int partNum);
void wordDrill(char dataset[],int limit,int lessonNum,int partNum);
string RandomWordGen(char dataset[],int limit );

void drawKeyboard();
void drawHistogram(char dataset[],int size,int frequency[]);
void drawBorder(int x1,int x2,int y1,int y2,string ch1,string ch2);

void game1();
void Border();
void game2();
void clearScreen();
string DateFind();

void lessonNew1();
void lessonNew2();
void lessonNew3();
void lessonNew4();
void lessonNew5();
void mostCommonWord();

void signIn();
void signUp();

void history();
void statistics();
void performanceAnalysis();

void moveCursor(int x,int y);

void startMenu();

void TypingTutorial();
void UserManual();

//#endif // ALLHEADERFILE_H_INCLUDED
