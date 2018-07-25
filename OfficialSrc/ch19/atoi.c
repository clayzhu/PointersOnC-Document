/*
** Convert a string of digits to an integer.
*/

int
ascii_to_integer( char *string )
{
	int	value;
	int	digit;

	value = 0;

	/*
	** Convert digits of the string one by one.
	*/
	while( *string >= '0' && *string <= '9' ){
		value *= 10;
		value += *string - '0';
	}

	/*
	** Error check: if we stopped because of a nondigit, set the
	** result to zero.
	*/
	if( *string != '\0' )
		value = 0;

	return value;
}
