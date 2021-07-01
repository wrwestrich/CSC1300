/*
    Title:   functions.cpp
    Author:  Will Westrich
    Date:    November 1, 2017
    Purpose: Store functions used in creatures.cpp
*/

#include "creatures.h"

#ifdef _WIN32 // Defines function to get console window size if using Windows
int ConsoleSizeWindows(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int consoleSize;
    
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    consoleSize = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    return consoleSize;
}
#else // Assumes Unix if not Windows and defines the proper function
int ConsoleSizeUnix(){
    int consoleSize;
    struct winsize w;

    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    consoleSize = w.ws_col;

    return consoleSize;
}
#endif

string WordWrap(const char* text, int consoleSize){ // Function using console window size to wrap text
    istringstream words(text);
    ostringstream wrappedText;
    string indvWord;
    size_t spaceLeft;

    if(words >> indvWord){
        wrappedText << "     " << indvWord;
        spaceLeft = consoleSize - indvWord.length() - 5;
        while(words >> indvWord){
            if(spaceLeft < indvWord.length() + 1){
                wrappedText << "\n     " << indvWord;
                spaceLeft = consoleSize - indvWord.length() - 5;
            }
            else{
                wrappedText << ' ' << indvWord;
                spaceLeft -= indvWord.length() + 1;
            }
        }
    }

    return wrappedText.str();
}

float ConvertToFloat(string s){
    istringstream inputString(s);
    float conFloat;

    if(!(inputString >> conFloat))
        conFloat = 0;

    return conFloat;
}

