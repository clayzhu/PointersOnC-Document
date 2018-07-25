/*
** String copy that returns a pointer to the end
** of the destination argument.  (Version 1)
*/

#include <string.h>

char *
my_strcpy_end( char *dst, char const *src )
{
	strcpy( dst, src );

	return dst + strlen( dst );
}
