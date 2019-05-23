/*
	David Brown
	9.6.16
	Timer Generation
*/

#include <ctime>
#include <cmath>
#include <cstdlib>

/*
	Pre: None
	Post: Returns the current system time
*/
time_t getTime();
/*
	Pre: start and end are variables of type time_t containing 2 different system times, start is before end
	Post: Will return the number of seconds separating two times
*/
double totalTime (time_t start, time_t end);
