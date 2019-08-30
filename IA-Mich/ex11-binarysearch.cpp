#include<iostream>
#include<cmath>
#include<cstdlib>
#include <fstream>
using namespace std;


class Entry{
    public:
        string number;
        string name;
};


void bubblesort(Entry directory[], int num_of_entries);
string binarysearch(Entry directory[], string input_num, int dir_len);


int main(){
    string input_line;
    ifstream fileInput; // a variable of a type that lets you input from files
    int firstQuote;
    int lastQuote;
    int firstSpace;
    string number;
    string name;
    int dir_len = 10;
    Entry directory[dir_len];

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

    int sort_num = 1;
    Entry temp;

    bubblesort(directory, dir_len);

    for(int i=0; i<dir_len; i++){
        cout << directory[i].number << " " << directory[i].name << endl;
    }


    cout << "Type a number you're searching for" << endl;

    string input_num;

    cin >> input_num;

    name = binarysearch(directory, input_num, dir_len);

    cout << name << endl;


    return 0;
}


void bubblesort(Entry directory[], int num_of_entries){
    int sort_num = 1;
    Entry temp;

    while(sort_num > 0){
        sort_num = 0;
        for(int i=0; i<9; i++){
            if (directory[i].number > directory[i+1].number){
            temp = directory[i];
            directory[i] = directory[i+1];
            directory[i+1] = temp;
            sort_num++;
            }
        }
    }
}


string binarysearch(Entry directory[], string input_num, int dir_len){
    int low = 0;
    int high = dir_len;
    int check;

    while(true){
        if (directory[0].number == input_num){
            return directory[0].name;
        }

        check = (dir_len + low)/2;
        // cout << low << " " << check << " " << high << endl;

        if (directory[check].number == input_num) {
            return directory[check].name;
        }

        else if (directory[check].number < input_num){
            if (low == check){
                cout << "Number not found" << endl;
                return "";
            }
            low = check;
        }

        else if (directory[check].number > input_num){
            if (high == check){
                cout << "Number not found" << endl;
                return "";
            }
            high = check;
        }
    }

}
