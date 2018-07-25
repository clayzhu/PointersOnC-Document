/*
** Reverse the string contained in the argument.
*/

void
reverse_string( char *str )
{
	char	*last_char;

	/*
	** Set last_char to point to the last character in the
	** string.
	*/
	for( last_char = str; *last_char != '\0'; last_char++ )
		;

	last_char--;

	/*
	** Interchange the characters that str and last_char point
	** to, advance str and move last_char back one, and keep
	** doing this until the two pointers meet or cross.
	*/
	while( str < last_char ){
		char	temp;

		temp = *str;
		*str++ = *last_char;
		*last_char-- = temp;
	}
}
