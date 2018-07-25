/*
** Read an EOF-terminated list of integers from the standard input
** and return a dynamically allocated array containing the values.
** The first element of the array contains a count of the number
** of values it contains.
*/

#include <stdio.h>
#include <malloc.h>

#define	DELTA		100

int *
readints()
{
	int	*array;
	int	size;
	int	count;
	int	value;

	/*
	** Get the initial array, large enough to hold DELTA values.
	*/
	size = DELTA;
	array = malloc( ( size + 1 ) * sizeof( int ) );
	if( array == NULL )
		return NULL;

	/*
	** Get values from the standard input.
	*/
	count = 0;
	while( scanf( "%d", &value ) == 1 ){
		/*
		** Make the array bigger if needed, then store
		** the value.
		*/
		count += 1;
		if( count > size ){
			size += DELTA;
			array = realloc( array,
			    ( size + 1 ) * sizeof( int ) );
			if( array == NULL )
				return NULL;
		}
		array[ count ] = value;
	}

	/*
	** Resize the array to the exact size, then store the count
	** and return the array.  This never makes the array bigger
	** and so should never fail.  (Check it anyway!)
	*/
	if( count < size ){
		array = realloc( array,
		    ( count + 1 ) * sizeof( int ) );
		if( array == NULL )
			return NULL;
	}
	array[ 0 ] = count;
	return array;
}
