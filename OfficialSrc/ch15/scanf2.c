/*
** Variable format input processing with sscanf
*/
#include <stdio.h>
#include <stdlib.h>

#define	DEFAULT_A	1	/* or whatever ... */
#define	DEFAULT_B	2	/* or whatever ... */

void
function( char *buffer )
{
	int	a, b, c;

	/*
	** See if all three values are given.
	*/
	if( sscanf( buffer, "%d %d %d", &a, &b, &c ) != 3 ){
		/*
		** No, use default value for a, see if other two
		** values are both given.
		*/
		a = DEFAULT_A;
		if( sscanf( buffer, "%d %d", &b, &c ) != 2 ){
			/*
			** Use default value for b too, look for
			** remaining value.
			*/
			b = DEFAULT_B;
			if( sscanf( buffer, "%d", &c ) != 1 ){
				fprintf( stderr, "Bad input: %s",
				    buffer );
				exit( EXIT_FAILURE );
			}
		}
	}
	/*
	** Process the values a, b, and c.
	*/
}
