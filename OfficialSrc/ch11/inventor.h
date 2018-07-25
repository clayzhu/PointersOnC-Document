/*
** Declarations for the inventory record.
**
**	Structure that contains information about a part.
*/
typedef struct	{
	int	cost;
	int	supplier;
	/* etc. */
} Partinfo;

/*
**	Structure to hold information about a subassembly.
*/
typedef	struct	{
	int	n_parts;
	struct	SUBASSYPART {
		char	partno[10];
		short	quan;
	} *part;
} Subassyinfo;

/*
**	Structure for an inventory record, which is a variant record.
*/
typedef	struct	{
	char	partno[10];
	int	quan;
	enum	{ PART, SUBASSY }	type;
	union	{
		Partinfo	*part;
		Subassyinfo	*subassy;
	} info;
} Invrec;
