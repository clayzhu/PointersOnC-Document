/*
** A queue implemented with a static array.  The array size can
** be adjusted only by changing the #define and recompiling
** the module.
*/
#include "queue.h"
#include <stdio.h>
#include <assert.h>

#define	QUEUE_SIZE	100	/* Max # of values on the queue */
#define	ARRAY_SIZE	( QUEUE_SIZE + 1 )	/* Size of array */

/*
**	The array that holds the values on the queue, and pointers
**	to the front and rear of the queue.
*/
static	QUEUE_TYPE	queue[ ARRAY_SIZE ];
static	size_t		front = 1;
static	size_t		rear = 0;

/*
**	insert
*/
void
insert( QUEUE_TYPE value )
{
	assert( !is_full() );
	rear = ( rear + 1 ) % ARRAY_SIZE;
	queue[ rear ] = value;
}

/*
**	delete
*/
void
delete( void )
{
	assert( !is_empty() );
	front = ( front + 1 ) % ARRAY_SIZE;
}

/*
**	first
*/
QUEUE_TYPE first( void )
{
	assert( !is_empty() );
	return queue[ front ];
}

/*
**	is_empty
*/
int
is_empty( void )
{
	return ( rear + 1 ) % ARRAY_SIZE == front;
}

/*
**	is_full
*/
int
is_full( void )
{
	return ( rear + 2 ) % ARRAY_SIZE == front;
}
