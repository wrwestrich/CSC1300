/*
	Title:  Movie.cpp
	Author:  April Crockett, modified by Will Westrich******************************************************
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print & delete a single movie.
*/
#include "Movie.h"
#include "Text.h"

//FIXME:  add the overloaded createMovie function!****************************************************************
Movie *createMovie(Text *title, int length, int year, Text *genre, Text *rating, int oscars, float imdbRating)
{
  Movie *newMovie = new Movie;

  newMovie->movieTitle = title;
  newMovie->movieLength = length;
  newMovie->movieYear = year;
  newMovie->movieGenre = genre;
  newMovie->movieRating = rating;
  newMovie->movieOscars = oscars;
  newMovie->movieNumStars = imdbRating;

  return newMovie;
}

//FIXME:  add the editMovie function!*****************************************************************************
void editMovie(Movie *movie)
{
  int inputS, input;
  float inputF;
  char temp[100];

  while (1)
  {
    cout << "\nWhich detail would you like to edit?" << endl;
    cout << "1. Title" << endl;
    cout << "2. Length" << endl;
    cout << "3. Year" << endl;
    cout << "4. Genre" << endl;
    cout << "5. Rating" << endl;
    cout << "6. Number of Oscars" << endl;
    cout << "7. Number of Stars" << endl;
    cout << "8. Done Editing" << endl;
    cout << "Choose 1-8: ";
    do
    {
      while (!(cin >> inputS))
      {
        cout << "\nInvalid input. Please enter a number 1-8: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      if (inputS < 1 || inputS > 8)
        cout << "\nInvalid input. Please enter a number 1-8: ";
    } while (inputS < 1 || inputS > 8);
    cin.ignore();

    switch (inputS)
    {
    case 1:
      cout << "\n\nCurrent Title: ";
      displayText(movie->movieTitle);
      cout << endl;
      cout << "New Title: ";
      cin.getline(temp, 100);
      movie->movieTitle = createText(temp);
      cout << endl
           << endl;
      break;

    case 2:
      cout << "\n\nCurrent Length: " << movie->movieLength << endl;
      cout << "New Length: ";
      do
      {
        while (!(cin >> input))
        {
          cout << "\nInvalid Input. Please enter a number: ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (input < 1)
          cout << "\nInvalid Input. Please enter a length >1: ";
      } while (input < 1);
      cin.ignore();

      movie->movieLength = input;
      cout << endl
           << endl;
      break;

    case 3:
      cout << "\n\nCurrent Year: " << movie->movieYear << endl;
      cout << "New Year: ";
      do
      {
        while (!(cin >> input))
        {
          cout << "\nInvalid Input. Please enter a number: ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (input < 1888) // 1888 was the year that the first known movie was made
          cout << "\nInvalid Input. Please enter a year after 1887: ";
      } while (input < 1888);
      cin.ignore();

      movie->movieYear = input;
      cout << endl
           << endl;
      break;

    case 4:
      cout << "\n\nCurrent Genre: ";
      displayText(movie->movieGenre);
      cout << endl;
      cout << "New Genre: ";
      cin.getline(temp, 100);
      movie->movieGenre = createText(temp);
      cout << endl
           << endl;
      break;

    case 5:
      cout << "\n\nCurrent Rating: ";
      displayText(movie->movieRating);
      cout << endl;
      cout << "New Rating: ";
      cin.getline(temp, 100);
      movie->movieRating = createText(temp);
      cout << endl
           << endl;
      break;

    case 6:
      cout << "\n\nCurrent Number of Oscars: " << movie->movieOscars << endl;
      cout << "New Number of Oscars: ";
      do
      {
        while (!(cin >> input))
        {
          cout << "\nInvalid Input. Please enter a positive number: ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (input < 0)
          cout << "\nInvalid Input. Please enter a positive number: ";
      } while (input < 0);
      cin.ignore();

      movie->movieOscars = input;
      cout << endl
           << endl;
      break;

    case 7:
      cout << "\n\nCurrent Number of Stars: " << movie->movieNumStars << endl;
      cout << "New Number of Stars: ";
      do
      {
        while (!(cin >> inputF))
        {
          cout << "\nInvalid Input. Please enter a number 0-10: ";
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        if (inputF < 0 || inputF > 10)
          cout << "Invalid Input. Please enter a number 0-10: ";
      } while (inputF < 0 || inputF > 10);
      cin.ignore();

      movie->movieNumStars = inputF;
      cout << endl
           << endl;
      break;

    case 8:
      return; // Gets out of infinite loop
    }
  }
}

Movie *createMovie(Text *title, int length)
{
  //dynamically allocate a new Movie
  Movie *myMovie = new Movie;

  //assign parameter data to structure memebers
  myMovie->movieTitle = title;
  myMovie->movieLength = length;

  return myMovie;
}

void destroyMovie(Movie *myMovie)
{
  destroyText(myMovie->movieTitle);
  destroyText(myMovie->movieGenre);
  destroyText(myMovie->movieRating);
  delete myMovie;
}

void printMovieDetails(Movie *myMovie)
{
  cout << endl;
  cout << right << setw(30) << "Movie Title:  " << left;
  displayText(myMovie->movieTitle);
  cout << endl;
  cout << right << setw(30) << "Length (minutes):  " << left << myMovie->movieLength << endl;
  cout << right << setw(30) << "Year Released:  " << left << myMovie->movieYear << endl;
  cout << right << setw(30) << "Genre:  " << left;
  displayText(myMovie->movieGenre);
  cout << endl;
  cout << right << setw(30) << "Rating:  " << left;
  displayText(myMovie->movieRating);
  cout << endl;
  cout << right << setw(30) << "Number of Nominations:  " << left << myMovie->movieOscars << endl;
  cout << right << setw(30) << "Number of Stars:  " << left << myMovie->movieNumStars << endl
       << endl;
}

void printMovieDetailsToFile(Movie *myMovie, ofstream &outFile)
{
  char temp[1000];
  strncpy(temp, getText(myMovie->movieTitle), 1000);
  outFile << temp << endl;
  outFile << myMovie->movieLength << endl;
  outFile << myMovie->movieYear << endl;
  strncpy(temp, getText(myMovie->movieGenre), 1000);
  outFile << temp << endl;
  strncpy(temp, getText(myMovie->movieRating), 1000);
  outFile << temp << endl;
  outFile << myMovie->movieOscars << endl;
  outFile << myMovie->movieNumStars << endl;
}

Text *getMovieTitle(Movie *myMovie)
{
  return myMovie->movieTitle;
}

int getMovieLength(Movie *myMovie)
{
  return myMovie->movieLength;
}

int getMovieYear(Movie *myMovie)
{
  return myMovie->movieYear;
}

Text *getMovieGenre(Movie *myMovie)
{
  return myMovie->movieGenre;
}

Text *getMovieRating(Movie *myMovie)
{
  return myMovie->movieRating;
}

int getMovieOscars(Movie *myMovie)
{
  return myMovie->movieOscars;
}

float getMovieNumStars(Movie *myMovie)
{
  return myMovie->movieNumStars;
}

void setMovieTitle(Movie *myMovie, Text *title)
{
  myMovie->movieTitle = title;
}

void setMovieLength(Movie *myMovie, int length)
{
  myMovie->movieLength = length;
}

void setMovieYear(Movie *myMovie, int year)
{
  myMovie->movieLength = year;
}

void setMovieGenre(Movie *myMovie, Text *title)
{
  myMovie->movieTitle = title;
}

void setMovieRating(Movie *myMovie, Text *rating)
{
  myMovie->movieRating = rating;
}

void setMovieOscars(Movie *myMovie, int nom)
{
  myMovie->movieOscars = nom;
}

void setMovieNumStars(Movie *myMovie, int stars)
{
  myMovie->movieNumStars = stars;
}
