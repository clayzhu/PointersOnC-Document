/*
** Compute the square root of a number.
*/

#include <stdio.h>
#include <stdlib.h>

int
main()
{
	float	new_guess;
	float	last_guess;
	float	number;

	/*
	** Prompt for and read the data, then check it.
	*/
	printf( "Enter a number: " );
	scanf( "%f", &number );
	if( number < 0 ){
		printf( "Cannot compute the square root of a "
		    "negative number!\n" );
		return EXIT_FAILURE;
	}

	/*
	** Compute approximations to the square root until they
	** don't change any more.
	*/
	new_guess = 1;
	do {
		last_guess = new_guess;
		new_guess = ( last_guess + number / last_guess ) / 2;
		printf( "%.15e\n", new_guess );
	} while( new_guess != last_guess );

	/*
	** Print results.
	*/
	printf( "Square root of %g is %g\n", number, new_guess );

	return EXIT_SUCCESS;
}
