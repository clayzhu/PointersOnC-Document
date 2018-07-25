/*
** Function to search a linked list for a specific value.  Arguments
** are a pointer to the first node in the list, a pointer to the
** value we're looking for, and a pointer to a function that compares
** values of the type stored on the list.
*/
#include <stdio.h>
#include "node.h"

Node *
search_list( Node *node, void const *value,
    int (*compare)( void const *, void const * ) )
{
	while( node != NULL ){
		if( compare( &node->value, value ) == 0 )
			break;
		node = node->link;
	}
	return node;
}
