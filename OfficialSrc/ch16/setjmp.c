/*
** A program to demonstrate the use of setjmp
*/
#include "trans.h"
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

/*
**	The variable that stores setjmp's state information.
*/
jmp_buf	restart;

int
main()
{
	int	value;
	Trans	*transaction;

	/*
	** Establish the point at which we want to resume execution
	** after a call to longjmp.
	*/
	value = setjmp( restart );

	/*
	** Figure out what to do after a return from setjmp.
	*/
	switch( value ){
	default:
		/*
		** longjmp was called -- fatal error
		*/
		fputs( "Fatal error.\n", stderr );
		break;

	case 1:
		/*
		** longjmp was called -- minor error
		*/
		fputs( "Invalid transaction.\n", stderr );
		/* FALL THROUGH and continue processing */

	case 0:
		/*
		** Original return from setjmp: perform normal
		** processing.
		*/
		while( (transaction = get_trans()) != NULL )
			process_trans( transaction );

	}

	/*
	** Save data and exit the program
	*/
	write_data_to_file();

	return value == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
