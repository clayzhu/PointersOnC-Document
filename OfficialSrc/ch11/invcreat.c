/*
** Function to create a SUBASSEMBLY inventory record.
*/

#include <stdlib.h>
#include <stdio.h>
#include "inventor.h"

Invrec *
create_subassy_record( int n_parts )
{
	Invrec	*new_rec;

	/*
	** Try to get memory for the Invrec portion.
	*/
	new_rec = malloc( sizeof( Invrec ) );
	if( new_rec != NULL ){
		/*
		** That worked; now get the SUBASSYINFO portion.
		*/
		new_rec->info.subassy =
		    malloc( sizeof( Subassyinfo ) );
		if( new_rec->info.subassy != NULL ){
			/*
			** Get an array big enough for the parts.
			*/
			new_rec->info.subassy->part = malloc(
			    n_parts * sizeof( struct SUBASSYPART ) );
			if( new_rec->info.subassy->part != NULL ){
				/*
				** Got the memory; fill in the fields
				** whose values we know and return.
				*/
				new_rec->type = SUBASSY;
				new_rec->info.subassy->n_parts =
				    n_parts;
				return new_rec;
			}

			/*
			** Out of memory: free what we've got so far.
			*/
			free( new_rec->info.subassy );
		}
		free( new_rec );
	}
	return NULL;
}
