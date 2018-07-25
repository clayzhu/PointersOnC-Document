/*
** Sample declaration for a transaction structure, and prototypes for
** the functions that deal with transactions.
*/
typedef	struct {
	int	a;
} Trans;

Trans *get_trans( void );
void process_trans( Trans * );
void write_data_to_file( void );
