/*
** A binary search tree implemented by linking dynamically allocated
** structures.
*/
#include "tree.h"
#include <assert.h>
#include <stdio.h>
#include <malloc.h>

/*
**	The TreeNode structure holds the value and pointers for one
**	tree node.
*/
typedef struct TREE_NODE {
	TREE_TYPE	value;
	struct TREE_NODE *left;
	struct TREE_NODE *right;
} TreeNode;

/*
**	The pointer to the root node in the tree.
*/
static	TreeNode	*tree;

/*
**	insert
*/
void
insert( TREE_TYPE value )
{
	TreeNode	*current;
	TreeNode	**link;

	/*
	** Start with the root node.
	*/
	link = &tree;

	/*
	** As long as we keep finding values, go to the proper
	** subtree.
	*/
	while( (current = *link) != NULL ){
		/*
		** Go to the left or right subtree, as appropriate.
		** (And make sure we don't have a duplicate value!)
		*/
		if( value < current->value )
			link = &current->left;
		else {
			assert( value != current->value );
			link = &current->right;
		}
	}
	
	/*
	** Allocate a new node; make the proper link field point
	** to it.
	*/
	current = malloc( sizeof( TreeNode ) );
	assert( current != NULL );
	current->value = value;
	current->left = NULL;
	current->right = NULL;
	*link = current;
}

/*
**	find
*/
TREE_TYPE *
find( TREE_TYPE value )
{
	TreeNode	*current;

	/*
	** Start with the root node.  Until we find the value,
	** go to the proper subtree.
	*/
	current = tree;

	while( current != NULL && current->value != value ){
		/*
		** Go to the left or right subtree, as appropriate.
		*/
		if( value < current->value )
			current = current->left;
		else
			current = current->right;
	}
	
	if( current != NULL )
		return &current->value;
	else
		return NULL;
}

/*
** do_pre_order_traverse
**	Do one level of a pre-order traverse.  This helper function
**	is needed to save the information of which node we're
**	currently processing; this is not a part of the
**	client's interface.
*/
static void
do_pre_order_traverse( TreeNode *current,
    void (*callback)( TREE_TYPE value ) )
{
	if( current != NULL ){
		callback( current->value );
		do_pre_order_traverse( current->left, callback );
		do_pre_order_traverse( current->right, callback );
	}
}

/*
**	pre_order_traverse
*/
void
pre_order_traverse( void (*callback)( TREE_TYPE value ) )
{
	do_pre_order_traverse( tree, callback );
}
