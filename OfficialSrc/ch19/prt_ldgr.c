/*
** Print the indicated ledger in whichever style(s) is
** indicated by the symbols that are defined.
*/

void
print_ledger( int x )
{
#ifdef	OPTION_LONG
#	define	OK	1
	print_ledger_long( x );
#endif

#ifdef	OPTION_DETAILED
#	define	OK	1
	print_ledger_detailed( x );
#endif

#ifndef	OK
	print_ledger_default( x );
#endif
}
