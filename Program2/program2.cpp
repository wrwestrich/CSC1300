/*
    Title:   program2.cpp
    Author:  Will Westrich
    Date:    October 12, 2017
    Purpose: Let user play though a board-game-esque game
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <limits>
using namespace std;

static const short NUM_SPACES = 25;
static const short MAX_PLAYERS = 20;

void RollDie(int dieRoll)
{ // Function used to print die art
  switch (dieRoll)
  {
  case 1:
    cout << " _________\n";
    cout << "|         |\n";
    cout << "|    o    |\n";
    cout << "|         |\n";
    cout << "|_________|\n\n";
    break;
  case 2:
    cout << " _________\n";
    cout << "|         |\n";
    cout << "|  o      |\n";
    cout << "|      o  |\n";
    cout << "|_________|\n\n";
    break;
  case 3:
    cout << " _________\n";
    cout << "| o       |\n";
    cout << "|    o    |\n";
    cout << "|       o |\n";
    cout << "|_________|\n\n";
    break;
  case 4:
    cout << " _________\n";
    cout << "| o     o |\n";
    cout << "|         |\n";
    cout << "| o     o |\n";
    cout << "|_________|\n\n";
    break;
  case 5:
    cout << " _________\n";
    cout << "| o     o |\n";
    cout << "|    o    |\n";
    cout << "| o     o |\n";
    cout << "|_________|\n\n";
    break;
  case 6:
    cout << " _________\n";
    cout << "| o     o |\n";
    cout << "| o     o |\n";
    cout << "| o     o |\n";
    cout << "|_________|\n\n";
    break;
  }
  return;
}

void GoodFace()
{ // Function used to print happy face art

  cout << "    _____" << endl;
  cout << "  .'     '." << endl;
  cout << " /  o   o  \\" << endl;
  cout << "|           |" << endl;
  cout << "|  \\     /  |" << endl;
  cout << " \\  '___'  /" << endl;
  cout << "  '._____.'" << endl;
  cout << endl;

  return;
}

void BadFace()
{ // Function used to print sad face art

  cout << "    _____" << endl;
  cout << "  .'     '." << endl;
  cout << " /  o   o  \\" << endl;
  cout << "|           |" << endl;
  cout << "|   .___.   |" << endl;
  cout << " \\ /     \\ /" << endl;
  cout << "  '._____.'" << endl;
  cout << endl;

  return;
}

int main()
{
  char input;
  int numPlayers, i, j, dieRoll, goodOrBad, lineNum, richestNum;
  bool playGame = false, invalidInput = false;
  string names[MAX_PLAYERS], fileLine;
  int boardSpace[MAX_PLAYERS];
  double money[MAX_PLAYERS], moneyCounter, richestPlayer;
  ifstream inFS;

  cout << "\n\nYou are playing LandLand!" << endl;

  do
  { // Main game loop. Only loops if user chooses to play again

    cout << endl
         << "How many players? (1-" << MAX_PLAYERS << "):" << endl;

    do
    {
      while (!(cin >> numPlayers))
      { // This while loop doesn't allow characters to be entered, thus preventing an infinite loop
        cout << endl
             << "Invalid input. Please enter a number (1-" << MAX_PLAYERS << "):" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      if (numPlayers < 1 || numPlayers > MAX_PLAYERS)
      {
        cout << endl
             << "Invalid number of players. Please enter (1-" << MAX_PLAYERS << "):" << endl;
        cin.clear();
        cin >> numPlayers;
        cin.ignore();
      }
    } while (numPlayers < 1 || numPlayers > MAX_PLAYERS);
    cin.ignore();

    // Loop gets player names and assigns it to names[], also clears all used money[] and boardspace[] indices
    for (i = 0; i < numPlayers; ++i)
    {
      cout << "\nPlayer " << i + 1 << ", What is your name?" << endl
           << "Name: ";
      getline(cin, names[i]);

      money[i] = 0.0;
      boardSpace[i] = 0;
    }

    // Main loop that runs the game
    for (i = 0; boardSpace[i] < NUM_SPACES; ++i)
    {
      cout << "\n----------\n"
           << names[i] << ", Press Enter to roll the die." << flush;
      cin.ignore();

      // These lines seed and generate all random numbers needed for each player's turn
      srand(time(0));
      dieRoll = (rand() % 6) + 1;
      goodOrBad = (rand() % 2) + 1;
      lineNum = (rand() % 20) + 1;
      moneyCounter = ((rand() % 10000000) + 1) / 100.0;

      boardSpace[i] += dieRoll;

      cout << "You rolled a " << dieRoll << "." << endl;
      RollDie(dieRoll);

      if (boardSpace[i] >= NUM_SPACES)
      {
        cout << "You finished the LandLand board!" << endl;
        cout << "----------\n"
             << endl;
        break; // Breaks out of main loop if a player reaches the end of the board
      }
      else
        cout << names[i] << " is now on space " << boardSpace[i] << endl;

      if (goodOrBad == 1)
      {
        inFS.open("good.txt");
        if (!inFS.is_open())
        {
          cout << "Could not open good.txt." << endl;
          return 1;
        }
        else
        {
          money[i] += moneyCounter;
          GoodFace();
          for (j = 1; getline(inFS, fileLine); ++j)
            if (j == lineNum)
              break;

          cout << "You're fortunate! " << fileLine << endl;
          cout << "You have gained $" << fixed << setprecision(2) << moneyCounter << "." << endl;

          inFS.close();
        }
      }
      else
      { // No need to check if goodOrBad == 2 since there are only 2 possible outcomes: 1 or 2
        inFS.open("bad.txt");
        if (!inFS.is_open())
        {
          cout << "Could not open bad.txt" << endl;
          return 1;
        }
        else
        {
          money[i] -= moneyCounter;
          BadFace();
          for (j = 1; getline(inFS, fileLine); ++j)
            if (j == lineNum)
              break;

          cout << "Bad Luck! " << fileLine << endl;
          cout << "You have lost $" << fixed << setprecision(2) << moneyCounter << "." << endl;

          inFS.close();
        }
      }
      cout << "You now have $" << fixed << setprecision(2) << money[i] << " in your account." << endl;
      cout << "----------" << endl;

      if (i == (numPlayers - 1)) // Resets index counter to 0 at begining of next loop if loop reaches last used player
        i = -1;
    }
    richestPlayer = money[0];
    for (i = 0; i < numPlayers; ++i)
    {
      if (boardSpace[i] >= NUM_SPACES)
        cout << "Player who survived the LandLand board: " << names[i] << "." << endl;

      if (money[i] > richestPlayer)
      {
        richestPlayer = money[i];
        richestNum = i;
      }
    }
    cout << "Player with the most money: " << names[richestNum] << ", with $" << fixed << setprecision(2) << richestPlayer << "." << endl;

    do
    {
      cout << "\n\nWould you like to play again? (Y or N)" << endl;
      cin >> input;

      if (input == 'n' || input == 'N')
      {
        playGame = false;
        invalidInput = false;
      }
      else if (input == 'y' || input == 'Y')
      {
        playGame = true;
        invalidInput = false;
      }
      else
      {
        cout << "\nInvalid input.";
        invalidInput = true;
      }
    } while (invalidInput); // Keeps user from inputting invalid character

  } while (playGame); // While conditon for main do-while loop

  return 0;
}
