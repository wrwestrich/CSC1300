/*
	Title: program1.cpp
	Author: Will Westrich
	Date: September 27, 2017
	Purpose: Calculate basic conversions for cooking measurements.
*/

#include <iostream>
using namespace std;

int main()
{
  int menu, conversionCount = 0;
  double celsius, fahrenheit, gallons, quarts, pints, cups, teaspoons, tablespoons;
  bool menu1 = true, menu2 = true, menu3 = true, mainMenu = true;

  while (mainMenu)
  {
    cout << "\n\n--MAIN MENU--\n\nWhat kind of conversion do you need?" << endl;
    cout << "1. Conversions for water, Fahrenheit, & Celsius" << endl;
    cout << "2. Conversions for gallon, quart, pint, & cup" << endl;
    cout << "3. Conversions for teaspoon, tablespoon, & cup" << endl;
    cout << "4. End program" << endl;
    cout << "Choose 1-4:" << endl;
    cin >> menu;
    while (menu < 1 || menu > 4)
    {
      cout << "\nInvaild input. Please enter a number 1-4." << endl;
      cin >> menu;
    }

    switch (menu)
    {
      case 1: //Main menu
        while (menu1)
        {
          cout << "\n\n--Water, Fahrenheit, & Celsius--\n\n";
          cout << "Water boils at 100 degrees Celsius and 212 degrees Fahrenheit." << endl;
          cout << "Water freezes at 0 degrees Celsius and 32 degrees Fahrenheit." << endl;
          cout << "\nWhat do you want to do?" << endl;
          cout << "1. Convert a temperature from Celsius to Fahrenheit." << endl;
          cout << "2. Convert a temperature from Fahrenheit to Celsius." << endl;
          cout << "3. Go back to MAIN MENU." << endl;
          cout << "Choose 1-3:" << endl;
          cin >> menu;
          while (menu < 1 || menu > 3)
          {
            cout << "\nInvaild input. Please enter a number 1-3." << endl;
            cin >> menu;
          }

          // Choice 1 subchoices

          switch (menu)
          {
            case 1:
              cout << "\nWhat is the temperature in Celsius?" << endl;
              cin >> celsius;

              fahrenheit = celsius * 1.8 + 32;

              cout << "\nRESULT: " << celsius << " degrees Celsius is " << fahrenheit << " degrees Fahrenheit." << endl;
              ++conversionCount;
              break;

            case 2:
              cout << "\nWhat is the temperature in Fahrenheit?" << endl;
              cin >> fahrenheit;

              celsius = (fahrenheit - 32) / 1.8;

              cout << "\nRESULT: " << fahrenheit << " degrees Fahrenheit is " << celsius << " degrees Celsius." << endl;
              ++conversionCount;
              break;

            case 3:
              menu1 = false;
              break;
          }
        }
        menu1 = true;
        break;

        //End of choice 1 conversions and case 1 of main menu switch

      case 2: //Main menu
        while (menu2)
        {
          cout << "\n\n--GALLON, QUART, PINT, & CUP--\n\n";
          cout << "What measurement do you know?" << endl;
          cout << "1. I know how many gallons I have." << endl;
          cout << "2. I know how many quarts I have." << endl;
          cout << "3. I know how many pints I have." << endl;
          cout << "4. I know how many cups I have." << endl;
          cout << "5. Go back to Main Menu." << endl;
          cout << "Choose 1-5:" << endl;
          cin >> menu;
          while (menu < 1 || menu > 5)
          {
            cout << "\nInvalid input. Please enter a number 1-5." << endl;
            cin >> menu;
          }

          //Choice 2 subchoices

          switch (menu)
          {
            case 1:
              cout << "\nHow many gallons do you have?" << endl;
              cin >> gallons;
              while (gallons < 0)
              {
                cout << "\nCan't have negative gallons. Please enter a positive value." << endl;
                cin >> gallons;
              }

              quarts = gallons * 4.0;
              pints = gallons * 8.0;
              cups = gallons * 16.0;

              cout << "\nRESULT: " << gallons << " gallons is " << quarts << " quarts, " << pints << " pints, or " << cups << " cups." << endl;
              ++conversionCount;
              break;

            case 2:
              cout << "\nHow many quarts do you have?" << endl;
              cin >> quarts;
              while (quarts < 0)
              {
                cout << "\nCan't have negative quarts. Please enter a positive value." << endl;
                cin >> quarts;
              }

              gallons = quarts / 4.0;
              pints = quarts * 2.0;
              cups = quarts * 4.0;

              cout << "\nRESULT: " << quarts << " quarts is " << gallons << " gallons, " << pints << " pints, or " << cups << " cups." << endl;
              ++conversionCount;
              break;

            case 3:
              cout << "\nHow many pints do you have?" << endl;
              cin >> pints;
              while (pints < 0)
              {
                cout << "\nCan't have negative pints. Please enter a positive value." << endl;
                cin >> pints;
              }

              gallons = pints / 8.0;
              quarts = pints / 2.0;
              cups = pints * 2.0;

              cout << "\nRESULT: " << pints << " pints is " << gallons << " gallons, " << quarts << " quarts, or " << cups << " cups." << endl;
              ++conversionCount;
              break;

            case 4:
              cout << "\nHow many cups do you have?" << endl;
              cin >> cups;
              while (cups < 0)
              {
                cout << "\nCan't have negative cups. Please enter a positive value." << endl;
                cin >> cups;
              }

              gallons = cups / 16.0;
              quarts = cups / 4.0;
              pints = cups / 2.0;

              cout << "\nRESULT: " << cups << " cups is " << gallons << " gallons, " << quarts << " quarts, or " << pints << " pints." << endl;
              ++conversionCount;
              break;

            case 5:
              menu2 = false;
              break;
          }
        }
        menu2 = true;
        break;

        //End of choice 2 conversion and case 2 of main menu switch

      case 3: //Main menu
        while (menu3)
        {
          cout << "\n\n--Teaspoon, Tablespoon, & Cups--" << endl;
          cout << "\nWhat measurement do you know?" << endl;
          cout << "1. I know how many teaspoons I have." << endl;
          cout << "2. I know how many tablespoons I have." << endl;
          cout << "3. I know how many cups I have." << endl;
          cout << "4. Go back to Main Menu." << endl;
          cout << "Choose 1-4:" << endl;
          cin >> menu;
          while (menu < 1 || menu > 4)
          {
            cout << "\nInvalid input. Please enter a number 1-4." << endl;
            cin >> menu;
          }

          //Choice 3 subchoices

          switch (menu)
          {
            case 1:
              cout << "\nHow many teaspoons do you have?" << endl;
              cin >> teaspoons;
              while (teaspoons < 0)
              {
                cout << "\nCan't have negative teaspoons. Please enter a positive value." << endl;
                cin >> teaspoons;
              }

              tablespoons = teaspoons / 3.0;
              cups = teaspoons / 48.0;

              cout << "\nRESULT: " << teaspoons << " teaspoons is " << tablespoons << " tablespoons and " << cups << " cups." << endl;
              ++conversionCount;
              break;

            case 2:
              cout << "\nHow many tablespoons do you have?" << endl;
              cin >> tablespoons;
              while (tablespoons < 0)
              {
                cout << "\nCan't have negative tablespoons. Please enter a positive value." << endl;
                cin >> tablespoons;
              }

              teaspoons = tablespoons * 3.0;
              cups = tablespoons / 16.0;

              cout << "\nRESULT: " << tablespoons << " tablespoons is " << teaspoons << " teaspoons and " << cups << " cups." << endl;
              ++conversionCount;
              break;

            case 3:
              cout << "\nHow many cups do you have?" << endl;
              cin >> cups;
              while (cups < 0)
              {
                cout << "\nCan't have negative cups. Please enter positive value." << endl;
                cin >> cups;
              }

              teaspoons = cups * 48.0;
              tablespoons = cups * 16.0;

              cout << "\nRESULT: " << cups << " cups is " << teaspoons << " teaspoons and " << tablespoons << " tablespoons." << endl;
              ++conversionCount;
              break;

            case 4:
              menu3 = false;
              break;
          }
        }
        menu3 = true;
        break;

        //End of choice 3 conversions and case 3 of Main Menu switch

      case 4: //Main menu
        cout << "\nThank you for using the conversion program." << endl;
        cout << "Don't mess up. You made " << conversionCount << " conversions." << endl
            << endl;
        mainMenu = false;
        break;
    }
  }
  return 0;
}
