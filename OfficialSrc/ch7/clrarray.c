/*
** Set all of the elements of an array to zero.
*/

void
clear_array( int array[], int n_elements )
{
	/*
	** Clear the elements of the array starting with the last
	** and working towards the first.  Note the predecrement
	** avoids going off the end of the array.
	*/
	while( n_elements > 0 )
		array[ --n_elements ] = 0;
}
