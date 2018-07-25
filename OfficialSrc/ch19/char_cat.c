/*
** Compute the percentage of characters read from the standard
** input that are in each of several character categories.
*/
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/*
**	Define a function to compute whether a character is not
**	printable; this eliminates a special case for this
**	category in the code below.
*/
int is_not_print( int ch )
{
	return !isprint( ch );
}

/*
**	Jump table of classification functions for each category.
*/
static	int	(*test_func[])( int ) = {
	iscntrl,
	isspace,
	isdigit,
	islower,
	isupper,
	ispunct,
	is_not_print
};
#define	N_CATEGORIES	\
	    ( sizeof( test_func ) / sizeof( test_func[ 0 ] ) )

/*
**	The name of each of the character categories.
*/
char	*label[] = {
	"control",
	"whitespace",
	"digit",
	"lower case",
	"upper case",
	"punctuation",
	"non-printable"
};

/*
**	Number of characters seen in each category so far, and
**	total # of characters.
*/
int	count[ N_CATEGORIES ];
int	total;

main()
{
	int	ch;
	int	category;

	/*
	** Read and process each character
	*/
	while( (ch = getchar()) != EOF ){
		total += 1;

		/*
		** Call each of the test functions with this
		** character; if true, increment the associated
		** counter.
		*/
		for( category = 0; category < N_CATEGORIES;
		    category += 1 ){
			if( test_func[ category ]( ch ) )
				count[ category ] += 1;
		}
	}

	/*
	** Print the results.
	*/
	if( total == 0 ){
		printf( "No characters in the input!\n" );
	}
	else {
		for( category = 0; category < N_CATEGORIES;
		    category += 1 ){
			printf( "%3.0f%% %s characters\n",
			    count[ category ] * 100.0 / total,
			    label[ category ] );
		}
	}

	return EXIT_SUCCESS;
}
