/*
** Declarations for the address list module.
*/

/*
** Data characteristics
**
**	Maximum lengths of the various data (includes space for the
**	terminating NUL byte), and maximum number of addresses.
*/
#define	NAME_LENGTH	30		/* longest name allowed */
#define	ADDR_LENGTH	100		/* longest address allowed */
#define	PHONE_LENGTH	11		/* longest phone # allowed */

#define	MAX_ADDRESSES	1000		/* # of addresses allowed */

/*
** Interface functions
**
**	Given a name, find the corresponding address.
*/
char const *
lookup_address( char const *name );

/*
**	Given a name, find the corresponding phone number.
*/
char const *
lookup_phone( char const *name );
