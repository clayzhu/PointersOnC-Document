/*
** Copy the standard input to the standard output, converting
** all uppercase characters to lowercase.
*/
#include <stdio.h>

int
main( void )
{
	int	ch;

	while( (ch = getchar()) != EOF ){
		if( ch >= 'A' && ch <= 'Z' )
			ch += 'a' - 'A';
		putchar( ch );
	}
}
