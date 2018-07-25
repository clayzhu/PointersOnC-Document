/*
** Take an integer value (unsigned), convert it to characters, and
** print it.  Leading zeros are suppressed.
*/
#include <stdio.h>

void
binary_to_ascii( unsigned int value )
{
	unsigned int	quotient;

	quotient = value / 10;
	if( quotient != 0 )
		binary_to_ascii( quotient );
	putchar( value % 10 + '0' );
}
