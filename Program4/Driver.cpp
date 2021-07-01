/*
	Title:  Driver.cpp
	Author:  April Crockett, modified by Will Westrich******************************************************
	Date:  11/7/2017
	Purpose:  To demonstrate the Movies, Movie, and Text structure code working
	by allowing the user to add, save, delete, and edit movies to/from a library.
*/

#include "Movies.h"
#include "Movie.h"
#include "Text.h"
#include <iostream>
using namespace std;

int main()
{
	int menuChoice;
	int movieChoice;
	int maxMovies;
	char filename[25];

	//variables needed for adding a movie
	int length, year, numOscars;
	double numStars;
	char tempString[100];
	Text *title;
	Text *genre;
	Text *rating;
	Movie *oneMovie;

	cout << "\n\nWhat is the maximum number of movies you can have in your library?\n";
	cin >> maxMovies;
	while (maxMovies < 0)
	{
		cout << "\n\nYou have to allow for at least one movie.  Please enter the maximum number of movies you can have in your library.\n";
		cin >> maxMovies;
	}
	Movies *movieLibrary = createMovies(maxMovies);

	do
	{
		cout << "\n\nWhat would you like to do?\n";
		cout << "1.  Read movies from file.\n";
		cout << "2.  Save movies to a file.\n";
		cout << "3.  Add a movie.\n";
		cout << "4.  Delete a movie.\n";
		cout << "5.  Edit a movie.\n";
		cout << "6.  Print all movies.\n";
		cout << "7.  Delete ALL movies and end the program.\n";
		cout << "CHOOSE 1-7:  ";
		cin >> menuChoice;
		while (menuChoice < 1 || menuChoice > 7)
		{
			cout << "That is not a valid choice.\n";
			cout << "CHOOSE 1-7:  ";
			cin >> menuChoice;
		}

		switch (menuChoice)
		{
		case 1:
			cout << "\n\nWhat is the name of the file? (example.txt):  ";
			cin >> filename;
			readMoviesFromFile(filename, movieLibrary); //function is in Movies.cpp
			break;

		case 2:
			cout << "\n\nWhat do you want to name the file? (example.txt):  ";
			cin >> filename;
			saveToFile(filename, movieLibrary); //function is in Movies.cpp

			break;

		case 3:					//add a movie
			cin.ignore(); //remove the \n from the keyboard buffer
			cout << "\n\nMOVIE TITLE: ";
			cin.getline(tempString, 100);
			title = createText(tempString);
			cout << "\nMOVIE LENGTH (in minutes): ";
			cin >> length;
			cout << "\nMOVIE YEAR: ";
			cin >> year;
			cin.ignore();
			cout << "\nMOVIE GENRE: ";
			cin.getline(tempString, 100);
			genre = createText(tempString);
			cout << "\nMOVIE RATING: ";
			cin.getline(tempString, 100);
			rating = createText(tempString);
			cout << "\nNUMBER OF OSCARS WON: ";
			cin >> numOscars;
			cout << "\nSTAR RATING (out of 10): ";
			cin >> numStars;

			//create the movie
			oneMovie = createMovie(title, length, year, genre, rating, numOscars, numStars);

			//add the movie to the library
			addMovieToArray(movieLibrary, oneMovie);
			break;

		case 4: //delete a movie
			cout << "\n\nChoose from the following movies to remove:\n";
			displayMovieTitles(movieLibrary);
			cout << "\nChoose a movie to remove between 1 & " << movieLibrary->numMovies << ":  ";
			cin >> movieChoice;
			while (movieChoice < 1 || movieChoice > movieLibrary->numMovies)
			{
				cout << "\nOops!  You must enter a number between 1 & " << movieLibrary->numMovies << ":  ";
				cin >> movieChoice;
			}
			removeMovieFromArray(movieLibrary, movieChoice);

			break;

		case 5: //edit a movie
			cout << "\n\nChoose from the following movies to edit:\n";
			displayMovieTitles(movieLibrary);
			cout << "\nChoose a movie to remove between 1 & " << movieLibrary->numMovies << ":  ";
			cin >> movieChoice;
			while (movieChoice < 1 || movieChoice > movieLibrary->numMovies)
			{
				cout << "\nOops!  You must enter a number between 1 & " << movieLibrary->numMovies << ":  ";
				cin >> movieChoice;
			}
			oneMovie = movieLibrary->moviesArray[movieChoice - 1];
			editMovie(oneMovie);

			break;

		case 6: //print all movies
			displayMovies(movieLibrary);
			break;

		case 7: //delete all movies
			destroyMovies(movieLibrary);
			break;
		}

	} while (menuChoice != 7);

	cout << "\n\nGOODBYE!\n\n";

	return 0;
}
