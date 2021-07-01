/************************************************************
 *
 *	Title:   netflix.h
 *	Author:  Will Westrich
 *	Date:    November 30, 2017
 *	Purpose: Header file for netflix.cpp
 *
 ************************************************************/
#ifndef _NETFLIX_H
#define _NETFLIX_H

#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Function prototypes
void selectionSort(int *, int);
double getMedian(int *, int);
double getAverage(int *, int);
int *MakeArray(int);
void GetStudentData(int *, int);
void PrintArray(int *, int);

#endif
