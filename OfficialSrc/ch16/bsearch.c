/*
** Demonstrates searching an array of structures with bsearch
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
	Record	key;
	Record	*ans;

	/*
	** Code that fills the array with 50 elements and sorts it
	*/

	/*
	** Create a key record (only the key field filled in with the
	** value we want to locate) and search the array.
	*/
	strcpy( key.key, "value" );
	ans = bsearch( &key, array, 50, sizeof( Record ),
	    r_compare );

	/*
	** ans now points to the array element whose key field
	** matches the value, or NULL if none matched.
	*/

	return EXIT_SUCCESS;
}
