/*
** Simulate the throwing of a six-sided die by returning a
** random number in the range one through six.
*/
#include <stdlib.h>
#include <stdio.h>

/*
**	Compute the largest number returned by the random number
**	generator that will produce a six as the value of the die.
*/
#define	MAX_OK_RAND	\
	    (int)( ( ( (long)RAND_MAX + 1 ) / 6 ) * 6 - 1 )

int
throw_die( void ){
	static	int	is_seeded = 0;
	int	value;

	if( !is_seeded ){
		is_seeded = 1;
		srand( (unsigned int)time( NULL ) );
	}

	do {
		value = rand();
	} while( value > MAX_OK_RAND );

	return value % 6 + 1;
}
