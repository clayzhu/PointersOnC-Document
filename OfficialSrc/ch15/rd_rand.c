/*
** Reads a specific record from a file.  The arguments are the stream
** from which to read, the desired record number, and a pointer to
** the buffer into which the data should be placed.
*/
#include <stdio.h>
#include "studinfo.h"

int
read_random_record( FILE *f, size_t rec_number, StudentInfo *buffer )
{
	fseek( f, (long)rec_number * sizeof( StudentInfo ),
	    SEEK_SET );
	return fread( buffer, sizeof( StudentInfo ), 1, f );
}
