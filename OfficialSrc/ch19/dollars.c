/*
** Convert the digit string 'src' to dollars-and-cents form and store
** it in 'dst'.
*/

#include <stdio.h>

void
dollars( register char *dst, register char const *src )
{
	int	len;

	if( dst == NULL || src == NULL )
		return;

	*dst++ = '$';
	len = strlen( src );

	/*
	** If digit string is long enough, copy the digits that will
	** be on the left of the decimal point, putting in commas
	** where appropriate.  If the string is shorter than 3
	** digits, force a '0' into dst ahead of the '.' .
	*/
	if( len >= 3 ){
		int	i;

		for( i = len - 2; i > 0; ){
			*dst++ = *src++;
			if( --i > 0 && i % 3 == 0 )
				*dst++ = ',';
		}
	} else
		*dst++ = '0';

	/*
	** Store the decimal point, and then store the remaining
	** digits from 'src'.  If 'src' had fewer than two digits,
	** force in '0's instead.  Then NUL terminate 'dst'.
	*/
	*dst++ = '.';
	*dst++ = len < 2 ? '0' : *src++;
	*dst++ = len < 1 ? '0' : *src;
	*dst = 0;
}
