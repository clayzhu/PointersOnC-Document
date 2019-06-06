/*
** Given a pointer to a NULL-terminated list of pointers, search
** the strings in the list for a particular character.
*/

#include <stdio.h>

#define	TRUE	1
#define	FALSE	0

int
find_char( char **strings, char value )
{
	char	*string;	/* the string we're looking at */

	/*
	** For each string in the list ...
	*/
	while( ( string = *strings++ ) != NULL ){
		/*
		** Look at each character in the string to see if
		** it is the one we want.
		*/
		while( *string != '\0' ){
			if( *string++ == value )
				return TRUE;
		}
	}
	return FALSE;
}
