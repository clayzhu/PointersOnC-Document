/*
** Compute the factorial of n, recursively
*/

long
factorial( int n )
{
	if( n <= 0 )
		return 1;
	else
		return n * factorial( n - 1 );
}
