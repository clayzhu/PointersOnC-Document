/*
** Insert a value into a doubly linked list.  rootp is a pointer to
** the root node, and value is the new value to be inserted.
** Returns: 0 if the value is already in the list, -1 if there was
** no memory to create a new node, 1 if the value was added
** successfully.
*/
#include <stdlib.h>
#include <stdio.h>
#include "dll_node.h"

int
dll_insert( Node *rootp, int value )
{
	Node	*this;
	Node	*next;
	Node	*newnode;

	/*
	** See if value is already in the list; return if it is.
	** Otherwise, allocate a new node for the value ("newnode"
	** will point to it). "this" will point to the node that the
	** new value should follow, and "next" will point to the one
	** after it.
	*/
	for( this = rootp; (next = this->fwd) != NULL; this = next ){
		if( next->value == value )
			return 0;
		if( next->value > value )
			break;
	}
	newnode = (Node *)malloc( sizeof( Node ) );
	if( newnode == NULL )
		return -1;
	newnode->value = value;

	/*
	** Add the new node to the list.
	*/
	if( next != NULL ){
		/*
		** Case 1 or 2: not at end of the list 
		*/
		if( this != rootp ){	   /* Case 1: not at front */
			newnode->fwd = next;
			this->fwd = newnode;
			newnode->bwd = this;
			next->bwd = newnode;
		}
		else {			   /* Case 2: at front */
			newnode->fwd = next;
			rootp->fwd = newnode;
			newnode->bwd = NULL;
			next->bwd = newnode;
		}
	}
	else {
		/*
		** Case 3 or 4: at end of the list
		*/
		if( this != rootp ){	   /* Case 3: not at front */
			newnode->fwd = NULL;
			this->fwd = newnode;
			newnode->bwd = this;
			rootp->bwd = newnode;
		}
		else {			   /* Case 4: at front */
			newnode->fwd = NULL;
			rootp->fwd = newnode;
			newnode->bwd = NULL;
			rootp->bwd = newnode;
		}
	}
	return 1;
}
