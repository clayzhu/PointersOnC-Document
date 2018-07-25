/*
** A stack implemented with a dynamically allocated array.
** The array size is given when create is called, which must
** happen before any other stack operations are attempted.
*/
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>

/*
**	The array that holds the values on the stack, and a pointer
**	to the topmost value on the stack.
*/
static	STACK_TYPE	*stack;
static	size_t		stack_size;
static	int		top_element = -1;

/*
**	create_stack
*/
void
create_stack( size_t size )
{
	assert( stack_size == 0 );
	stack_size = size;
	stack = malloc( stack_size * sizeof( STACK_TYPE ) );
	assert( stack != NULL );
}

/*
**	destroy_stack
*/
void
destroy_stack( void )
{
	assert( stack_size > 0 );
	stack_size = 0;
	free( stack );
	stack = NULL;
}

/*
**	push
*/
void
push( STACK_TYPE value )
{
	assert( !is_full() );
	top_element += 1;
	stack[ top_element ] = value;
}

/*
**	pop
*/
void
pop( void )
{
	assert( !is_empty() );
	top_element -= 1;
}

/*
**	top
*/
STACK_TYPE top( void )
{
	assert( !is_empty() );
	return stack[ top_element ];
}

/*
**	is_empty
*/
int
is_empty( void )
{
	assert( stack_size > 0 );
	return top_element == -1;
}

/*
**	is_full
*/
int
is_full( void )
{
	assert( stack_size > 0 );
	return top_element == stack_size - 1;
}