void ValidNum(float& input){ // Checks for a valid input when adding a creature
    do{
        while(!(cin >> input)){
            cout << "\nInvalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(input < 0)
            cout << "\nPlease enter a positive value." << endl;
    } while(input < 0);
    cin.ignore();
}

int EnterCreatures(int numCreatures, Creatures creatures[]){
    bool fileOpened = true, invalidInput, exists = false, maxReached = false, skipped = false;
    ifstream inFile;
    short input, creaturesAdded = 0;
    size_t i = 0, j = 0, k = 0;
    string fileName, dangerous, tempString;

    if(numCreatures == MAX_CREATURES){
        cout << "\nZoo is at max capacity. Please remove a creature before adding one to the zoo." << endl;
        return numCreatures;
    }
    else
        maxReached = false;

    cout << "\nWhat would you like to do?" << endl;
    cout << "\t1. Load creatures from a file." << endl;
    cout << "\t2. Manually enter a creature." << endl;
    cout << "\t3. Return to main menu." << endl;
    cout << "Please enter a number 1-3:" << endl;
    
    do{
        while(!(cin >> input)){
            cout << "\nInvalid input. Please enter a number 1-3:" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if(input < 1 || input > 3){
            cout << "\nInvalid number. Please enter a number 1-3:" << endl;
        }
    } while(input < 1 || input > 3);
    cin.ignore();
            
    switch(input){
        
        case 1:
            cout << "\nWhat is the name of the file containing your creature information?\n(ex: filename.txt)" << endl;

            getline(cin, fileName);

            inFile.open(fileName);
            if(!inFile.is_open()){
                cout << endl << fileName << " could not be opened." << endl << endl;
                return numCreatures;
            }

            while(69){ // Loop relies on a break at the end of the file to terminate
                if(creatures[i].name != ""){
                    ++i;
                    continue;
                }
                getline(inFile, tempString, '#');
                if(inFile.eof())
                    break;
                
                j = 0;
                k = 0;
                while(j < numCreatures){ // Loop skips any "deleted" creature by passing by a blank name
                    if(creatures[k].name == ""){
                        ++k;
                        continue;
                    }
                    if(creatures[k].name == tempString){ // Checks if creature already exists
                        exists = true;
                        break;
                    }
                    ++j;
                    ++k;
                }
                    
                if(exists){ // Skips an already existing creature by reading in all corresponding data to junk variable
                    exists = false;
                    skipped = true;
                    for(j = 0; j < 9; ++j)
                        getline(inFile, tempString, '#');
                    continue;
                }
                creatures[i].name = tempString;
                
                getline(inFile, creatures[i].description, '#');
                getline(inFile, tempString, '#');
                creatures[i].avgLength = ConvertToFloat(tempString);

                getline(inFile, tempString, '#');
                creatures[i].avgHeight = ConvertToFloat(tempString);

                getline(inFile, creatures[i].location, '#');

                getline(inFile, tempString, '#');
                creatures[i].dangerous = ConvertToFloat(tempString);

                getline(inFile, tempString, '#');
                creatures[i].costData.hours = ConvertToFloat(tempString);

                getline(inFile, tempString, '#');
                creatures[i].costData.costPerHour = ConvertToFloat(tempString);

                getline(inFile, tempString, '#');
                creatures[i].costData.costFood = ConvertToFloat(tempString);

                getline(inFile, tempString, '#');
                creatures[i].costData.costMat = ConvertToFloat(tempString);
            
                ++numCreatures;
                ++creaturesAdded;
                if(i == MAX_CREATURES){
                    maxReached = true;
                    break;
                }
                ++i;
            }
            inFile.close();

            if(maxReached || skipped)
                cout << endl << "Not all creatures in file were read because the max number\nof creatures was reached or a creature already existed." << endl;
            
            cout << endl << creaturesAdded <<  " creatures successfully loaded from " << fileName << endl << endl;
            break;

        case 2:
            for(i = 0; i < MAX_CREATURES; ++i) // Finds first blank space in array
                if(creatures[i].name == "")
                    break;

            cout << "\nName: ";
            getline(cin, tempString);
            for(j = 0; j < numCreatures; ++j)
                if(tempString == creatures[j].name){
                    cout << endl << tempString << " already exists." << endl;
                    return numCreatures;
                }
            creatures[i].name = tempString;
            
            cout << endl << "\nDescription: ";
            getline(cin, creatures[i].description);

            cout << endl << "\nAverage length (in feet): ";
            ValidNum(creatures[i].avgLength);

            cout << endl << "\nAverage height (in feet): ";
            ValidNum(creatures[i].avgHeight);

            cout << endl << "\nLocation: ";
            getline(cin, creatures[i].location);

            do{
                cout << endl << "\nIs it dangerous? (y or n): ";
                getline(cin, dangerous);

                if(dangerous == "n" || dangerous == "N")
                    invalidInput = false;
                else if(dangerous == "y" || dangerous == "Y")
                    invalidInput = false;
                else{
                    cout << "\nInvalid input. Please enter y or n." << endl;
                    invalidInput = true;
                }
            } while(invalidInput);

            cout << endl << "\nHow many hours do you spend caring for the " << creatures[i].name << "? ";
            ValidNum(creatures[i].costData.hours);

            cout << endl << "\nWhat is the cost per hour of caring for the " << creatures[i].name << "? ";
            ValidNum(creatures[i].costData.costPerHour);

            cout << endl << "\nHow much do you spend on food for the " << creatures[i].name << "? ";
            ValidNum(creatures[i].costData.costFood);

            cout << endl << "\nHow much do you spend on grooming and medical supplies for the " << creatures[i].name << "? ";
            ValidNum(creatures[i].costData.costMat);

            ++numCreatures;
            cout << endl << "\nThe " << creatures[i].name << " has been added." << endl << endl;
            break;

        case 3:
            break; // Quits to menu
    }
    return numCreatures;
}

int DeleteCreature(int numCreatures, Creatures creatures[]){
    bool creatureRemoved = false, fail = false;
    string creatureName;
    size_t i = 0, j = 0;

    if(numCreatures == 0){
        cout << "\nThe zoo is empty." << endl << endl;
        return numCreatures;
    }

    cout << "\nCreatures you care for:" << endl;

    while(i < numCreatures){
        if(creatures[j].name == ""){
            ++j;
            continue;
        }
        cout << creatures[j].name << endl;

        ++i;
        ++j;
    }
    cout << "\nWhat is the name of the creature you would like to remove?\n(Enter q to return to main menu)" << endl;
    getline(cin, creatureName);

    if(creatureName == "q" || creatureName == "Q")
        return numCreatures;

    i = 0;
    j = 0;
    while(i < numCreatures){
        if(creatures[j].name == ""){
            ++j;
            continue;
        }
        if(creatureName == creatures[j].name){
            creatures[j].name = "";
            creatureRemoved = true;
            --numCreatures;
            cout << endl << creatureName << " has been removed." << endl << endl;
        }
        ++i;
        ++j;
    }
    if(!creatureRemoved){ // Displays if a creature was not found
        cout << endl << creatureName << " was not found." << endl << endl;
        creatureRemoved = false;
    }

    return numCreatures;
}

void PrintCreatures(int numCreatures, Creatures creatures[]){
    size_t i = 0, j = 0;
    int consoleSize;
    string dangerous;

    if(numCreatures == 0){
        cout << "\n\nThere are no creatures to print out. Please add creatures to continue." << endl << endl;
        return;
    }
    
    #ifdef _WIN32 // Checks for Windows
    consoleSize = ConsoleSizeWindows();
    #else // Assumes Unix if not Windows
    consoleSize = ConsoleSizeUnix();
    #endif

    while(i < numCreatures){
        if(creatures[j].name == ""){
            ++j;
            continue;
        }
        if(creatures[j].dangerous == true)
            dangerous = "Yes";
        else
            dangerous = "No";

        cout << setfill('-') << setw(consoleSize) << "" << endl;
        cout << "Creature " << i+1 << ":" << endl;
        cout <<  setfill(' ') << setw(20) << left << "Name:" << creatures[j].name << endl;

        cout << "Description:" << endl;
        cout << setw(consoleSize) << left << WordWrap(creatures[j].description.c_str(), consoleSize) << endl << endl;

        if(creatures[j].avgLength == 1)
            cout << setw(20) << left << "Length:" << fixed << setprecision(2) << creatures[j].avgLength << " foot" <<  endl;
        else
            cout << setw(20) << left << "Length:" << fixed << setprecision(2) << creatures[j].avgLength << " feet" <<  endl;

        if(creatures[j].avgHeight == 1)
            cout << setw(20) << left << "Height:" << creatures[j].avgHeight << " foot" << endl;
        else
            cout << setw(20) << left << "Length:" << creatures[j].avgHeight << " feet" <<  endl;

        cout << setw(20) << left << "Location:" << creatures[j].location << endl;

        cout << setw(20) << left << "Dangerous?" << dangerous << endl << endl;
        if(creatures[j].costData.hours == 1)
            cout << setw(50) << left << "Number of hours to care for creature:" << creatures[j].costData.hours << " hour" << endl;
        else
            cout << setw(50) << left << "Number of hours to care for creature:" << creatures[j].costData.hours << " hours" << endl;

        cout << setw(50) << left << "Cost per hour of taking care of the creature:" << "$ " << creatures[j].costData.costPerHour << endl;
        cout << setw(50) << left << "Cost to feed creature:" << "$ " << creatures[j].costData.costFood << endl;
        cout << setw(50) << left << "Grooming and supplies cost:" << "$ " << creatures[j].costData.costMat << endl << endl;

        ++i;
        ++j;
    }

}

void PrintStatistics(int numCreatures, Creatures creatures[]){
    float totalCostEach[MAX_CREATURES], total = 0;
    size_t i = 0, j = 0;

    if(numCreatures == 0){
        cout << endl << "There are no creatures to print out. Please add creatures to continue." << endl << endl;
        return;
    }

    cout << "\nCost of each creature for one week:" << endl << endl;
    cout << setfill(' ') << setw(20) << left << "Creature" << " ";
    cout << setw(15) << right << "Cost" << endl;

    while(i < numCreatures){ // Adds the cost of each creature together and also adds to total cost
        if(creatures[j].name == ""){
            ++j;
            continue;
        }
        totalCostEach[j] = creatures[j].costData.hours * creatures[j].costData.costPerHour
                         + creatures[j].costData.costFood + creatures[j].costData.costMat;
        total += totalCostEach[j];

        cout << setw(20) << left << creatures[j].name << "$";
        cout << setw(15) << right << fixed << setprecision(2) << totalCostEach[j] << endl;

        ++i;
        ++j;
    }
    cout << endl << setw(20) << left << "Total Cost:" << "$";
    cout << setw(15) << right << fixed << setprecision(2) << total << endl << endl;
}

void SaveCreatures(int numCreatures, Creatures creatures[]){
    bool fileOpened, invalidInput;
    char save;
    size_t i = 0, j = 0;
    string fileName;
    ofstream outFile;

    if(numCreatures == 0)
        return; // Quits out instantly if there is nothing to save to a file

    do{
        cout << "\nWould you like to save your creature list to a file? (Y/N)" << endl;
        cin >> save;
        cin.ignore();
        if(save == 'n' || save == 'N')
            return;
        else if(save == 'y' || save == 'Y'){
            invalidInput = false;
            do{
                cout << "\nPlease enter the name of the file (ex: filename.txt):" << endl;
                cout << "Type q to exit without saving: ";

                getline(cin, fileName);
                if(fileName == "q" || fileName == "Q")
                    return;

                outFile.open(fileName);
                if(!(outFile.is_open())){
                    cout << endl << fileName << " could not be opened. Please try again." << endl;
                    fileOpened = false;
                }
                else
                    fileOpened = true;
            } while(!fileOpened);
        }
        else{
            cout << "\nInvalid input. Please enter y or n." << endl;
            invalidInput = true;
        }
    } while(invalidInput);

    while(i < numCreatures){
        if(creatures[j].name == ""){
            ++j;
            continue;
        }
        outFile << creatures[j].name << "#" << creatures[j].description << "#"
                << creatures[j].avgLength << "#" << creatures[j].avgHeight << "#"
                << creatures[j].location << "#" << creatures[j].dangerous << "#"
                << creatures[j].costData.hours << "#" << creatures[j].costData.costPerHour << "#"
                << creatures[j].costData.costFood << "#" << creatures[j].costData.costMat << "#";
        ++i;
        ++j;
    }
    outFile.close();

    cout << "\nYour creatures were successfully saved to " << fileName << "." << endl;
}
