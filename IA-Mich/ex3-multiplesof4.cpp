#include <iostream>
#include <string>
using namespace std;

bool is_even(int number); // the function prototype

int main() {
    int i=0;
    while(i<11) {
        if (is_even(i)) {  // the function call
            cout << i << " is a multiple of 4" << endl;
        }
        else {
            cout << i << " is not a multiple of 4" << endl;
            }
        i=i+1;
    }
}

// the is_even function's definition
bool is_even(int number) {
    if ( (number % 4) == 0) {
        return true;
    }
    else {
        return false;
    }
}