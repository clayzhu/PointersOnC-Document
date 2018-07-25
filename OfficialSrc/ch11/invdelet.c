/*
** Function to discard an inventory record.
*/

#include <stdlib.h>
#include "inventor.h"

void
discard_inventory_record( Invrec *record )
{
	/*
	** Delete the variant parts of the record
	*/
	switch( record->type ){
	case SUBASSY:
		free( record->info.subassy->part );
		free( record->info.subassy );
		break;

	case PART:
		free( record->info.part );
		break;
	}

	/*
	** Delete the main part of the record
	*/
	free( record );
}
