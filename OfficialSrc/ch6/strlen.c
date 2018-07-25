/*
** Compute the length of a string.
*/

#include <stdlib.h>

size_t
strlen( char *string )
{
	int	length = 0;

	/*
	** Advance through the string, counting characters
	** until the terminating NUL byte is reached.
	*/
	while( *string++ != '\0' )
		length += 1;

	return length;
}
