/*
** Find and print all of the lines in the named files that
** contain the given string.
**
**	Usage:
**		fgrep string file [ file ... ]
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define	BUFFER_SIZE	512

void
search( char *filename, FILE *stream, char *string )
{
	char	buffer[ BUFFER_SIZE ];

	while( fgets( buffer, BUFFER_SIZE, stream ) != NULL ){
		if( strstr( buffer, string ) != NULL ){
			if( filename != NULL )
				printf( "%s:", filename );
			fputs( buffer, stdout );
		}
	}
}

int
main( int ac, char **av )
{
	char	*string;

	if( ac <= 1 ){
		fprintf( stderr, "Usage: fgrep string file ...\n" );
		exit( EXIT_FAILURE );
	}

	/*
	** Get the string.
	*/
	string = *++av;

	/*
	** Process the files.
	*/
	if( ac <= 2 )
		search( NULL, stdin, string );
	else {
		while( *++av != NULL ){
			FILE	*stream;

			stream = fopen( *av, "r" );
			if( stream == NULL )
				perror( *av );
			else {
				search( *av, stream, string );
				fclose( stream );
			}
		}
	}

	return EXIT_SUCCESS;
}
