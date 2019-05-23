/*
    Title:   creatures.h
    Author:  Will Westrich
    Date:    November 1, 2017
    Purpose: Header file for creatures.cpp and functions.cpp.
*/
#ifndef CREATURES_H
#define CREATURES_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <limits>

#ifdef _WIN32 // Checks to see if compiler is running on Windows
#include <windows.h>
int ConsoleSizeWindows();
#else // Assumes Unix if not Windows
#include <sys/ioctl.h>
#include <unistd.h>
int ConsoleSizeUnix();
#endif
using namespace std;


static const short MAX_CREATURES = 100;

struct Cost {
    float hours, costPerHour, costFood, costMat;
};

struct Creatures {
    string name, description, location;
    float avgLength, avgHeight;
    bool dangerous;
    Cost costData;
};

string WordWrap(const char*, int);
int EnterCreatures(int, Creatures []);
int DeleteCreature(int, Creatures []);
void PrintCreatures(int, Creatures []);
void PrintStatistics(int, Creatures []);
void SaveCreatures(int, Creatures []);
#endif
