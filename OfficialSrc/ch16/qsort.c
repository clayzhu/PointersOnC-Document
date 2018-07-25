/*
** Demonstrates sorting an array of structures with qsort
*/
#include <stdlib.h>
#include <string.h>

typedef	struct	{
	char	key[ 10 ];	/* the sort key for the array */
	int	other_data;	/* data associated with the key */
} Record;

/*
** Comparison function: compares only the key value.
*/
int r_compare( void const *a, void const *b ){
	return strcmp( ((Record *)a)->key, ((Record *)b)->key );
}

int
main()
{
	Record	array[ 50 ];

	/*
	** Code that fills the array with 50 elements.
	*/

	qsort( array, 50, sizeof( Record ), r_compare );

	/*
	** Array is now sorted by the key field of the structures.
	*/

	return EXIT_SUCCESS;
}
