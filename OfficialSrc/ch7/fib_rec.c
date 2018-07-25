/*
** Compute the value of the n'th Fibonacci number, recursively.
*/

long
fibonacci( int n )
{
	if( n <= 2 )
		return 1;

	return fibonacci( n - 1 ) + fibonacci( n - 2 );
}
