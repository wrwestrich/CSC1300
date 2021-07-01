/*
    Title:   creatures.cpp
    Author:  Will Westrich
    Date:    November 1, 2017
    Purpose: Allow user to store and manipulate
             data about magical creatures.
*/

#include "creatures.h"

int main(){
    bool loopMenu = true;
    Creatures creatures[MAX_CREATURES] = {};
    int input, numCreatures = 0;

    while(loopMenu){
        cout << endl << "What would you like to do?" << endl;
        cout << "\t1. Enter a new creature or load from file." << endl;
        cout << "\t2. Delete a creature." << endl;
        cout << "\t3. Print all creatures." << endl;
        cout << "\t4. Print statistics on creature costs." << endl;
        cout << "\t5. End program" << endl;
        cout << "Please enter a number 1-5: ";
            
        do{ // Checks for proper input
            while(!(cin >> input)){
                cout << "\nInvalid input. Please enter a number 1-5: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            if(input < 1 || input > 5){
                cout << "\nInvalid number. Please enter a number 1-5: ";
            }
        } while(input < 1 || input > 5);
        cin.ignore();

        switch(input){
        
            case 1:
                numCreatures = EnterCreatures(numCreatures, creatures);
                break;

            case 2:
                numCreatures = DeleteCreature(numCreatures, creatures);
                break;

            case 3:
                PrintCreatures(numCreatures, creatures);
                break;

            case 4:
                PrintStatistics(numCreatures, creatures);
                break;

            case 5:
                SaveCreatures(numCreatures, creatures);
                loopMenu = false;
                break;
        }
    }

    return 0;
}
