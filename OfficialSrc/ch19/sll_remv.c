/*
** Remove a specified node from a singly linked list.  The first
** argument points to the root pointer for the list, and the second
** points to the node to be removed. TRUE is returned if it can be
** removed, otherwise FALSE is returned.
*/

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "singly_linked_list_node.h"

#define	FALSE	0
#define TRUE	1

int
sll_remove( struct NODE **linkp, struct NODE *delete )
{
	register Node	*current;

	assert( delete != NULL );

	/*
	** Look for the indicated node.
	*/
	while( ( current = *linkp ) != NULL && current != delete )
		linkp = &current->link;

	if( current == delete ){
		*linkp = current->link;
		free( current );
		return TRUE;
	}
	else 
		return FALSE;
}
