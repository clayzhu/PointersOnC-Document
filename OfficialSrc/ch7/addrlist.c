/*
** Abstract data type to maintain an address list.
*/

#include "addrlist.h"
#include <stdio.h>

/*
**	The three parts to each address are kept in corresponding
**	elements of these three arrays.
*/
static	char	name[MAX_ADDRESSES][NAME_LENGTH];
static	char	address[MAX_ADDRESSES][ADDR_LENGTH];
static	char	phone[MAX_ADDRESSES][PHONE_LENGTH];

/*
**	This routine locates a name in the array and returns the
**	subscript of the location found.  If the name does not exist,
**	-1 is returned.
*/
static int
find_entry( char const *name_to_find )
{
	int	entry;

	for( entry = 0; entry < MAX_ADDRESSES; entry += 1 )
		if( strcmp( name_to_find, name[ entry ] ) == 0 )
			return entry;

	return -1;
}

/*
**	Given a name, look up and return the corresponding address. 
**	If the name was not found, return a NULL pointer instead.
*/
char const *
lookup_address( char const *name )
{
	int	entry;

	entry = find_entry( name );
	if( entry == -1 )
		return NULL;
	else
		return address[ entry ];
}

/*
**	Given a name, look up and return the corresponding phone
**	number. If the name was not found, return a NULL pointer
**	instead.
*/
char const *
lookup_phone( char const *name )
{
	int	entry;

	entry = find_entry( name );
	if( entry == -1 )
		return NULL;
	else
		return phone[ entry ];
}
