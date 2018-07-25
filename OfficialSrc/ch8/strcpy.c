/*
**  Copy the string contained in the second argument to the
** buffer specified by the first argument.
*/
void
strcpy( char *buffer, char const *string )
{
	/*
	** Copy characters until a NUL byte is copied.
	*/
	while( (*buffer++ = *string++) != '\0' )
		;
}
