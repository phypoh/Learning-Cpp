#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

int RollDie();
int Roll2Die();
int runTheGauntlet();

int main(){
    int frequency[6];
    int runCount = 10000;
    int counter = 0;
    int total = 0;
    float percentage;
    int hotelsVisited;

    srandom(time(0));

    while (counter < runCount){
        hotelsVisited = runTheGauntlet();
        frequency[hotelsVisited]++;
        counter++;
    }

    counter = 0;
    while (counter < 6){
        total += frequency[counter];
        counter++;
    }

    cout << "Hotels Visited \t Frequency \t Percentage" << endl;


    counter = 0;
    while (counter < 6){
    percentage = frequency[counter]*1.0/total;
        cout << counter << "\t\t " << frequency[counter] << "\t\t" << percentage << "%" << endl;
        counter++;
    }

    return 0;
}


int RollDie(){
    int randomNumber, die;

    randomNumber = random();
    die = 1 + (randomNumber % 6);
    return die;
}

int Roll2Die(){
    int die1, die2, diesum;

    die1 = RollDie();
    die2 = RollDie();

    diesum = die1 + die2;

    return diesum;
}

int runTheGauntlet(){
    int hotelsVisited = 0;
    int location = 0;

    while (location <= 9){
        location += Roll2Die();
        if (location == 1 or location == 3 or location == 6 or location == 8 or location == 9){
            hotelsVisited++;
        }
    }

    return hotelsVisited;
}