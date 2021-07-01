/*
	Title:  Movie.h
	Author:  April Crockett, modified by Will Westrich******************************************************
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print & delete a single movie.
*/

#ifndef MOVIE_H
#define MOVIE_H

#include "Text.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <limits>

using namespace std;

struct Movie
{
	Text* movieTitle;  //title of movie
	int movieLength; //length of movie in minutes
	int movieYear; //year released
	Text* movieGenre; //comedy, horror, sci-fi, fantasy, romance, thriller, drama, action, biography
	Text* movieRating; //G, PG, PG-13, R, MA
	int movieOscars; //number of oscars won (not nominations)
	float movieNumStars; //taken from IMDB on 10 star scale
};

/*
	Function name:  createMovie (overloaded function)
	Parameters:  	1) A pointer to a Text variable, containing a c-string and the length of the string.
					2) An integer containing the length of the movie
	Returns: 		A pointer to a new Movie structure
	Purpose:  		This function should be called when only the title of the movie and the length of
					the movie is known and it will create a new movie with this information.
*/
Movie* createMovie(Text*, int); 

/*
	Function name:  createMovie (overloaded function)
	Parameters:  	1) A pointer to a Text variable, containing the title of the movie
					2) An integer containing the length of the movie
					3) An integer containing the year the movie was released
					4) A pointer to a Text variable, containing the genre of the movie
					5) A pointer to a Text variable, containing the rating of the movie
					6) An integer containing the number of oscars the movie won
					7) A float containing the IMDB rating of the movie (out of 10 stars)
	Returns: 		A pointer to a new Movie structure
	Purpose:  		This function should be called when all movie information is known and 
					it will dynamically create a new movie, assign parameter data to the structure,
					and then return the pointer to the newly created Movie
*/
Movie* createMovie(Text*, int, int, Text*, Text*, int, float); 

/*
	Function name:  editMovie 
	Parameters:  	A pointer to a movie structure
	Returns: 		nothing (void)
	Purpose:  		This function should be called when the user wants to edit movie data.  It 
					will show a menu that asks the user which piece of information they wish
					to edit.  Then displays the current value.  Then, allows the user to enter
					in a new value to overwrite the old value.  Then it will show the menu again
					until the user choose #8, which means they are done editing.
*/
void editMovie(Movie* myMovie);

/*
	Function name:  destroyMovie 
	Parameters:  	A pointer to a movie structure
	Returns: 		nothing (void)
	Purpose:  		This function should be called when there is no longer need for the
					movie in the database (like when removing or deleting a movie).
*/
void destroyMovie(Movie*);

/*
	Function name:  printMovieDetails 
	Parameters:  	A pointer to a movie structure
	Returns: 		nothing (void)
	Purpose:  		This function should be called when the user wants to print ALL
					the movie information to the screen.
*/
void printMovieDetails(Movie*);

/*
	Function name:  printMovieDetailsToFile 
	Parameters:  	A pointer to a movie structure, a file stream object (sent by reference)
	Returns: 		nothing (void)
	Purpose:  		This function should be called when the user wants to print ALL
					the movie information to the file.
*/
//FIXME:  add function prototype of printMovieDetailsToFile here!!***********************************************
void printMovieDetailsToFile(Movie*, ofstream&);





//function prototypes to get the information out of the structure variable
Text* getMovieTitle(Movie*);
int getMovieLength(Movie*);
int getMovieYear(Movie*);
Text* getMovieGenre(Movie*);
Text* getMovieRating(Movie*);
int getMovieOscars(Movie*);
float getMovieNumStars(Movie*);

//function prototypes to set or change the information in the structure variable
void setMovieTitle(Movie*, Text*);
void setMovieLength(Movie*, int);
void setMovieYear(Movie*, int);
void setMovieGenre(Movie*, Text*);
void setMovieRating(Movie*, Text*);
void setMovieOscars(Movie*, int);
void setMovieNumStars(Movie*, int);





#endif
