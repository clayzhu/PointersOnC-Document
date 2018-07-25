/*
** Find the place in an array where a particular integer value
** is stored, and return a pointer to that location.
*/
#include <stdio.h>

int *
find_int( int key, int array[], int array_len )
{
	int	i;

	/*
	** For each location in the array ...
	*/
	for( i = 0; i < array_len; i += 1 )
		/*
		** Check the location for the desired value.
		*/
		if( array[ i ] == key )
			return &array[ i ];

	return NULL;
}
