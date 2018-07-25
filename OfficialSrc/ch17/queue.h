/*
** Interface for a queue module
*/

#include <stdlib.h>

#define	QUEUE_TYPE	int	/* Type of value in the queue */

/*
** create_queue
**	Creates a queue.  The argument indicates the maximum number
**	of values that the queue will hold.  NOTE: this applies only
**	to the dynamically allocated array implementation.
*/
void	create_queue( size_t size );

/*
** destroy_queue
**	Destroys a queue.  NOTE: this applies only to the linked and
**	dynamically allocated array implementations.
*/
void	destroy_queue( void );

/*
** insert
**	Adds a new value on the queue.  The argument is the value
**	to be inserted.
*/
void	insert( QUEUE_TYPE value );

/*
** delete
**	Removes a value from the queue, discarding it.
*/
void	delete( void );

/*
** first
**	Returns the first value on the queue without changing the
**	queue itself.
*/
QUEUE_TYPE first( void );

/*
** is_empty
**	Returns TRUE if the queue is empty, else FALSE
*/
int	is_empty( void );

/*
** is_full
**	Returns TRUE if the queue is full, else FALSE
*/
int	is_full( void );
