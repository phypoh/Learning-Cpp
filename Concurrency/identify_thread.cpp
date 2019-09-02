#include <iostream>
#include <thread>


void thread_init();


int main() {
    std::thread t(thread_init);
    t.join();
    std::cout<<"This statement is executed in the main thread\n";
    std::cout<<std::this_thread::get_id() << std::endl;

}


void thread_init() {
    std::cout<<"This statement is executed in the new thread\n";
    std::cout<<std::this_thread::get_id() << std::endl;
}