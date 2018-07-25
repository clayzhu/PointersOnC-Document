/*
** Exchange two integers in the calling program.
*/

void
swap( int *x, int *y )
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
