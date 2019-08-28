#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){
    string str;
    int freq_table[20];
    int temp;

    ifstream fileInput; // a variable of a type that lets you input from files
    fileInput.open("test.txt"); // this tries to open a file called "filename"

    if(not fileInput.good()) { // print an error message
        cout << "Couldn't open the file."  << endl;
        cout << "Does one exist in the same folder as your program?" << endl;
        return 1;
    }

    while(fileInput >> str) {
        freq_table[str.length()]++;
    }

    int counter = 1;

    cout << "Length \t Frequency" << endl;

    while(counter < 11){
        cout << counter << " \t " << freq_table[counter] << endl;
        counter++;
    }
}