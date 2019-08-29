#include<iostream>
#include<cmath>
#include<cstdlib>
#include <fstream>
using namespace std;

class Person{
    public:
        string number;
        string name;
};

int main(){
    string input_line;
    ifstream fileInput; // a variable of a type that lets you input from files
    int firstQuote;
    int lastQuote;
    int firstSpace;
    string number;
    string name;
    Person directory[15];

    fileInput.open("directory.txt"); // this tries to open a file called "filename"

    if(not fileInput.good()) { // print an error message
        cout << "Couldn't open the file."  << endl;
        cout << "Does one exist in the same folder as your program?" << endl;
        return 1;
    }

    int counter = 0;
    while (getline(fileInput, input_line)) {
        firstQuote = input_line.find('"');
        lastQuote = input_line.find_last_of('"'); // look for the last w
        firstSpace = input_line.find(' ');

        if (firstQuote==string::npos or lastQuote==string::npos or firstSpace==string::npos) continue;

        else{

            number = input_line.substr(0, firstSpace);
            name = input_line.substr(firstQuote+1, (lastQuote-firstQuote-1));

            directory[counter].number = number;
            directory[counter].name = name;

            counter++;
        }
    }


    for(int i=0; i<15; i++){
        cout << directory[i].number << " " << directory[i].name << endl;
    }

    return 0;
}

