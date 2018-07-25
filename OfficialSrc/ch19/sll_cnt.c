/*
** Count the number of nodes on a singly linked list.
*/

#include "singly_linked_list_node.h"
#include <stdio.h>

int
sll_count_nodes( struct NODE *first )
{
	int	count;

	for( count = 0; first != NULL; first = first->link ){
		count += 1;
	}

	return count;
}
