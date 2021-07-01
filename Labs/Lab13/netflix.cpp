/************************************************************
 *
 *	Title:   netflix.cpp
 *	Author:  Will Westrich
 *	Date:    November 30, 2017
 *	Purpose: Gather data of how many hours students watch
 *           Netflix
 ************************************************************/
 
#include "netflix.h"

int main(){
    int numStudents;
    int* students = NULL;
    
    do{
        cout << "\n\nHow many students were surveyed? ";
        while(!(cin >> numStudents)){
            cout << "\n\nInvalid input. Please enter a poitive number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if(numStudents < 1)
            cout << "\n\nInvalid input. Please enter a number > 0." << endl;
    } while(numStudents < 1);

    students = MakeArray(numStudents);

    GetStudentData(students, numStudents);

    PrintArray(students, numStudents);

    cout << "\n\n" << setw(40) << setfill('-') << "" << endl;
    cout << setw(40) << "" << endl;
    cout << "\tNetflix Statistics" << endl;
    cout << setw(40) << "" << endl << endl;
    cout << "\t" << fixed << setprecision(2) << setw(9) << setfill(' ') << left << "Average:" << getAverage(students, numStudents) << endl;
    cout << "\t" << setw(9) << left << "Median:" << getMedian(students, numStudents) << endl;
    cout << setw(40) << setfill('-') << "" << endl;
    cout << setw(40) << "" << endl << endl;

    delete[] students;

	return 0;
}
