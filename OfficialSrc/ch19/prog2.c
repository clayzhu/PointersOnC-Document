/*
** Copy standard input to standard output, one line
** at a time.  Lines must be 80 data bytes or shorter.
*/

#include <stdio.h>

#define	BUFSIZE	81	/* 80 data bytes + the null byte */

main()
{
	char	buf[BUFSIZE];

	while( gets( buf ) != NULL )
		puts( buf );

	return EXIT_SUCCESS;
}
