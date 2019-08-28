#include<iostream>
#include <string>
using namespace std;

int main()
{
    int a;
    int b;
    int c;

    cout << "\nType two integers." << endl;
    cin >> a >> b;

    c = a + b;

    cout << "The sum of " << a << " and " << b << " is " << c << endl;
    return 0;
}