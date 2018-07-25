/*
** Multiply two matrices together.
*/

void
matrix_multiply( int *m1, int *m2, register int *r,
    int x, int y, int z )
{
	register int	*m1p;
	register int	*m2p;
	register int	k;
	int	row;
	int	column;

	/*
	** The outer two loops go through the solution matrix element
	** by element.  Because this is done in storage order, we
	** can access these elements using indirection on r.
	*/
	for( row = 0; row < x; row += 1 ){
		for( column = 0; column < z; column += 1 ){
			/*
			** Compute one value in the result.  This is
			** done by getting pointers to the proper
			** elements in m1 and m2, and then advancing
			** them as we go through the loop.
			*/
			m1p = m1 + row * y;
			m2p = m2 + column;
			*r = 0;

			for( k = 0; k < y; k += 1 ){
				*r += *m1p * *m2p;
				m1p += 1;
				m2p += z;
			}

			/*
			** Advance r to point to the next element.
			*/
			r++;
		}
	}
}
