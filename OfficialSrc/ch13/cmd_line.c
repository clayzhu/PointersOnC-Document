/*
** Process command-line arguments
*/
#include <stdio.h>
#define	TRUE	1

/*
**	Prototypes for functions that do the real work.
*/
void	process_standard_input( void );
void	process_file( char *file_name );

/*
**	Option flags, default initialization is FALSE.
*/
int	option_a, option_b /* etc. */ ;

void
main( int argc, char **argv )
{
	/*
	** Process option arguments: skip to next argument, and
	** check that it begins with a dash.
	*/
	while( *++argv != NULL && **argv == '-' ){
		/*
		** Check the letter after the dash.
		*/
		switch( *++*argv ){
		case 'a':
			option_a = TRUE;
			break;

		case 'b':
			option_b = TRUE;
			break;

		/* etc. */
		}
	}

	/*
	** Process file name arguments
	*/
	if( *argv == NULL )
		process_standard_input();
	else {
		do {
			process_file( *argv );
		} while( *++argv != NULL );
	}
}
