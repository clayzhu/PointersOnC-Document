/*
** Copy the standard input to the standard output, converting
** all uppercase characters to lowercase.  Note: This depends
** on the fact that tolower returns its argument unchanged if
** the argument is not an uppercase letter.
*/
#include <stdio.h>
#include <ctype.h>

int
main( void )
{
	int	ch;

	while( (ch = getchar()) != EOF )
		putchar( tolower( ch ) );
}
