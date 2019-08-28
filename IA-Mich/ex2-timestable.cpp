#include<iostream>
#include <string>
using namespace std;

int main(){
    int num = 6;
    int counter = 1;
    int prod;

    while (counter < 11){
        prod = num * counter;
        cout << counter << "X" << num << "=" << prod << endl;
        counter++;
    }

    return 0;
}