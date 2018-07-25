/*
** Count the number of times the word "the" appears in the standard
** input.  Case is important, and the words in the input are
** separated from each other by one or more white space characters.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	const	whitespace[] = " \n\r\f\t\v";

int
main()
{
	char	buffer[101];
	int	count;

	count = 0;

	/*
	** Read lines until EOF is found.
	*/
	while( gets( buffer ) ){
		char	*word;

		/*
		** Extract words from the buffer one by one
		** until there are no more.
		*/
		for( word = strtok( buffer, whitespace );
		    word != NULL;
		    word = strtok( NULL, whitespace ) ){
			if( strcmp( word, "the" ) == 0 )
				count += 1;
		}
	}

	printf( "%d\n", count );

	return EXIT_SUCCESS;
}
