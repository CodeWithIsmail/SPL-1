//#ifndef ALLHEADERFILE_H_INCLUDED
//#define ALLHEADERFILE_H_INCLUDED
#pragma once

#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<time.h>
#include<chrono>
#include<thread>

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
string DateFind();

void lessonNew1();
void lessonNew2();
void lessonNew3();
void lessonNew4();
void lessonNew5();
void mostCommonWord();

void signIn();

void history();

void gotoxy(int x,int y);

void startMenu();

void TypingTutorial();

//#endif // ALLHEADERFILE_H_INCLUDED
