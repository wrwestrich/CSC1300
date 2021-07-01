#ifndef JELLYBELLY_H
#define JELLYBELLY_H

#include <iostream>
#include <fstream>
#include <cstring> //for strcpy function
#include <cstdlib> //for atof function
#include <string>
#include <limits>
using namespace std;

struct Jellybean
{
  float poundPrice, quantity, rating;
  string flavor, color;
};

const int NUM_FLAVORS = 50;

float stringToFloat(string);
int deleteBeans(Jellybean[], int);
void PrintInventory(int, Jellybean[]);
void PrintColor(int, Jellybean[]);
int DisplayMenuGetChoice();
int AddBeans(int, Jellybean[]);

#endif
