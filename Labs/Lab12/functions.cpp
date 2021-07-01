#include "functions.h"
#include "Timer.h"

bool IsPrime(int num)
{
  int roundedNum = static_cast<int>(ceil(sqrt(num)));
  bool isPrime = true;

  if (num > 2)
  {
    for (size_t i = 2; i <= roundedNum; ++i)
    {
      if (num % i == 0)
      {
        isPrime = false;
        break;
      }
    }
    return isPrime;
  }
  if (num == 1)
    return isPrime = false;
  if (num == 2)
    return isPrime;
}

int ParallelNumPrimes(int lowBound, int upBound)
{
  int numPrimes = 0;
  bool isPrime;

#pragma omp parallel for reduction(+ \
                                   : counter)
  for (size_t i = lowBound; i <= upBound; ++i)
  {
    isPrime = IsPrime(i);
    if (isPrime)
      ++numPrimes;
  }
  return numPrimes;
}

int SequentialNumPrimes(int lowBound, int upBound)
{
  int numPrimes = 0;
  bool isPrime;

  for (size_t i = lowBound; i <= upBound; ++i)
  {
    isPrime = IsPrime(i);
    if (isPrime)
      ++numPrimes;
  }
  return numPrimes;
}

int DisplayMenuGetChoice()
{
  int input;

  cout << "\nNumber of Primes Program" << endl
       << endl;
  cout << "Choose an option below:" << endl;
  cout << "    1. Number of primes found sequentially." << endl;
  cout << "    2. Number of primes found in parallel." << endl;
  cout << "    3. Quit program." << endl;
  cout << "Please enter 1-3: ";
  do
  {
    while (!(cin >> input))
    {
      cout << "\nInvalid input. Please enter a number 1-3: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (input < 1 || input > 3)
      cout << "\nInvalid input. Please enter a number 1-3: ";
  } while (input < 1 || input > 3);
  return input;
}
