#include "functions.h"
#include "Timer.h"

int main(){
    ifstream inFS;
    int input, lowBound, upBound, numPrimes;
    time_t timeStart, timeEnd;
    double timeTotal;

    inFS.open("range.txt");
    if(!(inFS.is_open())){
        cout << "\nFile could not be found." << endl;
        return 1;
    }
    inFS >> lowBound;
    inFS >> upBound;
    inFS.close();

    while(1){
        input = DisplayMenuGetChoice();

        switch(input){
            case 1:
                cout << "\n\nFinding the number of primes between " << lowBound << " and " << upBound << " inclusive..." << endl;

                timeStart = getTime();
                numPrimes = SequentialNumPrimes(lowBound, upBound);
                timeEnd = getTime();
                timeTotal = totalTime(timeStart, timeEnd);

                cout << "\n\nNumber of primes: " << numPrimes << endl;
                cout << "Total time: " << timeTotal << endl << endl;
                break;

            case 2:
                cout << "\n\nFinding the number of primes between " << lowBound << " and " << upBound << " inclusive..." << endl;

                timeStart = getTime();
                numPrimes = ParallelNumPrimes(lowBound, upBound);
                timeEnd = getTime();
                timeTotal = totalTime(timeStart, timeEnd);

                cout << "\n\nNumber of primes: " << numPrimes << endl;
                cout << "Total time: " << timeTotal << endl << endl;
                break;

            case 3:
                return 0;
        }
    }
}
