/*
** Insert into an ordered, singly linked list.  The arguments are
** a pointer to the first node in the list, and the value to
** insert.
*/
#include <stdlib.h>
#include <stdio.h>
#include "sll_node.h"

#define	FALSE	0
#define TRUE	1

int
sll_insert( register Node **linkp, int new_value )
{
	register Node	*current;
	register Node	*new;

	/*
	** Look for the right place by walking down the list
	** until we reach a node whose value is greater than
	** or equal to the new value.
	*/
	while( ( current = *linkp ) != NULL &&
	    current->value < new_value )
		linkp = &current->link;

	/*
	** Allocate a new node and store the new value into it.
	** In this event, we return FALSE.
	*/
	new = (Node *)malloc( sizeof( Node ) );
	if( new == NULL )
		return FALSE;
	new->value = new_value;

	/*
	** Insert the new node into the list, and return TRUE.
	*/
	new->link = current;
	*linkp = new;
	return TRUE;
}
