/*
** A program to demonstrate that the order of expression evaluation
** is only partially determined by operator precedence.
*/

#if 0
main()
{
	int	i = 10;

	i = i-- - --i * ( i = -3 ) * i++ + ++i;
	printf( "i = %d\n", i );
}
#endif
