/*
** Compute the value of a Hermite polynomial
**
**	Inputs:
**		n, x: identifying values
**
**	Output:
**		value of polynomial (return value)
*/

int
hermite( int n, int x )
{
	/*
	** Do special cases where no recursion is required.
	*/
	if( n <= 0 )
		return 1;
	if( n == 1 )
		return 2 * x;

	/*
	** Otherwise, recursively compute value.
	*/
	return 2 * x * hermite( n - 1, x ) -
	    2 * ( n - 1 ) * hermite( n - 2, x );
}
