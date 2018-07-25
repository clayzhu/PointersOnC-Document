/*
** Program to determine the C runtime environment.
*/

/*
** Static initialization
*/
int	static_variable = 5;

void
f()
{
	register int	i1, i2, i3, i4, i5,
			i6, i7, i8, i9, i10;
	register char	*c1, *c2, *c3, *c4, *c5,
			*c6, *c7, *c8, *c9, *c10;
	extern	int	a_very_long_name_to_see_how_long_they_can_be;
	double	dbl;
	int	func_ret_int();
	double	func_ret_double();
	char	*func_ret_char_ptr();

	/*
	** Maximum number of register variables.
	*/
	i1 = 1; i2 = 2; i3 = 3; i4 = 4; i5 = 5;
	i6 = 6; i7 = 7; i8 = 8; i9 = 9; i10 = 10;
	c1 = (char *)110; c2 = (char *)120;
	c3 = (char *)130; c4 = (char *)140;
	c5 = (char *)150; c6 = (char *)160;
	c7 = (char *)170; c8 = (char *)180;
	c9 = (char *)190; c10 = (char *)200;

	/*
	** External names
	*/
	a_very_long_name_to_see_how_long_they_can_be = 1;

	/*
	** Function calling/returning protocol, stack frame
	*/
	i2 = func_ret_int( 10, i1, i10 );
	dbl = func_ret_double();
	c1 = func_ret_char_ptr( c1 );
}

int
func_ret_int( int a, int b, register int c )
{
	int	d;

	d = b - 6;
	return a + b + c;
}

double
func_ret_double()
{
	return 3.14;
}

char *
func_ret_char_ptr( char *cp )
{
	return cp + 1;
}
