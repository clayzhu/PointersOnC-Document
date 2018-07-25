/*
** A stack implemented with a linked list.  This stack has no size
** limit.
*/
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

#define	FALSE 0

/*
**	Define a structure to hold one value.  The link field will
**	point to the next value on the stack.
*/
typedef	struct	STACK_NODE {
	STACK_TYPE	value;
	struct STACK_NODE *next;
} StackNode;

/*
**	A pointer to the topmost node on the stack.
*/
static	StackNode	*stack;

/*
**	create_stack
*/
void
create_stack( size_t size )
{
}

/*
**	destroy_stack
*/
void
destroy_stack( void )
{
	while( !is_empty() )
		pop();
}

/*
**	push
*/
void
push( STACK_TYPE value )
{
	StackNode	*new_node;

	new_node = malloc( sizeof( StackNode ) );
	assert( new_node != NULL );
	new_node->value = value;
	new_node->next = stack;
	stack = new_node;
}

/*
**	pop
*/
void
pop( void )
{
	StackNode	*first_node;

	assert( !is_empty() );
	first_node = stack;
	stack = first_node->next;
	free( first_node );
}

/*
**	top
*/
STACK_TYPE top( void )
{
	assert( !is_empty() );
	return stack->value;
}

/*
**	is_empty
*/
int
is_empty( void )
{
	return stack == NULL;
}

/*
**	is_full
*/
int
is_full( void )
{
	return FALSE;
}
