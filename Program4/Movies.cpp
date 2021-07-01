/*
	Title:  Movies.cpp
	Author:  April R Crockett, modified by Will Westrich******************************************************
	Date:  11/7/2017
	Purpose:  Be able to create, manage, print, save & delete a movie library
*/
#include "Movies.h"
#include "Movie.h"

//FIXME:  add the removeMovieFromArray function!****************************************************************
void removeMovieFromArray(Movies* movies, int movieElement){
    size_t i;

    --movieElement; // Sets value to corresponding array element
    destroyMovie(movies->moviesArray[movieElement]);
    for(i = movieElement; i < movies->numMovies; ++i)
        movies->moviesArray[i] = movies->moviesArray[i+1];
    
    --(movies->numMovies);

    cout << "\n\nThe movie was successfully removed." << endl << endl;
}
//FIXME:  add the displayMovieTitles function!******************************************************************
void displayMovieTitles(Movies* movies){
    size_t i = 0;

    cout << endl;
    for(; i < movies->numMovies; ++i){
        cout << "Movie " << i+1 << ": ";
        displayText(movies->moviesArray[i]->movieTitle);
        cout << endl;
    }
}

Movies* createMovies(int max)
{
	//dynamically create a new Movies structure
	Movies* myMovies = new Movies;
	myMovies->maxMovies = max;
	myMovies->numMovies = 0;
	
	//dynamically create the array that will hold the movies
	myMovies->moviesArray = new Movie*[max];
	
	return myMovies;
}

void resizeMovieArray(Movies* myMovies)
{
	int max = myMovies->maxMovies * 2; //increase size by 2
	
	//make an array that is twice as big as the one I've currently got
	Movie** newMoviesArray = new Movie*[max];
	for(int x = 0; x < myMovies->numMovies; x++)
	{
		newMoviesArray[x] = myMovies->moviesArray[x];
	}
	
	myMovies->moviesArray = newMoviesArray;
	myMovies->maxMovies = max;
}

bool addMovieToArray(Movies* myMovies, Movie* oneMovie) 
{
	bool wasAbleToAddMovie = false;
	
	if(myMovies->numMovies == myMovies->maxMovies)
		resizeMovieArray(myMovies);	//increase size by 2

	myMovies->moviesArray[myMovies->numMovies] = oneMovie;
	wasAbleToAddMovie = true;
	(myMovies->numMovies)++;
	return wasAbleToAddMovie;
}

void destroyMovies(Movies* myMovies)
{
	//delete each movie
	for(int x=0; x< myMovies->numMovies; x++)
	{
		//delete myMovies->moviesArray[x];
		destroyMovie(myMovies->moviesArray[x]);
	}
	
	//delete movies array
	delete [] myMovies->moviesArray;
	
	//delete myMovies
	delete myMovies;
}

void displayMovies(Movies* myMovies)
{
	for(int x=0; x < (myMovies->numMovies); x++)
	{
		cout << endl << right << setw(50) << "----------MOVIE " << (x+1) << "----------";
		printMovieDetails(myMovies->moviesArray[x]); //function is in Movie.cpp
	}
}

void readMoviesFromFile(char *filename, Movies* myMovies)
{
	int numMoviesReadFromFile = 0;
	ifstream inFile;
	char temp[100];
	Text* title;
	Text* genre;
	Text* rating;
	Movie* oneMovie;
	int movieLength; //length of movie in minutes
	int movieYear; //year released
	int movieOscars; //number of oscars won
	float movieNumStars; //from IMDB out of 10 stars
	
	inFile.open(filename);
	if(inFile.good())
	{
		inFile.getline(temp, 100);
		while(!inFile.eof())
		{	
			title = createText(temp);//create a text for the movie title
			inFile >> movieLength;
			inFile >> movieYear;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
			inFile.getline(temp, 100); //read in genre
			genre = createText(temp); //create a text for genre
			inFile.getline(temp, 100); //read in rating
			rating = createText(temp); //create a text for rating
			inFile >> movieOscars;
			inFile >> movieNumStars;
			inFile.ignore(); //get rid of \n in the inFile buffer
			
			//one movie has been read from the file.  Now create a movie object
			oneMovie = createMovie(title, movieLength, movieYear, genre, rating, movieOscars, movieNumStars);
			
			//now add this movie to the library
			if(addMovieToArray(myMovies, oneMovie))
			{
				cout << endl;
				displayText(title);
				cout << " was added to the movie library!\n";
			}
			else
			{
				cout << endl;
				cout << "I was unable to add ";
				displayText(title);
				cout << " to the movie library.\n";
			}
			
			inFile.getline(temp, 100); //read in the next movie title if there is one
			
			numMoviesReadFromFile++;
		}
		
		cout << "\n\n" << numMoviesReadFromFile << " movies were read from the file and added to your movie library.\n\n";
	}
	else
	{
		cout << "\n\nSorry, I was unable to open the file.\n";
	}
}

void saveToFile(char *filename, Movies* myMovies)
{
	ofstream outFile;
	
	outFile.open(filename);
	
	for(int x=0; x < (myMovies->numMovies); x++)
	{
		printMovieDetailsToFile(myMovies->moviesArray[x], outFile); //function in Movies.cpp
	}
	outFile.close();
	
	cout << "\n\nAll movies in your library have been printed to " << filename << endl;
}




