/*
** Process a line of input by concatenating the characters from
** the indicated columns.  The output line is then NUL terminated.
*/
void
rearrange( char *output, char const *input,
    int const n_columns, int const columns[] )
{
	int	col;		/* subscript for columns array */
	int	output_col;	/* output column counter */
	int	len;		/* length of input line */

	len = strlen( input );
	output_col = 0;

	/*
	** Process each pair of column numbers.
	*/
	for( col = 0; col < n_columns; col += 2 ){
		int	nchars = columns[col + 1] - columns[col] + 1;

		/*
		** If the input line isn't this long, skip the range.
		*/
		if( columns[col] >= len )
			continue;

		/*
		** If the output array is full, we're done.
		*/
		if( output_col == MAX_INPUT - 1 )
			break;

		/*
		** If there isn't room in the output array, only copy
		** what will fit.
		*/
		if( output_col + nchars > MAX_INPUT - 1 )
			nchars = MAX_INPUT - output_col - 1;

		/*
		** See how many characters the input line has in this
		** range.  If it is less than nchars, adjust nchars.
		*/
		if( columns[col] + nchars - 1 >= len )
			nchars = len - columns[col];

		/*
		** Copy the relevant data.
		*/
		strncpy( output + output_col, input + columns[col],
		    nchars );
		output_col += nchars;
	}

	output[output_col] = '\0';
}
