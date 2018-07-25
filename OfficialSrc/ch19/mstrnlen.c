/*
** Safe string length.  Returns the length of a string that
** is possibly not NUL-terminated.  'size' is the length of the
** buffer in which this string is stored.
*/

#include <string.h>
#include <stddef.h>

size_t
my_strnlen( char const *string, int size )
{
	register size_t	length;

	for( length = 0; length < size; length += 1 )
		if( *string++ == '\0' )
			break;

	return length;
}
