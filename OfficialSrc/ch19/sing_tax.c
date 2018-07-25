/*
** Compute the 1995 U.S. federal income tax for a single taxpayer.
*/

#include <float.h>

static	double	income_limits[]
	= { 0,	 23350,	 56550,	  117950,  256500,	DBL_MAX };
static	float	base_tax[]
	= { 0,	 3502.5, 12798.5, 31832.5, 81710.5 };
static	float	percentage[]
	= { .15, .28,	 .31,	  .36,	   .396 };

double
single_tax( double income )
{
	int	category;

	/*
	** Find the correct income category.  The DBL_MAX added to
	** the end of this list guarantees that the loop will not
	** go too far.
	*/
	for( category = 1;
	    income >= income_limits[ category ];
	    category += 1 )
		;
	category -= 1;

	/*
	** Compute the tax.
	*/
	return base_tax[ category ] + percentage[ category ] *
	    ( income - income_limits[ category ] );
}
