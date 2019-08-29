#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

bool dropthepen();

int main(){
    srandom(time(0));

    bool dropped;
    int numberOfHits = 0;
    int numberOfDrops = 10000;
    double piGuess;

    int counter = 0;

    while (counter < numberOfDrops){
        dropped = dropthepen();
        if (dropped){
            numberOfHits++;
        }
        counter++;
    }

    piGuess = 2.0*numberOfDrops/numberOfHits;

    cout << piGuess << endl;

    return 0;
}


bool dropthepen(){

    float angleindegrees = (90.0*random())/RAND_MAX; // a number between 0 and 90
    float angleinradians = angleindegrees*M_PI/180;  // a number between 0 and pi/2
    float D = (0.5* random())/RAND_MAX;
    float sineangle = sin(angleinradians);

    if (D <= 0.5*sineangle) return true;
    else return false;

}