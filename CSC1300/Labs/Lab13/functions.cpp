/************************************************************
 *
 *	Title:   functions.cpp
 *	Author:  Will Westrich
 *	Date:  	 November 30, 2017
 *	Purpose: A C++ program statistical data program
 *
 ************************************************************/
 
#include "netflix.h"


/**************************************************
 * Function selectionSort                         *
 * This function performs the selection sort      *
 * algorithm on array, sorting it into ascending  *
 * order. The parameter size holds the number of  *
 * elements in the array.                         *
 **************************************************/

void selectionSort(int *array, int size)
{
   int startScan, minIndex, minValue;

   for (startScan = 0; startScan < (size - 1); startScan++)
   {
      minIndex = startScan;
      minValue = *(array+startScan);
      for(int index = startScan + 1; index < size; index++)
      {
         if (*(array+index) < minValue)
         {
            minValue = *(array+index);
            minIndex = index;
         }
      }
      *(array+minIndex) = *(array+startScan);
      *(array+startScan) = minValue;
	}
}

/***************************************************
 * Function getMedian                              *
 * This function displays the median of the values *
 * in the array pointed to by the parameter arr.   *
 * The num parameter holds the number of elements  *
 * in the array.                                   *
 ***************************************************/

double getMedian(int *arr, int num)
{
	double med;
   
	selectionSort(arr, num);

	if (num % 2 == 0) // number of elements even?
	{
		int mid1 = num / 2, mid2 = (num / 2) - 1;
        med = ((*(arr + mid1) + *(arr + mid2)) / 2.0);
	}
	else
		med = *(arr + (num / 2));
	
	return med;
}

/****************************************************
 * Function getAverage                              *
 * This function calculates and returns the average *
 * of the values in the array arr. num is the       *
 * number of elements in the array.                 *
 ****************************************************/

double getAverage(int *array, int num)
{
	int total = 0;
	double average;

	for (int count = 0; count < num; count++)
	{
		total += *(array+count);
	}
	average = total / static_cast<double>(num);
	return average;
}

int* MakeArray(int size){
    
    int* array = new int[size];

    return array;
}

void GetStudentData(int* a, int size){
    
    cout << "\nEnter the number of hours each student watched Netflix:" << endl;

    for(size_t i = 0; i < size; ++i){
        cout << "Student " << i + 1 << ": ";

        do{
            while(!(cin >> *(a + i))){
                cout << "\nInvalid input. Please enter a positive number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if(*(a + i) < 0)
                cout << "\nInvalid input. Please enter a positive number." << endl;
        } while(*(a + i) < 0);
    }
}

void PrintArray(int* array, int size){

    selectionSort(array, size);

    cout << "\nNumber of hours each student watched in ascending order:" << endl;

    for(size_t i = 0; i < size; ++i)
        cout << *(array + i) << " ";

    cout << endl;
}
