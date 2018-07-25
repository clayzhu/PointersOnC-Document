/*
** Interface for a binary search tree module
*/

#define	TREE_TYPE	int	/* Type of value in the tree */

/*
** insert
**	Add a new value to the tree.  The argument is the value
**	to be added and must not already exist in the tree.
*/
void	insert( TREE_TYPE value );

/*
** find
**	Searches for a specific value, which is passed as the first
**	argument.
*/
TREE_TYPE *find( TREE_TYPE value );

/*
** pre_order_traverse
**	Does a pre-order traversal of the tree.  The argument is a
**	pointer to a callback function that will be called for
**	each node in the tree, with the value passed as an argument.
*/
void	pre_order_traverse( void (*callback)( TREE_TYPE value ) );
