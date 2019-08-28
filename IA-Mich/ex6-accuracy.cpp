#include<iostream>
using namespace std;

int main()
{
    double number = 0.1;
    int counter = 0;

    while (counter < 20){
        number = 11 * number - 1;
        counter++;
        cout << "number is " << number << " after " << counter << " iterations." << endl;
    }
    return 0;
}