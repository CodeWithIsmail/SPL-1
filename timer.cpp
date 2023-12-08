#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <atomic>
#include <conio.h>
#include <windows.h>

using namespace std;

atomic<bool> timeUp(false);

void timer(int sec) {
    this_thread::sleep_for(chrono::seconds(sec));
    timeUp = true;
}

void typing_task_key() {
    while (!timeUp) {
        // Generate a random character
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(97, 122); // ASCII values for 'a' to 'z'
        char key = static_cast<char>(dis(gen));

        cout << key << endl;
        char ch = _getch();

        if (ch == key) {
            cout << "Correct!" << endl;
        } else {
            cout << "Wrong!" << endl;
        }

        system("cls");
    }
}

void time_prac_key(int sec) {
    thread timerThread(timer, sec);
    thread typingThread(typing_task_key);

    timerThread.join();

    if (typingThread.joinable()) {
        typingThread.join();
    }

    // Rest of your result display and menu code
}

int main() {
    time_prac_key(10); // Change the duration as needed

    cout << "Hello, World!" << endl; // Print "Hello, World!" after practice session
    return 0;
}
