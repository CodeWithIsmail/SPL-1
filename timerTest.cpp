#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>
#ifdef _WIN32
#include <windows.h> // for Windows
#else
#include <unistd.h> // for Unix/Linux
#endif

using namespace std;

const string filename = "words.txt"; // Change this to the name of your file with words
const int gameDurationSeconds = 60;

void timerThread(bool &gameOver) {
    this_thread::sleep_for(chrono::seconds(gameDurationSeconds));
    gameOver = true;
}

int main() {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return 1;
    }

    string word;
    int score = 0;
    bool gameOver = false;

    // Start the timer thread
    thread timer(timerThread, ref(gameOver));

    // Set terminal to non-blocking input
    #ifdef _WIN32
        DWORD mode;
        HANDLE hstdin = GetStdHandle(STD_INPUT_HANDLE);
        GetConsoleMode(hstdin, &mode);
        SetConsoleMode(hstdin, mode & (~ENABLE_ECHO_INPUT) & (~ENABLE_LINE_INPUT));
    #else
        struct termios t;
        tcgetattr(STDIN_FILENO, &t);
        t.c_lflag &= ~ICANON;
        tcsetattr(STDIN_FILENO, TCSANOW, &t);
    #endif

    while (!gameOver && file >> word) {
        // Display the word to the user
        cout << "Word: " << word << endl;
        string userWord;
        cin >> userWord;

        // Check if the user input matches the word from the file
        if (userWord == word) {
            cout << "Correct! +1 point" << endl;
            score++;
        } else {
            cout << "Incorrect!" << endl;
        }

        // Clear the user's input
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Reset terminal input settings
    #ifdef _WIN32
        SetConsoleMode(hstdin, mode);
    #else
        t.c_lflag |= ICANON;
        tcsetattr(STDIN_FILENO, TCSANOW, &t);
    #endif

    // Join the timer thread if it's still running
    if (timer.joinable()) {
        timer.join();
    }

    // Clear the screen (platform-specific)
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    // Display the final score
    cout << "Game over! Your score: " << score << " points" << endl;

    return 0;
}
