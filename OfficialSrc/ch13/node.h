/*
** Sample declaration for a linked list node.  Change this declaration
** as appropriate for your list values and recompile the linked list
** search function with it.  Note that the value can be anything you
** want -- not just a built-in type -- because your comparison function
** does the work of comparing it to the desired value.
*/

typedef struct NODE {
	struct	NODE	*link;
	int	value;
} Node;
