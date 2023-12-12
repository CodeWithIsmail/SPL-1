#include <iostream>
#include "Poco/Timer.h"
#include "Poco/Thread.h"

void functionToRunForDuration() {
    int i = 0;
    while (i < 5) {
        std::cout << "Function running..." << std::endl;
        Poco::Thread::sleep(1000); // Simulate some work (1 second sleep)
        i++;
    }
    std::cout << "Function ended!" << std::endl;
    // Add any other termination logic for the function
}

class MyTimerCallback : public Poco::TimerCallback {
public:
    MyTimerCallback() {}

    void run(Poco::Timer& timer) override {
        std::cout << "Time's up! Terminating function." << std::endl;
        // Add any cleanup or termination logic here

        // For example, stopping the function
        // (You might need to implement specific termination logic based on your function's behavior)
        // In this example, we'll assume it's a separate thread running functionToRunForDuration
        // And we'll terminate it abruptly (which is not a good practice)
        // You might want to use flags and graceful termination methods in a real application
        std::terminate(); // This forcibly terminates the program (not recommended in most cases)
    }
};

int main() {
    int timeInSeconds = 10; // Change this to set the duration in seconds

    Poco::Timer timer(timeInSeconds * 1000, 0); // Start once, with the specified duration
    MyTimerCallback callback;
    timer.start(callback);

    // Start the function in a separate thread
    Poco::Thread functionThread;
    functionThread.start(functionToRunForDuration);

    // Let the timer run
    Poco::Thread::sleep(timeInSeconds * 1000 + 1000); // Sleep a bit longer than the timer

    return 0;
}
