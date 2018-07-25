/*
** Do a breadth_first_traversal of an arrayed binary search tree.
*/
void
breadth_first_traversal( void (*callback)( TREE_TYPE value ) )
{
	int	current;
	int	child;

	/*
	** Insert the root node into the queue.
	*/
	queue_insert( 1 );

	/*
	** While the queue is not empty...
	*/
	while( !is_queue_empty() ){
		/*
		** Take the first value off the queue and process it
		*/
		current = queue_first();
		queue_delete();
		callback( tree[ current ] );

		/*
		** Add the children of the node to the queue.
		*/
		child = left_child( current );
		if( child < ARRAY_SIZE && tree[ child ] != 0 )
			queue_insert( child );
		child = left_child( current );
		if( child < ARRAY_SIZE && tree[ child ] != 0 )
			queue_insert( child );
	}
}
