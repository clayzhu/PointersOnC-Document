/*
** String copy that returns a pointer to the end
** of the destination argument, without using any
** of the library string routines.  (Version 2)
*/

#include <string.h>

char *
my_strcpy_end( register char *dst, register char const *src )
{
	while( ( *dst++ = *src++ ) != '\0' )
		;

	return dst - 1;
}
