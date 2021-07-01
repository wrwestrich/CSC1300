/*
	Title: lab5.cpp
	Author: Will Westrich
	Date: September 29, 2017
	Purpose: Generate a random number and have user guess the number.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	char play;
	bool startGame = false, invalidInput = false, correctGuess;
	int randNumber, guess, tryCount = 0;

	do
	{
		cout << "Are you ready to play (y/n)?" << endl;
		cin >> play;
		if (play == 'n' || play == 'N')
		{
			startGame = false;
			invalidInput = false;
		}
		else if (play == 'y' || play == 'Y')
		{
			startGame = true;
			invalidInput = false;
		}
		else
		{
			cout << "\nInvalid input. Please enter y for yes or n for no." << endl;
			invalidInput = true;
		}
	} while (invalidInput);

	while (startGame)
	{
		srand(time(0));
		randNumber = (rand() % 100) + 1;

		do
		{
			cout << "\nEnter your guess (1-100):" << endl;
			cin >> guess;
			while (guess < 1 || guess > 100)
			{
				cout << "\nInvalid input. Please enter a number 1-100." << endl;
				cin >> guess;
			}
			if (guess < randNumber)
			{
				cout << "\nToo low." << endl;
				correctGuess = false;
				++tryCount;
			}
			else if (guess > randNumber)
			{
				cout << "\nToo high." << endl;
				correctGuess = false;
				++tryCount;
			}
			else
			{
				++tryCount;
				cout << "\nCorrect! You guessed the right number in " << tryCount << " tries." << endl;
				tryCount = 0;
				do
				{
					cout << "Are you ready to play again (y/n)?" << endl;
					cin >> play;
					if (play == 'n' || play == 'N')
					{
						startGame = false;
						correctGuess = true;
						invalidInput = false;
					}
					else if (play == 'y' || play == 'Y')
					{
						invalidInput = false;
						correctGuess = true;
					}
					else
					{
						cout << "\nInvalid input. Please enter y for yes or n for no." << endl;
						invalidInput = true;
					}
				} while (invalidInput);
			}
		} while (!(correctGuess));
	}
}
