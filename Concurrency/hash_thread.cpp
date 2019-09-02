#include <iostream>
#include <thread>
#include <functional>


void print_thread_id_and_hash(std::string remark);
void thread_init();


int main() {
    std::thread t(thread_init);
    t.join();
    print_thread_id_and_hash("Main thread");
}


void print_thread_id_and_hash(std::string remark) {
    std::thread::id id = std::this_thread::get_id();
    std::cout<<"Thread remark: ";
    std::cout<<remark << ".";
    std::cout<<" thread identifier (std::thread::id): ";
    std::cout<<id << ".";
    std::cout<<" thread hash (std::hash<std::thread::id>): ";
    std::cout<<std::hash<std::thread::id>()(id);
    std::cout<<std::endl;
}


void thread_init() {
    print_thread_id_and_hash("New thread");
}

// g++ hash_thread.cpp -pthread -std=c++11
