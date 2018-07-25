/*
** Mystery function
**
**	The argument is a value in the range 0 through 100.
*/
#include <stdio.h>

void
mystery( int n )
{
	n += 5;
	n /= 10;
	printf( "%s\n", "**********" + 10 - n );
}
