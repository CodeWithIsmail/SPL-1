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
#include<io.h>
#include<fcntl.h>
#include <codecvt>
#include<cstdlib>
#include<bits/stdc++.h>

using namespace std;

void bangla_homepage();
void english_homepage();
string keyMapping(char input);
void lesson(char input);
void keyDrill(char dataset[],int limit,int lessonNum,int partNum);
void wordDrill(char dataset[],int limit,int lessonNum,int partNum);
string RandomWordGen(char dataset[],int limit );

void drawKeyboard();
void drawHistogram(char dataset[],int size,int frequency[]);
void drawBorder(int x1,int x2,int y1,int y2,string ch1,string ch2);
int main();

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
int edit_distance(string a,string b);
void history();
void statistics();
void performanceAnalysis();
void bangla_game();

void moveCursor(int x,int y);

void startMenu();

void TypingTutorial();
void UserManual();
void time_prac_key(int sec);
void time_prac_word(int sec);

void bangla_tutorial();
void bangla_typing();
string RandomWord();
void loginsystem();

string bangla_tounicode(wstring key);



//#endif // ALLHEADERFILE_H_INCLUDED
