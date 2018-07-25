/*
** Look in the string s1 for the rightmost occurrence of the string
** s2, and return a pointer to where it begins.
*/
#include <string.h>

char	*
my_strrstr( char const *s1, char const *s2 )
{
	register char	*last;
	register char	*current;

	/*
	** Initialize pointer for the last match we've found.
	*/
	last = NULL;

	/*
	** Search only if the second string is not empty.  If s2 is
	** empty, return NULL.
	*/
	if( *s2 != '\0' ){
		/*
		** Find the first place where s2 appears in s1.
		*/
		current = strstr( s1, s2 );

		/*
		** Each time we find the string, save the pointer to
		** where it begins.  Then look after the string for
		** another occurrence.
		*/
		while( current != NULL ){
			last = current;
			current = strstr( last + 1, s2 );
		}
	}

	/*
	** Return pointer to the last occurrence we found.
	*/
	return last;
}
