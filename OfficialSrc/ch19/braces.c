/*
** Check the pairing of braces in a C program.
*/

#include <stdio.h>
#include <stdlib.h>

int
main()
{
	int	ch;
	int	braces;

	braces = 0;

	/*
	** Read the program character by character.
	*/
	while( (ch = getchar()) != EOF ){
		/*
		** Opening braces are always legal.
		*/
		if( ch == '{' )
			braces += 1;

		/*
		** A closing brace is legal only if matched to an
		** opening brace.
		*/
		if( ch == '}' )
			if( braces == 0 )
				printf( "Extra closing brace!\n" );
			else
				braces -= 1;
	}

	/*
	** No more input: make sure there aren't any opening braces
	** that were not matched.
	*/
	if( braces > 0 )
		printf( "%d unmatched opening brace(s)!\n", braces );

	return EXIT_SUCCESS;
}
