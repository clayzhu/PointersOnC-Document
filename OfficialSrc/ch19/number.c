/*
** Copy the standard input to the standard output, and number the
** output lines.
*/

#include <stdio.h>
#include <stdlib.h>

int
main()
{
	int	ch;
	int	line;
	int	at_beginning;

	line = 0;
	at_beginning = 1;
	/*
	** Read characters and process them one by one.
	*/
	while( (ch = getchar()) != EOF ){
		/*
		** If we're at the beginning of a line, print the
		** line number.
		*/
		if( at_beginning == 1 ){
			at_beginning = 0;
			line += 1;
			printf( "%d ", line );
		}

		/*
		** Print the character, and check for end of line.
		*/
		putchar( ch );
		if( ch == '\n' )
			at_beginning = 1;
	}

	return EXIT_SUCCESS;
}
