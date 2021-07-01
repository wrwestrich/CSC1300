#include "jellybelly.h"
/*
	Function: 	stringToFloat
	Purpose:  	This funciton accepts a string, converts the string to
				a c-string, and then converts the c-string to a float.
				Then, returns this float from the function.
*/
float stringToFloat(string str)
{
  float number;
  char convertStr[1000];
  strcpy(convertStr, str.c_str()); //convert the string to c-string

  number = atof(convertStr);

  return number;
}

int DisplayMenuGetChoice()
{
  int input;

  cout << "\nPlease pick from the following options:" << endl;
  cout << "\t1. Print jellybean inventory" << endl;
  cout << "\t2. Print number of jellybean of a certain color" << endl;
  cout << "\t3. Add to inventory" << endl;
  cout << "\t4. Delete from inventory" << endl;
  cout << "\t5. Save inventory & end program" << endl;
  cout << "Choose 1-5: ";

  do
  {
    while (!(cin >> input))
    {
      cout << "\nInvalid input. Please enter a number 1-5." << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (input < 1 || input > 5)
      cout << "\nInvalid input. Please enter a number 1-5." << endl;
  } while (input < 1 || input > 5);
  cin.ignore();

  return input;
}

void PrintInventory(int numBeans, Jellybean beans[])
{
  for (size_t i = 0; i < numBeans; ++i)
  {
    cout << "\n--------------------" << endl;
    cout << "Flavor:  " << beans[i].flavor << endl;
    cout << "Color:   " << beans[i].color << endl;
    cout << "Rating:  " << beans[i].rating << " stars" << endl;
    cout << "Price:   $" << beans[i].poundPrice << " per pound" << endl;
    cout << "Stock:   " << beans[i].quantity << " pounds" << endl
         << endl;
  }
}

void PrintColor(int numBeans, Jellybean beans[])
{
  string input;
  short numColor = 0;

  cout << "\nWhat color bean would you like to print out?" << endl;
  cout << "Choose from:" << endl;

  cout << "beige     black    brown" << endl;
  cout << "blue      green    mulit-colored" << endl;
  cout << "orange    pink     purple" << endl;
  cout << "red       white    yellow" << endl;

  cout << "\nColor: ";
  getline(cin, input);

  for (size_t i = 0; i < numBeans; ++i)
  {
    if (beans[i].color == input)
    {
      ++numColor;
      cout << "\n--------------------" << endl;
      cout << "Flavor:  " << beans[i].flavor << endl;
      cout << "Color:   " << beans[i].color << endl;
      cout << "Rating:  " << beans[i].rating << " stars" << endl;
      cout << "Price:   $" << beans[i].poundPrice << " per pound" << endl;
      cout << "Stock:   " << beans[i].quantity << " pounds" << endl
           << endl;
    }
  }
  if (numColor == 1)
    cout << "\nThere was " << numColor << " jellybean type of color " << input << "." << endl;
  else if (numColor != 0)
    cout << "\nThere were " << numColor << " jellybean types of color " << input << "." << endl;
  else
    cout << "\nThere are no jellybean types of color " << input << "." << endl;
}

int AddBeans(int numBeans, Jellybean beans[])
{

  cout << "\nFlavor:                    ";
  getline(cin, beans[numBeans].flavor);

  cout << "\n\nbeige     black    brown" << endl;
  cout << "blue      green    mulit-colored" << endl;
  cout << "orange    pink     purple" << endl;
  cout << "red       white    yellow" << endl;

  cout << "\nColor:                     ";
  getline(cin, beans[numBeans].color);

  cout << "\nRating (Number of stars):  ";
  do
  {
    while (!(cin >> beans[numBeans].rating))
    {
      cout << "\nInvalid input." << endl;
      cout << "\nRating (Number of stars):  ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (beans[numBeans].rating < 0 || beans[numBeans].rating > 5)
    {
      cout << "\nInvalid input. Please enter a number 0-5." << endl;
      cout << "\nRating (Number of stars):  ";
    }
  } while (beans[numBeans].rating < 0 || beans[numBeans].rating > 5);

  cout << "\nPrice per pound:           ";
  do
  {
    while (!(cin >> beans[numBeans].poundPrice))
    {
      cout << "\nInvalid input." << endl;
      cout << "\nPrice per pound:           ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (beans[numBeans].poundPrice < 0)
    {
      cout << "\nInvalid input. Please enter a positive number." << endl;
      cout << "\nPrice per pound:           ";
    }
  } while (beans[numBeans].poundPrice < 0);

  cout << "\nQuantity in pounds:        ";
  do
  {
    while (!(cin >> beans[numBeans].quantity))
    {
      cout << "\nInvalid input." << endl;
      cout << "\nQuantity in pounds:        ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if (beans[numBeans].quantity < 0)
    {
      cout << "\nInvalid input. Please enter a positive number." << endl;
      cout << "\nQuantity in pounds:        ";
    }
  } while (beans[numBeans].quantity < 0);
  cin.ignore();
  cout << endl;

  return ++numBeans;
}

/*
	Function:  	deleteBeans
	Purpose:  	This funciton will allow the user to delete or remove a kind
				of jellybean from inventory.  If kind was successfully removed
				then this function subtracts one from the current number of 
				kinds in inventory and returns this integer from the function.
*/
int deleteBeans(Jellybean jellybelly[], int num)
{
  string flavorChoice;
  bool removed = false;

  cout << "\n\nChoose a jellybelly kind to remove from inventory!\n\n";
  for (int x = 0; x < num; x++)
  {
    cout << jellybelly[x].flavor << "\n";
  }
  cout << "\nFLAVOR TO DELETE:  ";
  getline(cin, flavorChoice);
  for (int x = 0; x < num; x++)
  {
    if (flavorChoice == jellybelly[x].flavor)
    {
      removed = true;
      for (int y = x; y < (num - 1); y++)
      {
        jellybelly[y] = jellybelly[y + 1];
      }
    }
  }
  if (removed == true)
  {
    num--;
    cout << flavorChoice << " was removed from the inventory.\n\n";
  }
  else
    cout << flavorChoice << " does not exist in the inventory.\n\n";

  return num;
}
