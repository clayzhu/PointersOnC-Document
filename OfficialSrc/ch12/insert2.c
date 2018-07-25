/*
** Insert into an ordered, singly linked list.  The arguments are
** a pointer to the root pointer for the list, and the value to
** insert.
*/
#include <stdlib.h>
#include <stdio.h>
#include "sll_node.h"

#define	FALSE	0
#define TRUE	1

int
sll_insert( Node **rootp, int new_value )
{
	Node	*current;
	Node	*previous;
	Node	*new;

	/*
	** Get the pointer to the first node.
	*/
	current = *rootp;
	previous = NULL;

	/*
	** Look for the right place by walking down the list
	** until we reach a node whose value is greater than
	** or equal to the new value.
	*/
	while( current != NULL && current->value < new_value ){
		previous = current;
		current = current->link;
	}

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
	if( previous == NULL )
		*rootp = new;
	else
		previous->link = new;
	return TRUE;
}
