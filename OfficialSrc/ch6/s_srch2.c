/*
** Given a pointer to a NULL-terminated list of pointers, search
** the strings in the list for a particular character.  This
** version destroys the pointers so it can only be used when
** the collection will be examined only once.
*/

#include <stdio.h>
#include <assert.h>

#define	TRUE	1
#define	FALSE	0

int
find_char( char **strings, int value )
{
	assert( strings != NULL );

	/*
	** For each string in the list ...
	*/
	while( *strings != NULL ){
		/*
		** Look at each character in the string to see if
		** it is the one we want.
		*/
		while( **strings != '\0' ){
			if( *(*strings)++ == value )
				return TRUE;
		}
		strings++;
	}
	return FALSE;
}
