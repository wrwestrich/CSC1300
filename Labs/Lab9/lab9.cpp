/*
    Title: lab9.cpp
    Author: Will Westrich
    Date: October 27, 2017
    Purpose: Demonstrate a way of protecting private information.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;

static const short NUM_STUDENTS = 10;

struct StudentInfo
{
  string id, name;
  double gpa;
};

int main()
{
  StudentInfo student[NUM_STUDENTS];
  ifstream inFS;
  size_t i;
  int randomNum;
  double noise, tempNum;

  srand(time(0));

  inFS.open("data.txt");
  if (!inFS.is_open())
  {
    cout << "\nFile could not be opened." << endl;
    return 1;
  }

  for (i = 0; i < NUM_STUDENTS; ++i)
  {
    getline(inFS, student[i].id);
    getline(inFS, student[i].name);
    inFS >> student[i].gpa;
    inFS.ignore(numeric_limits<streamsize>::max(), '\n');
  }
  inFS.close();

  cout << "\n\nUnaltered Records:" << endl;
  for (i = 0; i < NUM_STUDENTS; ++i)
  {
    cout << setfill(' ') << setw(15) << left << student[i].id;
    cout << setw(20) << left << student[i].name << student[i].gpa << endl;
  }

  cout << endl
       << "Maintain confidentiality at expense of availability (no GPA):" << endl;
  for (i = 0; i < NUM_STUDENTS; ++i)
    cout << setfill(' ') << setw(15) << left << student[i].id << student[i].name << endl;

  cout << endl
       << "Maintain confidentiality and availability at expense of integrity (noisy GPA):" << endl;
  for (i = 0; i < NUM_STUDENTS; ++i)
  {
    tempNum = student[i].gpa;
    randomNum = rand();
    noise = (randomNum % 100) / 100.0;

    if (randomNum % 2 == 0 && student[i].gpa + noise <= 4.0)
      tempNum += noise;
    else
      tempNum -= noise;

    cout << setfill(' ') << setw(15) << left << student[i].id;
    cout << setw(20) << left << student[i].name << tempNum << endl;
  }
}
