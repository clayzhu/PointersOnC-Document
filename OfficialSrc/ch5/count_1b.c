/*
** This function returns the number of 1-bits that appeared in
** the argument value.
*/
int
count_one_bits( unsigned value )
{
	int	ones;

	/*
	** While the value still has some 1-bits in it ...
	*/
	for( ones = 0; value != 0; value >>= 1 )
		/*
		** If the low-order bit is a 1, count it.
		*/
		if( ( value & 1 ) != 0 )
			ones += 1;

	return ones;
}
