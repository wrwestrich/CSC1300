/*
	Title:  Movies.h
	Author:  April R Crockett, modified by Will Westrich******************************************************
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#ifndef MOVIES_H
#define MOVIES_H

#include "Movie.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Movies
{
	Movie **moviesArray; //an array of pointers - each pointer points to a single Movie
	int maxMovies;			 //maximum number of elements in the array
	int numMovies;			 //current number of movies in the array
};

/*
	Function name:  createMovies 
	Parameters:  	An integer containing the maximum size of the movie library 
	Returns: 		A pointer to a new Movies structure
	Purpose:  		This function should be called when the user needs to create a library
					of movies.  The function will dynamically allocate a movies array based
					on the maximum size and will also set the current number of movies to zero.
*/
Movies *createMovies(int);

/*
	Function name:  addMovieToArray 
	Parameters:  	1) The movies structure (which contains the movie library) 
					2) The single movie that needs to be added to the library
	Returns: 		A boolean indicating if the movie was able to be added or not
	Purpose:  		This function should be called when you need to add a single movie to the
					movie library.
*/
//FIXME:  put the function prototype for addMovieToArray here!!***************************************************
bool addMovieToArray(Movies *, Movie *);

/*
	Function name:  destroyMovies 
	Parameters:  	1) The movies structure (which contains the movie library) 
	Returns: 		nothing (void)
	Purpose:  		This function should be called when you need to remove all the single 
					movies in the movie library as well as the movie library.  This releases
					all the dynamically allocated space in memory.
*/
void destroyMovies(Movies *);

/*
	Function name:  displayMovies 
	Parameters:  	1) The movies structure (which contains the movie library) 
	Returns: 		nothing (void)
	Purpose:  		This function should be called when the user wants to have all the movies
					in the library printed to the screen.
*/
void displayMovies(Movies *);

/*
	Function name:  displayMovieTitles 
	Parameters:  	1) The movies structure (which contains the movie library) 
	Returns: 		nothing (void)
	Purpose:  		This function should be called when you want to print only the movie titles
					out of the movie library
*/
void displayMovieTitles(Movies *);

/*
	Function name:  readMoviesFromFile 
	Parameters:  	1) A pointer to a character (c-string or string literal argument) containing the filename
					2) The movies structure (which contains the movie library) 
	Returns: 		nothing (void)
	Purpose:  		This function should be called when the user wants to read movie data from a file
					and add the movies to the movie library.  The file must have data in the following order:
					title, length, year, genre, rating, num oscars won, star rating
*/
//FIXME:  Put the function prototype of readMoviesFromFile here!**************************************************
void readMoviesFromFile(char *, Movies *);

/*
	Function name:  removeMovieFromArray 
	Parameters:  	1) The movies structure (which contains the movie library) 
					2) The array element of the movie that needs to be removed
	Returns: 		nothing (void)
	Purpose:  		This function should be called when the user wants to remove one single movie
					from the movie library.  The movie to be removed must be identified before
					calling this function because this function eeds the element number (not
					the subscript/index number) of the movie to be removed.
*/
void removeMovieFromArray(Movies *movies, int movieElement);

/*
	Function name:  saveToFile 
	Parameters:  	1) A pointer to a character (c-string or string literal argument) containing the filename
					2) The movies structure (which contains the movie library) 
	Returns: 		nothing (void)
	Purpose:  		This function should be called when the user wants to print all the movie data
					from the movie library to a file.  The data is printed in the following order (one piece
					of data per line):
					title, length, year, genre, rating, num oscars won, star rating
*/
void saveToFile(char *filename, Movies *myMovies);

#endif
