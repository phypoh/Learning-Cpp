#include <iostream>
#include <thread>


class background_task {
    public:
        void operator()() const {
            //while(true){std::cout<<"Executed in the background task\n";}
            std::cout<<"Executed in the background task\n";
        }
};


int main() {
    background_task t;
    std::thread background_thread(t);
    std::cout<<"Executed in main\n";
    background_thread.detach();
    std::cout<<"Executed in main too\n";
}