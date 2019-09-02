#include <iostream>
#include <thread>
using namespace std;

void thread_init();

int main() {
    thread t(thread_init);
    cout << "This statement is executed in the main thread\n";
    t.join();
}

void thread_init() {
    cout << "This statement is executed in the new thread\n";
}

// g++ simple.cpp -o simple -pthread -std=c++11
